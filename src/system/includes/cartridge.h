#ifndef GOODBOY_CARTRIDGE_H
#define GOODBOY_CARTRIDGE_H

#include "types.h"
#include <array>
#include <string>

class Cartridge {
public:
    byte* rom = new byte[0x800000];
    std::string title;
    std::string license;
    std::string type;
    std::string romSize;
    std::string ramSize;
    std::string destinationCode;
    std::string headerChecksum;
    std::string globalChecksum;
    int romVersionNumber;
    int romBankNumber;
    bool isColor;
    bool isSuper;

    Cartridge(byte* data);

    void parseTitle();
    void parseLicense();
    void parseType();
    void parseRomSize();
    void parseRamSize();
    void parseDestinationCode();
    void calculateHeaderChecksum();
    void calculateGlobalChecksum();
    std::string toString();
};

#endif
