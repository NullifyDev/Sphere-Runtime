#ifndef BYTECODE
#define BYTECODE

#include <stdint.h>
#define packed_t __attribute__((packed))

typedef enum SbeOpCode {
	SIZE,
	ENTRY,
	CHECKSUM,

	WHITELIST,
	BLACKLIST,
} SbeOpCode;

struct packed_t BytecodeHdr {
    char magic[4]; // TARO
    int version;   // Binary version

    int code_size;
};

/**
 * Executable bytecode format.
 */
struct packed_t Bytecode {
    struct packed_t BytecodeHdr header;

    uint8_t *code;
};

// /* Encode and decode instructions */
// int encode_instruction(int op, int operands_count, VMOperand *operands, uint8_t *output);
// int decode_instruction(uint8_t *buffer, VMInstruction *inst);

// int read_bytecode_stream(uint8_t *stream, size_t len, VMInstruction *out_insts,
//                          size_t *out_count);

// int read_bytecode_file(const char *filename, struct Bytecode *bc);


#endif
