#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char** argv) {
	Chunk chunk;
	initChunk(&chunk);

	for (int i = 0; i <= 257; ++i)
		writeConstant(&chunk, i * 10, i + 1);

	writeChunk(&chunk, OP_RETURN, 123);

	disassembleChunk(&chunk, "test chunk");

	freeChunk(&chunk);
	return 0;
}
