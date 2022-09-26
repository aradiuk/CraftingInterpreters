#ifndef clox_lines_h
#define clox_lines_h

#include "memory.h"

typedef struct {
	int count;
	int capacity;
	int* lineNum;
	int* instrucionNum;
} Lines;


void initLines(Lines* lines);
void writeLines(Lines* lines, int instructionNum, int line);
void freeLines(Lines* lines);

int getLine(Lines* line, int instructionNum);

#endif