#include <stdio.h>

typedef struct {
	struct t_list* right;
	struct t_list* left;
	char* str;

} t_list;

void insert(t_list* list, char* str) {
	printf("%s\n", str);
}

int main() {
	t_list* list = NULL;
	insert(list, "hello");	
	

}


