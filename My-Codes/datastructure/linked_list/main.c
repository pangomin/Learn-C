#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node node_t;

void printlist(node_t *head) {
	while (1) {
		printf("%d\n", head->value);
		if (head->next == NULL) {
			break;
		}
		head = head->next;
	}
	return;
}

node_t *create_node(int value, node_t *next_ptr) {
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	new_node->next = next_ptr;

	return new_node;
}

int main(void) {
	node_t *head;
	node_t *next;

	next = create_node(20, NULL);
	head = create_node(10, next);

	printlist(head);

	return 0;
}
