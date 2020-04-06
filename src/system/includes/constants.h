#ifndef GOODBOY_CONSTANTS_H
#define GOODBOY_CONSTANTS_H

// cpu info
const static int CPU_FREQUENCY = 4194304;
const static int ZERO = 0b10000000;
const static int SUB = 0b01000000;
const static int HALF = 0b00100000;
const static int CARRY = 0b00010000;

// memory rom banks
static const int ROM_BANK_NONE = 0;
static const int ROM_BANK_MBC1 = 1;
static const int ROM_BANK_MBC2 = 2;

// gpu modes
static const int M_HBLANK = 0;
static const int M_VBLANK = 1;
static const int M_OAM = 2;
static const int M_VRAM = 3;

// gpu timing
static const int T_HBLANK = 204;
static const int T_VBLANK = 456;
static const int T_OAM = 80;
static const int T_VRAM = 172;

// vblank info
static const int VBLANK_START = 144;
static const int VBLANK_END = 153;
static const int LCDC_PERIOD = (VBLANK_END + 1) * T_VBLANK;

// lcd info
static const int LCD_HEIGHT = 144;
static const int LCD_WIDTH = 160;
static const int BG_HEIGHT = 256;
static const int BG_WIDTH = 256;

// pixel info
static const int PIXEL_WHITE = 0;
static const int PIXEL_LIGHT_GRAY = 1;
static const int PIXEL_DARK_GRAY = 2;
static const int PIXEL_BLACK = 3;

// interrupts
static const int I_VBLANK = 0x01;
static const int I_LCD_STAT = 0x01;
static const int I_TIMER = 0x01;
static const int I_SERIAL = 0x01;
static const int I_JOYPAD = 0x01;

// timer info
static const int TIMER_STATE_COUNTING = 0;
static const int TIMER_STATE_OVERFLOW = 1;
static const int TIMER_STATE_LOADING_TMA = 2;

static const int TAC_CLOCK0 = 4096;
static const int TAC_CLOCK1 = 262144;
static const int TAC_CLOCK2 = 65536;
static const int TAC_CLOCK3 = 16384;

// io registers
static const int IO_JOYPAD = 0xFF00;
static const int IO_SERIAL_TRANSFER_DATA = 0xFF01;
static const int IO_SERIAL_TRANSFER_CONTROL = 0xFF02;
static const int IO_DIVIDER = 0xFF04;
static const int IO_TIMA = 0xFF05;
static const int IO_TMA = 0xFF06;
static const int IO_TAC = 0xFF07;
static const int IO_INTERRUPT_FLAGS = 0xFF0F;
static const int IO_SOUND1_SWEEP = 0xFF10;
static const int IO_SOUND1_LENGTH_WAVE = 0xFF11;
static const int IO_SOUND1_ENVELOPE = 0xFF12;
static const int IO_SOUND1_LOW_FREQUENCY = 0xFF13;
static const int IO_SOUND1_HIGH_FREQUENCY = 0xFF14;
static const int IO_SOUND2_LENGTH_WAVE = 0xFF16;
static const int IO_SOUND2_ENVELOPE = 0xFF17;
static const int IO_SOUND2_LOW_FREQUENCY = 0xFF18;
static const int IO_SOUND2_HIGH_FREQUENCY = 0xFF19;
static const int IO_SOUND3_ENABLE = 0xFF1A;
static const int IO_SOUND3_LENGTH = 0xFF1B;
static const int IO_SOUND3_OUTPUT_LEVEL = 0xFF1C;
static const int IO_SOUND3_FREQUENCY_LOW_DATA = 0xFF1D;
static const int IO_SOUND3_FREQUENCY_HIGH_DATA = 0xFF1E;
static const int IO_SOUND4_LENGTH = 0xFF20;
static const int IO_SOUND4_ENVELOPE = 0xFF21;
static const int IO_SOUND4_COUNTER = 0xFF22;
static const int IO_SOUND4_INITIAL = 0xFF23;
static const int IO_SOUND_CHANNEL_CONTROL = 0xFF24;
static const int IO_SOUND_OUTPUT_CONTROL = 0xFF25;
static const int IO_SOUND_ENABLE = 0xFF26;
static const int IO_LCDC = 0xFF40;
static const int IO_LCD_STATUS = 0xFF41;
static const int IO_SCROLL_Y = 0xFF42;
static const int IO_SCROLL_X = 0xFF43;
static const int IO_LY_COORDINATE = 0xFF44;
static const int IO_LY_COMPARE = 0xFF45;
static const int IO_DIRECT_MEMORY_ACCESS = 0xFF46;
static const int IO_BG_PALETTE_DATA = 0xFF47;
static const int IO_OBJECT_PALETTE0_DATA = 0xFF48;
static const int IO_OBJECT_PALETTE1_DATA = 0xFF49;
static const int IO_WINDOW_Y = 0xFF4A;
static const int IO_WINDOW_X = 0xFF4B;
static const int IO_SPEED_SWITCH = 0xFF4D;
static const int IO_VRAM_BANK = 0xFF4F;
static const int IO_WRAM_BANK = 0xFF70;
static const int IO_INTERRUPT_ENABLE = 0xFFFF;

#endif
