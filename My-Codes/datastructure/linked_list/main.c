#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node node_t;

void printlist(node_t *head) {
	while (1) {
		printf("%d", head->value);
		if (head->next == NULL) {
			break;
		}
		printf("-");
		head = head->next;
	}
	return;
}

node_t *create_node(int value) {
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = value;
	new_node->next = NULL;

	return new_node;
}

node_t *insert_at_head(node_t **head, node_t *insert_node) {
	insert_node->next = *head;
	*head = insert_node;
	return insert_node;
}

node_t *find_node(node_t *head, int value) {
	while(head != NULL) {
		if(head->value == value) return head;
		head = head->next;
	}
	return NULL;
}

node_t *insert_after_value(node_t *node_to_insert, node_t* new_node) {
	new_node->next = node_to_insert->next;
	node_to_insert->next = new_node;
}

int main(void) {
	node_t *head = NULL, *tmp;

	for (int i = 0; i < 21; i++) {
		tmp = create_node(i);
		insert_at_head(&head, tmp);
	}
	tmp = find_node(head, 1);
	insert_after_value(tmp, create_node(999));
	if (tmp != NULL) printf("found: %d\n", tmp->value);

	printlist(head);

	return 0;
}
