#include "includes/cartridge.h"
#include "includes/constants.h"
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

std::string Cartridge::intToHex(word value) {
    char* digits = "0123456789ABCDEF";
    auto hex_len = sizeof(value) << 1;
    std::string rc(hex_len, '0');

    for (size_t i = 0, j = (hex_len-1) * 4 ; i < hex_len; ++i, j -= 4) {
        rc[i] = digits[(value >> j) & 0x0f];
    }

    return rc;
}

void Cartridge::parseTitle() {
    title = "";

    for(int i = 0x0134; i <= 0x0142; i++) {
        title.push_back((char)rom[i]);
    }
}

void Cartridge::parseLicense() {
    word code;
    int count;

    if(rom[0x014B] == 0x33) {
        code = (0x33 << 8) | (((rom[0x0144] & 0x0F) << 4) | (rom[0x0145] & 0x0F));
        count = LICENSEE.count(code);

        if(count == 0) {
            license = "unknown";
        } else {
            license = LICENSEE.at((0x33 << 8) | (((rom[0x0144] & 0x0F) << 4) | (rom[0x0145] & 0x0F)));
        }
    } else {
        code = rom[0x014B];
        count = LICENSEE.count(code);

        if(count == 0) {
            license = "unknown";
        } else {
            license = LICENSEE.at(rom[0x014B]);
        }
    }
}

void Cartridge::parseType() {
    type = CARTRIDGE_TYPE.at(rom[0x0147]);
}

void Cartridge::parseRomSize() {
    romSize = ROM_SIZE.at(rom[0x0148]);
}

void Cartridge::parseRamSize() {
    ramSize = RAM_SIZE.at(rom[0x0149]);
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
        headerChecksum = "Failed. Expected 0x" + intToHex(checksum) + " to be 0x" + intToHex(rom[0x014D]);
    }
}

void Cartridge::calculateGlobalChecksum() {
    word checksum = 0;
    int romChecksum = (rom[0x014E] << 8) | rom[0x014F];

    for(int i = 0; i < 0x800000; i++) {
        if(i != 0x014E && i != 0x014F) {
            checksum = checksum + rom[i];
        }
    }

    if(checksum == romChecksum) {
        globalChecksum = "OK";
    } else {
        globalChecksum = "Failed. Expected 0x" + intToHex(checksum) + " to be 0x" + intToHex(romChecksum);
    }
}

std::string Cartridge::toString() const {
    std::string ret = "Title: " + title + "\n" +
           "CGB Compatible: " + (isColor ? "Yes" : "No") + "\n" +
           "Licensee: " + license + "\n" +
           "SGB Compatible: " + (isSuper ? "Yes" : "No") + "\n" +
           "Cartridge Type: " + type + "\n" +
           "ROM Size: " + romSize + "\n" +
           "RAM Size: " + ramSize + "\n" +
           "Destination Code: " + destinationCode + "\n" +
           "ROM Version: " + std::to_string(romVersionNumber) + "\n" +
           "Header Checksum: " + headerChecksum + "\n" +
           "Global Checksum: " + globalChecksum + "\n";
    return ret;
}
