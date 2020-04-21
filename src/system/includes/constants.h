#ifndef GOODBOY_CONSTANTS_H
#define GOODBOY_CONSTANTS_H

#include <map>
#include <string>

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
static const int ROM_BANK_MBC3 = 3;
static const int ROM_BANK_MBC5 = 4;
static const int ROM_BANK_MBC6 = 5;
static const int ROM_BANK_MBC7 = 6;

// gpu modes
static const int GPU_MODE_HBLANK = 0;
static const int GPU_MODE_VBLANK = 1;
static const int GPU_MODE_OAM = 2;
static const int GPU_MODE_VRAM = 3;

// gpu timing
static const int GPU_TIMING_HBLANK = 204;
static const int GPU_TIMING_VBLANK = 456;
static const int GPU_TIMING_OAM = 80;
static const int GPU_TIMING_VRAM = 172;

// vblank info
static const int VBLANK_START = 144;
static const int VBLANK_END = 153;
static const int LCDC_PERIOD = (VBLANK_END + 1) * GPU_TIMING_VBLANK;

// lcd info
static const int LCD_HEIGHT = 144;
static const int LCD_WIDTH = 160;
static const int BG_HEIGHT = 256;
static const int BG_WIDTH = 256;
static const unsigned long long VBLANK_PERIOD = LCDC_PERIOD * 1000000000LL / CPU_FREQUENCY;

// pixel info
static const int PIXEL_WHITE = 0;
static const int PIXEL_LIGHT_GRAY = 1;
static const int PIXEL_DARK_GRAY = 2;
static const int PIXEL_BLACK = 3;

// interrupts
static const int INTERRUPT_VBLANK = 0x01;
static const int INTERRUPT_LCD_STAT = 0x01;
static const int INTERRUPT_TIMER = 0x01;
static const int INTERRUPT_SERIAL = 0x01;
static const int INTERRUPT_JOYPAD = 0x01;

// timer info
static const int TIMER_STATE_COUNTING = 0;
static const int TIMER_STATE_OVERFLOW = 1;
static const int TIMER_STATE_LOADING_TMA = 2;

// timer frequencies in hertz
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

// cartridge info
static const std::map<word, std::string> LICENSEE = {
    { 0x00, "none" },
    { 0x01, "nintendo" },
    { 0x08, "capcom" },
    { 0x09, "hot-b" },
    { 0x0A, "jaleco" },
    { 0x0B, "coconuts" },
    { 0x0C, "elite systems" },
    { 0x13, "electronic arts" },
    { 0x18, "hudsonsoft" },
    { 0x19, "itc entertainment" },
    { 0x1A, "yanoman" },
    { 0x1D, "clary" },
    { 0x1F, "virgin" },
    { 0x20, "KSS" },
    { 0x24, "pcm complete" },
    { 0x25, "san-x" },
    { 0x28, "kotobuki systems" },
    { 0x29, "seta" },
    { 0x30, "infogrames" },
    { 0x31, "nintendo" },
    { 0x32, "bandai" },
    { 0x34, "konami" },
    { 0x35, "hector" },
    { 0x38, "Capcom" },
    { 0x39, "Banpresto" },
    { 0x3C, "*entertainment i" },
    { 0x3E, "gremlin" },
    { 0x41, "Ubisoft" },
    { 0x42, "Atlus" },
    { 0x44, "Malibu" },
    { 0x46, "angel" },
    { 0x47, "spectrum holoby" },
    { 0x49, "irem" },
    { 0x4A, "virgin" },
    { 0x4D, "malibu" },
    { 0x4F, "u.s. gold" },
    { 0x50, "absolute" },
    { 0x51, "acclaim" },
    { 0x52, "activision" },
    { 0x53, "american sammy" },
    { 0x54, "gametek" },
    { 0x55, "park place" },
    { 0x56, "ljn" },
    { 0x57, "matchbox" },
    { 0x59, "milton bradley" },
    { 0x5A, "mindscape" },
    { 0x5B, "romstar" },
    { 0x5C, "naxat soft" },
    { 0x5D, "tradewest" },
    { 0x60, "titus" },
    { 0x61, "virgin" },
    { 0x67, "ocean" },
    { 0x69, "electronic arts" },
    { 0x6E, "elite systems" },
    { 0x6F, "electro brain" },
    { 0x70, "Infogrammes" },
    { 0x71, "Interplay" },
    { 0x72, "broderbund" },
    { 0x73, "sculptered soft" },
    { 0x75, "the sales curve" },
    { 0x78, "t*hq" },
    { 0x79, "accolade" },
    { 0x7A, "triffix entertainment" },
    { 0x7C, "microprose" },
    { 0x7F, "kemco" },
    { 0x80, "misawa entertainment" },
    { 0x83, "lozc" },
    { 0x86, "tokuma shoten intermedia" },
    { 0x8B, "bullet-proof software" },
    { 0x8C, "vic tokai" },
    { 0x8E, "ape" },
    { 0x8F, "i'max" },
    { 0x91, "chun soft" },
    { 0x92, "video system" },
    { 0x93, "tsuburava" },
    { 0x95, "varie" },
    { 0x96, "yonezawa/s'pal" },
    { 0x97, "kaneko" },
    { 0x99, "arc" },
    { 0x9A, "nihon bussan" },
    { 0x9B, "Tecmo" },
    { 0x9C, "imagineer" },
    { 0x9D, "Banpresto" },
    { 0x9F, "nova" },
    { 0xA1, "Hori electric" },
    { 0xA2, "Bandai" },
    { 0xA4, "Konami" },
    { 0xA6, "kawada" },
    { 0xA7, "takara" },
    { 0xA9, "technos japan" },
    { 0xAA, "broderbund" },
    { 0xAC, "Toei animation" },
    { 0xAD, "toho" },
    { 0xAF, "Namco" },
    { 0xB0, "Acclaim" },
    { 0xB1, "ascii or nexoft" },
    { 0xB2, "Bandai" },
    { 0xB4, "Enix" },
    { 0xB6, "HAL" },
    { 0xB7, "SNK" },
    { 0xB9, "pony canyon" },
    { 0xBA, "*culture brain o" },
    { 0xBB, "Sunsoft" },
    { 0xBD, "Sony imagesoft" },
    { 0xBF, "sammy" },
    { 0xC0, "Taito" },
    { 0xC2, "Kemco" },
    { 0xC3, "Squaresoft" },
    { 0xC4, "tokuma shoten intermedia" },
    { 0xC5, "data east" },
    { 0xC6, "tonkin house" },
    { 0xC8, "koei" },
    { 0xC9, "ufl" },
    { 0xCA, "ultra" },
    { 0xCB, "vap" },
    { 0xCC, "use" },
    { 0xCD, "meldac" },
    { 0xCE, "*pony canyon or" },
    { 0xCF, "angel" },
    { 0xD0, "Taito" },
    { 0xD1, "sofel" },
    { 0xD2, "quest" },
    { 0xD3, "sigma enterprises" },
    { 0xD4, "ask kodansha" },
    { 0xD6, "naxat soft" },
    { 0xD7, "copya systems" },
    { 0xD9, "Banpresto" },
    { 0xDA, "tomy" },
    { 0xDB, "ljn" },
    { 0xDD, "ncs" },
    { 0xDE, "human" },
    { 0xDF, "altron" },
    { 0xE0, "jaleco" },
    { 0xE1, "towachiki" },
    { 0xE2, "uutaka" },
    { 0xE3, "varie" },
    { 0xE5, "epoch" },
    { 0xE7, "athena" },
    { 0xE8, "asmik" },
    { 0xE9, "natsume" },
    { 0xEA, "king records" },
    { 0xEB, "atlus" },
    { 0xEC, "Epic/Sony records" },
    { 0xEE, "igs" },
    { 0xF0, "a wave" },
    { 0xF3, "extreme entertainment" },
    { 0xFF, "ljn" },
    { 0x3300, "none" },
    { 0x3301, "Nintendo R&D1" },
    { 0x3308, "Capcom" },
    { 0x3313, "Electronic Arts" },
    { 0x3318, "Hudson Soft" },
    { 0x3319, "b-ai" },
    { 0x3320, "kss" },
    { 0x3322, "pow" },
    { 0x3324, "PCM Complete" },
    { 0x3325, "san-x" },
    { 0x3328, "Kemco Japan" },
    { 0x3329, "seta" },
    { 0x3330, "Viacom" },
    { 0x3331, "Nintendo" },
    { 0x3332, "Bandai" },
    { 0x3333, "Ocean/Acclaim" },
    { 0x3334, "Konami" },
    { 0x3335, "Hector" },
    { 0x3337, "Taito" },
    { 0x3338, "Hudson" },
    { 0x3339, "Banpresto" },
    { 0x3341, "Ubi Soft" },
    { 0x3342, "Atlus" },
    { 0x3344, "Malibu" },
    { 0x3346, "angel" },
    { 0x3347, "Bullet-Proof" },
    { 0x3349, "irem" },
    { 0x3350, "Absolute" },
    { 0x3351, "Acclaim" },
    { 0x3352, "Activision" },
    { 0x3353, "American sammy" },
    { 0x3354, "Konami" },
    { 0x3355, "Hi tech entertainment" },
    { 0x3356, "LJN" },
    { 0x3357, "Matchbox" },
    { 0x3358, "Mattel" },
    { 0x3359, "Milton Bradley" },
    { 0x3360, "Titus" },
    { 0x3361, "Virgin" },
    { 0x3364, "LucasArts" },
    { 0x3367, "Ocean" },
    { 0x3369, "Electronic Arts" },
    { 0x3370, "Infogrames" },
    { 0x3371, "Interplay" },
    { 0x3372, "Broderbund" },
    { 0x3373, "sculptured" },
    { 0x3375, "sci" },
    { 0x3378, "THQ" },
    { 0x3379, "Accolade" },
    { 0x3380, "misawa" },
    { 0x3383, "lozc" },
    { 0x3386, "tokuma shoten i*" },
    { 0x3387, "tsukuda ori*" },
    { 0x3391, "Chunsoft" },
    { 0x3392, "Video system" },
    { 0x3393, "Ocean/Acclaim" },
    { 0x3395, "Varie" },
    { 0x3396, "Yonezawa/s'pal" },
    { 0x3397, "Kaneko" },
    { 0x3399, "Pack in soft" },
    { 0x33A4, "Konami (Yu-Gi-Oh!)" }
};

static const std::map<byte, std::string> CARTRIDGE_TYPE = {
    { 0x00, "ROM" },
    { 0x01, "MBC1" },
    { 0x02, "MBC1+RAM" },
    { 0x03, "MBC1+RAM+BATTERY" },
    { 0x05, "MBC2" },
    { 0x06, "MBC2+BATTERY" },
    { 0x08, "ROM+RAM" },
    { 0x09, "ROM+RAM+BATTERY" },
    { 0x0B, "MMM01" },
    { 0x0C, "MMM01+RAM" },
    { 0x0D, "MMM01+RAM+BATTERY" },
    { 0x0F, "MBC3+TIMER+BATTERY" },
    { 0x10, "MBC3+TIMER+RAM+BATTERY" },
    { 0x11, "MBC3" },
    { 0x12, "MBC3+RAM" },
    { 0x13, "MBC3+RAM+BATTERY" },
    { 0x15, "MBC4" },
    { 0x16, "MBC4+RAM" },
    { 0x17, "MBC4+RAM+BATTERY" },
    { 0x19, "MBC5" },
    { 0x1A, "MBC5+RAM" },
    { 0x1B, "MBC5+RAM+BATTERY" },
    { 0x1C, "MBC5+RUMBLE" },
    { 0x1D, "MBC5+RUMBLE+RAM" },
    { 0x1E, "MBC5+RUMBLE+RAM+BATTERY" },
    { 0x20, "MBC6" },
    { 0x22, "MBC7+SENSOR+RUMBLE+RAM+BATTERY" },
    { 0xFC, "POCKET CAMERA" },
    { 0xFD, "Bandai TAMA5" },
    { 0xFE, "HuC3" },
    { 0xFF, "HuC1+RAM+BATTERY" }
};

static const std::map<byte, std::string> ROM_SIZE = {
    { 0x00, "32KByte -> 0 banks" },
    { 0x01, "64KByte -> 4 banks" },
    { 0x02, "128KByte -> 8 banks" },
    { 0x03, "256KByte -> 16 banks" },
    { 0x04, "512KByte -> 32 banks" },
    { 0x05, "1MByte -> 64 banks" },
    { 0x06, "2MByte -> 128 banks" },
    { 0x07, "4MByte -> 256 banks" },
    { 0x08, "8MByte -> 512 banks" },
    { 0x52, "1.1MByte -> 72 banks" },
    { 0x53, "1.2MByte -> 80 banks" },
    { 0x54, "1.5MByte -> 96 banks" }
};

static const std::map<byte, std::string> RAM_SIZE = {
    { 0x00, "0k" },
    { 0x01, "2k" },
    { 0x02, "8k" },
    { 0x03, "32k" }
};

#endif
