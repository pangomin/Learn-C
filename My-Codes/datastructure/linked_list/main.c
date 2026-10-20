#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

typedef struct node node_t;

void printlist(node_t *head) {
	for (head = head;; head = head->next) {
		printf("%d\n", head->value);
		if (head->next == NULL) {
			break;
		}
	}
	return;
}

int main(void) {
	node_t n0, n1, n2;
	node_t *head;

	n0.value = 10;
	n1.value = 20;
	n2.value = 30;

	head = &n0;

	n0.next = &n1;
	n1.next = &n2;
	n2.next = NULL;

	printlist(&n0);

	return 0;
}
