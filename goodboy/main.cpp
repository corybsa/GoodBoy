// Dear ImGui: standalone example application for DirectX 11
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui/imgui.h"
#include "imgui/imfilebrowser.h"
#include "imgui/backends/imgui_impl_win32.h"
#include "imgui/backends/imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <filesystem>

#include "system/includes/gameboy.h"
#include "test/system/includes/cpu_test.h"
#include "test/system/includes/memory_test.h"
#include "test/system/includes/instructions.h"

// Data
static ID3D11Device* g_pd3dDevice = NULL;
static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

byte* openFile(std::string name);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("Goodboy"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Goodboy"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.Fonts->AddFontFromFileTTF("resources/fonts/consolas.ttf", 14);

    io.KeysDown[0] = false;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Load test rom
    ImGui::FileBrowser fileDialog;
    auto* gb = new GameBoy();
    byte* rom = new byte[0x800000];
    std::thread gameThread;
    std::thread testThread;

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImVec2 cursor;

        // LCD
        {
            ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(140, 166), ImGuiCond_Once);

            ImGui::Begin("LCD");

            if (ImGui::BeginPopupContextItem("test context")) {
                if (ImGui::Selectable("Open ROM...")) {
                    fileDialog.SetTitle("Open ROM");
                    fileDialog.SetTypeFilters({ ".gb" });

                    fileDialog.Open();
                }

                ImGui::EndPopup();
            }

            ImGui::End();
        }

        fileDialog.Display();

        if (fileDialog.HasSelected()) {
            std::string file = fileDialog.GetSelected().string();
            std::cout << file << std::endl;
            fileDialog.ClearSelected();
            byte* rom = openFile(file);

            if (rom != nullptr) {
                gb->loadRom(rom);
            }
            else {
                std::cout << "Could not open file " << file << std::endl;
            }
        }

        // CPU Info
        {
            ImGui::SetNextWindowPos(ImVec2(10, 186), ImGuiCond_Once);
            //ImGui::SetNextWindowSize(ImVec2(250, 490), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(250, 510), ImGuiCond_Once);

            ImGui::Begin("CPU");

            ImGui::Text("AF: 0x%04X     LCDC: 0x%02X", gb->cpu->registers.AF, gb->memory->readIO(IO_LCDC));
            ImGui::Text("BC: 0x%04X     STAT: 0x%02X", gb->cpu->registers.BC, gb->memory->readIO(IO_LCD_STATUS));
            ImGui::Text("DE: 0x%04X     LY:   0x%02X", gb->cpu->registers.DE, gb->memory->readIO(IO_LY_COORDINATE));
            ImGui::Text("HL: 0x%04X     IE:   0x%02X", gb->cpu->registers.HL, gb->memory->readIO(IO_INTERRUPT_ENABLE));
            ImGui::Text("PC: 0x%04X     IF:   0x%02X", gb->cpu->registers.PC, gb->memory->readIO(IO_INTERRUPT_FLAGS));
            ImGui::Text("SP: 0x%04X     IME:  %s", gb->cpu->registers.SP, gb->cpu->ime ? "on" : "off");

            word flags = gb->cpu->registers.AF;
            static bool zero = (flags & ZERO) == ZERO;
            static bool sub = (flags & SUB) == SUB;
            static bool half = (flags & HALF) == HALF;
            static bool carry = (flags & CARRY) == CARRY;

            if (ImGui::Checkbox("Z", &zero)) zero = !zero;
            ImGui::SameLine();

            if (ImGui::Checkbox("N", &sub)) sub = !sub;
            ImGui::SameLine();

            if (ImGui::Checkbox("N", &half)) half = !half;
            ImGui::SameLine();

            if (ImGui::Checkbox("N", &carry)) carry = !carry;

            cursor = ImGui::GetCursorPos();
            ImGui::SetCursorPosY(cursor.y + 10);
            ImGui::Separator();

            // Breakpoints
            cursor = ImGui::GetCursorPos();
            ImGui::SetCursorPosY(cursor.y + 10);

            ImGui::BeginChild("Breakpoints", ImVec2(240, 200));

                static int breakpoint;
                ImGui::Text("Breakpoint");
                if (ImGui::InputInt("", &breakpoint, 1, 100, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_AlwaysOverwrite)) {
                    gb->addBreakpoint((word)breakpoint);
                }

                if (ImGui::BeginTable("Breakpoints", 2, ImGuiTableFlags_SizingFixedSame)) {
                    for (auto it : gb->breakpoints) {
                        ImGui::TableNextColumn();
                        ImGui::Text("0x%04X", it);
                        ImGui::TableNextColumn();

                        // TODO: only works for the first item in the table
                        if (ImGui::Button("X")) {
                            gb->removeBreakpoint(it);
                        }
                    }

                    ImGui::EndTable();
                }

                if (gb->breakpoints.size() == 0) {
                    ImGui::Text("No breakpoints");
                }

            ImGui::EndChild();

            cursor = ImGui::GetCursorPos();
            ImGui::SetCursorPosY(cursor.y + 10);
            ImGui::Separator();

            // Buttons
            cursor = ImGui::GetCursorPos();
            ImGui::SetCursorPosY(cursor.y + 10);
            ImGui::Text("Controls");

            if (ImGui::Button("Run (F9)") || ImGui::IsKeyPressed(0, false)) {
                if (gameThread.joinable()) {
                    gb->pause();
                    gameThread.join();
                }

                gameThread = std::thread([gb]() -> void {
                    gb->run();
                });
            }

            ImGui::SameLine();
            if (ImGui::Button("Tick")) {
                gb->pause();
                gb->tick();
            }

            if (ImGui::Button("Pause")) {
                gb->pause();

                if (gameThread.joinable()) {
                    gameThread.join();
                }
            }

            ImGui::SameLine();
            if (ImGui::Button("Reset")) {
                gb->pause();
                gb->reset();

                if (gameThread.joinable()) {
                    gameThread.join();
                }
            }

            ImGui::End();
        }

        // GPU Info
        {
            ImGui::SetNextWindowPos(ImVec2(160, 10), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(170, 166), ImGuiCond_Once);

            ImGui::Begin("GPU");

            ImGui::Text("Mode: %d", gb->gpu->mode);
            ImGui::Text("Frame time: %2.2f ms", gb->gpu->frameTime);
            ImGui::Text("Framerate: %2.2f", gb->gpu->frameRate);
            ImGui::Text("Frame count: %u", gb->gpu->frameCount);

            ImGui::End();
        }

        // ROM info
        {
            ImGui::SetNextWindowPos(ImVec2(270, 186), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(420, 200), ImGuiCond_Once);

            ImGui::Begin("Rom info");

            ImGui::Text(gb->cartridge->toString().c_str());

            ImGui::End();
        }

        // Memory info
        {
            ImGui::SetNextWindowPos(ImVec2(270, 396), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(350, 220), ImGuiCond_Once);

            static int memWatchAddress;

            ImGui::Begin("Memory");

            ImGui::Text("Watch address");
            if (ImGui::InputInt("", &memWatchAddress, 1, 100, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue)) {
                gb->addMemoryWatch((word)memWatchAddress);
            }

            if (ImGui::BeginTable("Memory Info", 3)) {
                for (auto it : gb->memoryWatchList) {
                    ImGui::TableNextColumn();
                    ImGui::Text("0x%x", it);
                    ImGui::TableNextColumn();
                    ImGui::Text("0x%x", gb->memory->readByte(it));
                    ImGui::TableNextColumn();

                    if (ImGui::Button("X")) {
                        gb->removeMemoryWatch(it);
                    }
                }

                ImGui::EndTable();
            }

            ImGui::End();
        }

        {
            ImGui::SetNextWindowPos(ImVec2(895, 10), ImGuiCond_Once);
            ImGui::SetNextWindowSize(ImVec2(360, 740), ImGuiCond_Once);

            static std::string testOutput;

            ImGui::Begin("Tests");

            if (ImGui::Button("Run tests")) {
                gb->pause();
                gb->reset();

                if (testThread.joinable()) {
                    gb->pause();
                    testThread.join();
                }

                testThread = std::thread([gb]() -> void {
                    testOutput = "";
                    CPUTest cpuTest(gb);
                    cpuTest.run(&testOutput);

                    MemoryTest memoryTest(gb);
                    memoryTest.run(&testOutput);

                    InstructionsTest instrTest(gb);
                    testOutput += "\nInstructions Tests running...\n";
                    instrTest.run(&testOutput);

                    testOutput += "\nTests have completed!";
                });
            }

            ImGui::Text(testOutput.c_str());

            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0); // Present with vsync
    }

    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    gb->quit();
    
    if (gameThread.joinable()) {
        gameThread.join();
        gameThread.detach();
    }

    delete[] rom;
    delete gb;

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    // Setup swap chain
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;
    //createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
            CreateRenderTarget();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

byte* openFile(std::string name) {
    std::ifstream file(name, std::ios_base::binary);

    if (!file.is_open()) {
        printf("file could not be opened!\n");
        return nullptr;
    }

    if (file.bad()) {
        printf("error reading file!\n");
        return nullptr;
    }

    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    char* ret = new char[length];
    file.seekg(0, std::ios::beg);
    file.read(ret, length);
    file.close();

    byte* rom = new byte[0x800000];

    for (int i = 0; i < length; i++) {
        rom[i] = (byte)ret[i];
    }

    delete[] ret;
    return rom;
}
