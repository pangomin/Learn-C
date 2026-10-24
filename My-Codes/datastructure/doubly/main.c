#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
	struct node *prev;
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
	new_node->prev = NULL;

	return new_node;
}

node_t *insert_at_head(node_t **head, node_t *insert_node) {
	insert_node->next = *head;
	if (*head != NULL) {
		(*head)->prev = insert_node;
	}
	*head = insert_node;
	insert_node->prev = NULL;
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
	if (new_node->next != NULL) {
		new_node->next->prev = new_node;
	}
	new_node->prev = node_to_insert;
	node_to_insert->next = new_node;
}

void remove_node(node_t **head, node_t *node_to_remove) {
	if (*head == node_to_remove) {
		*head = node_to_remove->next;
		if (head != NULL) {
			(*head)->prev = NULL;
		}
	} else {
		node_to_remove->prev->next = node_to_remove->next;
		if (node_to_remove->next != NULL) {
			node_to_remove->next->prev = node_to_remove->prev;
		}
	}
}

int main(void) {
	node_t *head = NULL, *tmp;

	for (int i = 0; i < 21; i++) {
		tmp = create_node(i);
		insert_at_head(&head, tmp);
	}
	tmp = find_node(head, 10);
	insert_after_value(tmp, create_node(999));
	if (tmp != NULL) printf("found: %d\n", tmp->value);
	remove_node(&head, tmp);
	printlist(head);
	putc('\n', stdout);
	remove_node(&head, head);

	printlist(head);

	return 0;
}
