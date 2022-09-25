#include <stdlib.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, site_t newSize) {
	if (!newSize) {
		free(pointer);
		return NULL;
	}

	void* result = realloc(pointer, newSize);
	if (result == NULL) {
		printf("Realloc failed. OOM\n");
		exit(1);
	}

	return result;
}
