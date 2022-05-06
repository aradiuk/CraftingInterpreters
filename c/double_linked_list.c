#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	new_elem->prev = NULL;
	new_elem->str = (char*)malloc(sizeof(char) * strlen(string));
	strcpy(new_elem->str, string);
	return new_elem;
}

void insert(t_list** list, char* string) {
	t_list* new_elem = (t_list*)malloc(sizeof(t_list));
	new_elem->next = NULL;
	new_elem->str = (char*)malloc(sizeof(char) * strlen(string));
	strcpy(new_elem->str, string);

	t_list* last = return_last(*list);
	last->next = new_elem;
	new_elem->prev = last;
}

t_list* find(t_list* list, char* string) {
	t_list* ptr = list;
	while (ptr != NULL) {
		if (!strcmp(ptr->str, string)) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void delete_list_element(t_list** list, char* str) {
	t_list* ptr = *list;
	t_list* prev = NULL;
	t_list* next = NULL;
	while (*list != NULL) {
		next = (*list)->next;
		if (!strcmp((*list)->str, str)) {
			if (next != NULL) {
				next->prev = prev;
			}
			prev->next = next;
			free((*list)->str);
			free(*list);
		}
		prev = *list;
		*list = next;
	}
	*list = ptr;
}

void print_list(t_list* list) {
	t_list* tmp = list;
	while (1) {
		if (tmp->next != NULL) {
			printf("%s - %p -> ", tmp->str, tmp->str);
		} else {
			printf("%s - %p |\n ", tmp->str, tmp->str);
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

	t_list* find_res = find(list, "world");
	if (find_res != NULL) {
		printf("%s\n", find_res->str);
	} else {
		printf("list element with not found.\n");
	}

	delete_list_element(&list, "hello");
	delete_list_element(&list, "bye");
	print_list(list);	
}


