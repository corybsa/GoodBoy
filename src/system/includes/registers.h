#ifndef GOODBOY_REGISTERS_H
#define GOODBOY_REGISTERS_H

#include "types.h"

class Registers {
public:
    struct {
		union {
			struct {
				byte F;
				byte A;
			};
			word AF;
		};
	};

    struct {
		union {
			struct {
				byte C;
				byte B;
			};
			word BC;
		};
	};

    struct {
		union {
			struct {
				byte E;
				byte D;
			};
			word DE;
		};
	};

    struct {
		union {
			struct {
				byte L;
				byte H;
			};
			word HL;
		};
	};

    word SP;
    word PC;

    Registers() = default;

    byte get8Bit(int reg);
    void set8Bit(int reg, byte value);

    word get16Bit(int reg, bool useAF);
    void set16Bit(int reg, word value, bool useAF);
};

#endif
