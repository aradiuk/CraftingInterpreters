#include <stdio.h>

#include "debug.h"
#include "value.h"

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

static int longConstantInstruction(const char* name, Chunk* chunk, int offset) {
    int constant_1 = chunk->code[offset + 1];
    int constant_2 = chunk->code[offset + 2] << 8;
    int constant_3 = chunk->code[offset + 3] << 16;
    int constant = constant_1 | constant_2 | constant_3;
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 4;
}

static int simpleInstruction(const char* name, int offset) {
    printf("%s\n", name);
    return offset + 1;
}

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->count;)  {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);

    int currentLine = getLine(&chunk->lines, offset);
    int previousLine = getLine(&chunk->lines, offset - 1);

    if (offset > 0 && currentLine == previousLine) {
        printf("   | ");
    } else {
        printf("%4d ", currentLine);
    }

    uint8_t instruction = chunk->code[offset];
    switch (instruction)     {
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        break;
        case OP_CONSTANT_LONG:
            return longConstantInstruction("OP_CONSTANT_LONG", chunk, offset);
        break;
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        break;
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}