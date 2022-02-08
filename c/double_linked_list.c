#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
	struct s_list* next;
	struct s_list* prev;
	char* str;

} t_list;

t_list* return_last(t_list* list) {
	t_list* ptr = list;
	while (ptr != NULL) {
		if (ptr->next == NULL) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return ptr;
}

t_list* create_list(char* string) {
	t_list* new_elem = (t_list*)malloc(sizeof(t_list));
	new_elem->next = NULL;
	new_elem->str = (char*)malloc(sizeof(string));
	new_elem->str = string;
	return new_elem;
}

void insert(t_list** list, char* string) {
	t_list* new_elem = (t_list*)malloc(sizeof(t_list));
	new_elem->next = NULL;
	new_elem->str = (char*)malloc(sizeof(string));
	new_elem->str = string;
	
	t_list* last = return_last(*list);
	last->next = new_elem;
}

void print_list(t_list* list) {
	t_list* tmp = list;
	while (1) {
		if (tmp->next != NULL) {
			printf("%s -> ", tmp->str);
		} else {
			printf("%s |\n ", tmp->str);
			return;
		}
		tmp = tmp->next;
	}
}

int main() {
	t_list* list = create_list("first");
	insert(&list, "hello");	
	insert(&list, "world");	
	insert(&list, "bye");	

	print_list(list);	
}


