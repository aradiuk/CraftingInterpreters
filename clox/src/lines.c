#include "lines.h"

void initLines(Lines* lines) {
	lines->count = 0;
    lines->capacity = 0;
    lines->lineNum = NULL;
    lines->instrucionNum = NULL;
}

void writeLines(Lines* lines, int instructionNum, int line) {
	if (lines->count == 0 || lines->lineNum[lines->count] != line) {
        if (lines->count == lines->capacity) {
            int oldCapacity = lines->capacity;
            lines->capacity = GROW_CAPACITY(oldCapacity);
            lines->lineNum = GROW_ARRAY(int, lines->lineNum, oldCapacity, lines->capacity);
            lines->instrucionNum = GROW_ARRAY(int, lines->instrucionNum, oldCapacity, lines->capacity);
        }

        lines->lineNum[lines->count] = line;
	    lines->instrucionNum[lines->count] = instructionNum;
	    ++lines->count;
	}
}

void freeLines(Lines* lines) {
	FREE_ARRAY(int, lines->lineNum, lines->capacity);
    FREE_ARRAY(int, lines->instrucionNum, lines->capacity);
	initLines(lines);
}

int getLine(Lines* lines, int instructionNum) {
    for (int offset = 0; offset < lines->count; ++offset) {
        if (instructionNum < lines->instrucionNum[offset]) {
            return lines->lineNum[offset - 1];
        }
    }
    return lines->lineNum[lines->count - 1];
}