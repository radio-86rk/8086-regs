#include <stdio.h>

typedef	__uint8_t	byte;
typedef	__uint16_t	word;


union reg16 {
	word	Value;
	struct {
		byte	Low;
		byte	High;
	};
};

struct regs {
	union {
		word	AX;
		struct {
			byte	AL;
			byte	AH;
		};
	};

	union {
		word	BX;
		struct {
			byte	BL;
			byte	BH;
		};
	};

	union {
		word	CX;
		struct {
			byte	CL;
			byte	CH;
		};
	};

	union {
		word	DX;
		struct {
			byte	DL;
			byte	DH;
		};
	};

};

int main ( int, char** ) {
	union reg16 AX;
	AX.Value = 0x1234;
	printf ("ax=%04x\nah=%02x\nal=%02x\n", AX.Value, AX.High, AX.Low);
	AX.High = 0x55;
	AX.Low = 0xAA;
	printf ("ax=%04x\nah=%02x\nal=%02x\n", AX.Value, AX.High, AX.Low);


	struct regs Regs;
	Regs.AX = 0x1234;
	printf ("ax=%04x\nah=%02x\nal=%02x\n", Regs.AX, Regs.AH, Regs.AL);
	Regs.AH = 0x55;
	Regs.AL = 0xAA;
	printf ("ax=%04x\nah=%02x\nal=%02x\n", Regs.AX, Regs.AH, Regs.AL);
}
