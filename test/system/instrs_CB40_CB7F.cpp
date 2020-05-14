#include "includes/instrs_CB40_CB7F.h"

Instrs_CB40_CB7F::Instrs_CB40_CB7F(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCB40(); });
    Test::addTest([this]() -> void { test_0xCB41(); });
    Test::addTest([this]() -> void { test_0xCB42(); });
    Test::addTest([this]() -> void { test_0xCB43(); });
    Test::addTest([this]() -> void { test_0xCB44(); });
    Test::addTest([this]() -> void { test_0xCB45(); });
    Test::addTest([this]() -> void { test_0xCB46(); });
    Test::addTest([this]() -> void { test_0xCB47(); });
    Test::addTest([this]() -> void { test_0xCB48(); });
    Test::addTest([this]() -> void { test_0xCB49(); });
    Test::addTest([this]() -> void { test_0xCB4A(); });
    Test::addTest([this]() -> void { test_0xCB4B(); });
    Test::addTest([this]() -> void { test_0xCB4C(); });
    Test::addTest([this]() -> void { test_0xCB4D(); });
    Test::addTest([this]() -> void { test_0xCB4E(); });
    Test::addTest([this]() -> void { test_0xCB4F(); });

    Test::addTest([this]() -> void { test_0xCB50(); });
    Test::addTest([this]() -> void { test_0xCB51(); });
    Test::addTest([this]() -> void { test_0xCB52(); });
    Test::addTest([this]() -> void { test_0xCB53(); });
    Test::addTest([this]() -> void { test_0xCB54(); });
    Test::addTest([this]() -> void { test_0xCB55(); });
    Test::addTest([this]() -> void { test_0xCB56(); });
    Test::addTest([this]() -> void { test_0xCB57(); });
    Test::addTest([this]() -> void { test_0xCB58(); });
    Test::addTest([this]() -> void { test_0xCB59(); });
    Test::addTest([this]() -> void { test_0xCB5A(); });
    Test::addTest([this]() -> void { test_0xCB5B(); });
    Test::addTest([this]() -> void { test_0xCB5C(); });
    Test::addTest([this]() -> void { test_0xCB5D(); });
    Test::addTest([this]() -> void { test_0xCB5E(); });
    Test::addTest([this]() -> void { test_0xCB5F(); });

    Test::addTest([this]() -> void { test_0xCB60(); });
    Test::addTest([this]() -> void { test_0xCB61(); });
    Test::addTest([this]() -> void { test_0xCB62(); });
    Test::addTest([this]() -> void { test_0xCB63(); });
    Test::addTest([this]() -> void { test_0xCB64(); });
    Test::addTest([this]() -> void { test_0xCB65(); });
    Test::addTest([this]() -> void { test_0xCB66(); });
    Test::addTest([this]() -> void { test_0xCB67(); });
    Test::addTest([this]() -> void { test_0xCB68(); });
    Test::addTest([this]() -> void { test_0xCB69(); });
    Test::addTest([this]() -> void { test_0xCB6A(); });
    Test::addTest([this]() -> void { test_0xCB6B(); });
    Test::addTest([this]() -> void { test_0xCB6C(); });
    Test::addTest([this]() -> void { test_0xCB6D(); });
    Test::addTest([this]() -> void { test_0xCB6E(); });
    Test::addTest([this]() -> void { test_0xCB6F(); });

    Test::addTest([this]() -> void { test_0xCB70(); });
    Test::addTest([this]() -> void { test_0xCB71(); });
    Test::addTest([this]() -> void { test_0xCB72(); });
    Test::addTest([this]() -> void { test_0xCB73(); });
    Test::addTest([this]() -> void { test_0xCB74(); });
    Test::addTest([this]() -> void { test_0xCB75(); });
    Test::addTest([this]() -> void { test_0xCB76(); });
    Test::addTest([this]() -> void { test_0xCB77(); });
    Test::addTest([this]() -> void { test_0xCB78(); });
    Test::addTest([this]() -> void { test_0xCB79(); });
    Test::addTest([this]() -> void { test_0xCB7A(); });
    Test::addTest([this]() -> void { test_0xCB7B(); });
    Test::addTest([this]() -> void { test_0xCB7C(); });
    Test::addTest([this]() -> void { test_0xCB7D(); });
    Test::addTest([this]() -> void { test_0xCB7E(); });
    Test::addTest([this]() -> void { test_0xCB7F(); });
}

void Instrs_CB40_CB7F::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_CB40_CB7F::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CB40_CB7F::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CB40_CB7F::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCB40_CB4F

void Instrs_CB40_CB7F::test_0xCB40() {}
void Instrs_CB40_CB7F::test_0xCB41() {}
void Instrs_CB40_CB7F::test_0xCB42() {}
void Instrs_CB40_CB7F::test_0xCB43() {}
void Instrs_CB40_CB7F::test_0xCB44() {}
void Instrs_CB40_CB7F::test_0xCB45() {}
void Instrs_CB40_CB7F::test_0xCB46() {}
void Instrs_CB40_CB7F::test_0xCB47() {}
void Instrs_CB40_CB7F::test_0xCB48() {}
void Instrs_CB40_CB7F::test_0xCB49() {}
void Instrs_CB40_CB7F::test_0xCB4A() {}
void Instrs_CB40_CB7F::test_0xCB4B() {}
void Instrs_CB40_CB7F::test_0xCB4C() {}
void Instrs_CB40_CB7F::test_0xCB4D() {}
void Instrs_CB40_CB7F::test_0xCB4E() {}
void Instrs_CB40_CB7F::test_0xCB4F() {}

#pragma endregion

#pragma region rCB50_CB5F

void Instrs_CB40_CB7F::test_0xCB50() {}
void Instrs_CB40_CB7F::test_0xCB51() {}
void Instrs_CB40_CB7F::test_0xCB52() {}
void Instrs_CB40_CB7F::test_0xCB53() {}
void Instrs_CB40_CB7F::test_0xCB54() {}
void Instrs_CB40_CB7F::test_0xCB55() {}
void Instrs_CB40_CB7F::test_0xCB56() {}
void Instrs_CB40_CB7F::test_0xCB57() {}
void Instrs_CB40_CB7F::test_0xCB58() {}
void Instrs_CB40_CB7F::test_0xCB59() {}
void Instrs_CB40_CB7F::test_0xCB5A() {}
void Instrs_CB40_CB7F::test_0xCB5B() {}
void Instrs_CB40_CB7F::test_0xCB5C() {}
void Instrs_CB40_CB7F::test_0xCB5D() {}
void Instrs_CB40_CB7F::test_0xCB5E() {}
void Instrs_CB40_CB7F::test_0xCB5F() {}

#pragma endregion

#pragma region rCB60_CB6F

void Instrs_CB40_CB7F::test_0xCB60() {}
void Instrs_CB40_CB7F::test_0xCB61() {}
void Instrs_CB40_CB7F::test_0xCB62() {}
void Instrs_CB40_CB7F::test_0xCB63() {}
void Instrs_CB40_CB7F::test_0xCB64() {}
void Instrs_CB40_CB7F::test_0xCB65() {}
void Instrs_CB40_CB7F::test_0xCB66() {}
void Instrs_CB40_CB7F::test_0xCB67() {}
void Instrs_CB40_CB7F::test_0xCB68() {}
void Instrs_CB40_CB7F::test_0xCB69() {}
void Instrs_CB40_CB7F::test_0xCB6A() {}
void Instrs_CB40_CB7F::test_0xCB6B() {}
void Instrs_CB40_CB7F::test_0xCB6C() {}
void Instrs_CB40_CB7F::test_0xCB6D() {}
void Instrs_CB40_CB7F::test_0xCB6E() {}
void Instrs_CB40_CB7F::test_0xCB6F() {}

#pragma endregion

#pragma region rCB70_CB7F

void Instrs_CB40_CB7F::test_0xCB70() {}
void Instrs_CB40_CB7F::test_0xCB71() {}
void Instrs_CB40_CB7F::test_0xCB72() {}
void Instrs_CB40_CB7F::test_0xCB73() {}
void Instrs_CB40_CB7F::test_0xCB74() {}
void Instrs_CB40_CB7F::test_0xCB75() {}
void Instrs_CB40_CB7F::test_0xCB76() {}
void Instrs_CB40_CB7F::test_0xCB77() {}
void Instrs_CB40_CB7F::test_0xCB78() {}
void Instrs_CB40_CB7F::test_0xCB79() {}
void Instrs_CB40_CB7F::test_0xCB7A() {}
void Instrs_CB40_CB7F::test_0xCB7B() {}
void Instrs_CB40_CB7F::test_0xCB7C() {}
void Instrs_CB40_CB7F::test_0xCB7D() {}
void Instrs_CB40_CB7F::test_0xCB7E() {}
void Instrs_CB40_CB7F::test_0xCB7F() {}

#pragma endregion
