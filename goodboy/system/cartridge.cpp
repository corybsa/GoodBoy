#include "includes/cartridge.h"
#include "includes/globals.h"
#include <algorithm>

Cartridge::~Cartridge() {
    delete[] rom;
    rom = nullptr;
}

void Cartridge::changeCartridge(byte* data) {
    std::copy(data, data + 0x800000, rom);
    isColor = rom[0x143] == 0x80;
    isSuper = rom[0x146] == 0x03;
    romVersionNumber = rom[0x14C];
    romBankNumber = 0;

    parseTitle();
    parseLicense();
    parseType();
    parseRomSize();
    parseRamSize();
    parseDestinationCode();
    calculateHeaderChecksum();
    calculateGlobalChecksum();
}

void Cartridge::parseTitle() {
    title = "";

    for(int i = 0x0134; i <= 0x0142; i++) {
        title.push_back((char)rom[i] == '\0' ? ' ' : (char)rom[i]);
    }

    if (title.compare("               ") == 0) {
        title = "UNKNOWN";
    }
}

void Cartridge::parseLicense() {
    word code;
    int count;

    if(rom[0x014B] == 0x33) {
        code = (0x33 << 8) | (((rom[0x0144] & 0x0F) << 4) | (rom[0x0145] & 0x0F));
        count = LICENSEE.count(code);

        if(count == 0) {
            license = "UNKNOWN";
        } else {
            try {
                license = LICENSEE.at((0x33 << 8) | (((rom[0x0144] & 0x0F) << 4) | (rom[0x0145] & 0x0F)));
            }
            catch (...) {
                license = "UNKNOWN";
            }
        }
    } else {
        code = rom[0x014B];
        count = LICENSEE.count(code);

        if(count == 0) {
            license = "UNKNOWN";
        } else {
            try {
                license = LICENSEE.at(rom[0x014B]);
            }
            catch (...) {
                license = "UNKNOWN";
            }
        }
    }
}

void Cartridge::parseType() {
    try {
        type = CARTRIDGE_TYPE.at(rom[0x0147]);
    }
    catch (...) {
        type = "UNKNOWN";
    }
}

void Cartridge::parseRomSize() {
    try {
        romSize = ROM_SIZE.at(rom[0x0148]);
    }
    catch (...) {
        romSize = "UNKNOWN";
    }
}

void Cartridge::parseRamSize() {
    try {
        ramSize = RAM_SIZE.at(rom[0x0149]);
    }
    catch (...) {
        ramSize = "UNKNOWN";
    }
}

void Cartridge::parseDestinationCode() {
    if(rom[0x014A] == 0x00) {
        destinationCode = "Japanese";
    } else {
        destinationCode = "Non-Japanese";
    }
}

void Cartridge::calculateHeaderChecksum() {
    // x=0:FOR i=0134h TO 014Ch:x=x-MEM[i]-1:NEXT
    byte checksum = 0; // x=0

    for(int i = 0x0134; i <= 0x014C; i++) { // FOR i=0134h TO 014Ch
        checksum = (checksum - rom[i] - 1); // x=x-MEM[i]-1
    }

    if(checksum == rom[0x014D]) {
        headerChecksum = "OK";
    } else {
        headerChecksum = "Failed. Expected 0x" + toHex(checksum) + " to be 0x" + toHex(rom[0x014D]);
    }
}

void Cartridge::calculateGlobalChecksum() {
    word checksum = 0;
    word romChecksum = (rom[0x014E] << 8) | rom[0x014F];

    for(int i = 0; i < 0x800000; i++) {
        if(i != 0x014E && i != 0x014F) {
            checksum = checksum + rom[i];
        }
    }

    if(checksum == romChecksum) {
        globalChecksum = "OK";
    } else {
        globalChecksum = "Failed. Expected 0x" + toHex(checksum) + " to be 0x" + toHex(romChecksum);
    }
}

std::string Cartridge::toString() const {
    std::stringstream ss;
    ss << "Title: " << title << std::endl;
    ss << "CGB Compatible: " << (isColor ? "Yes" : "No") << std::endl;
    ss << "Licensee: " << license << std::endl;
    ss << "SGB Compatible: " << (isSuper ? "Yes" : "No") << std::endl;
    ss << "Cartridge Type: " << type << std::endl;
    ss << "ROM Size: " << romSize << std::endl;
    ss << "RAM Size: " << ramSize << std::endl;
    ss << "Destination Code: " << destinationCode << std::endl;
    ss << "ROM Version: " << romVersionNumber << std::endl;
    ss << "Header Checksum: " << headerChecksum << std::endl;
    ss << "Global Checksum: " << globalChecksum << std::endl;

    return ss.str();
}
