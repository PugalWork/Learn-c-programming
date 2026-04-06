/* Implementation of singly linked list*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
      int data;
      struct Node *next;
};

int main() {
    struct Node *head, *newnode, *temp;
    int choice = 1;
    int count = 0;
    /* construct the linked list*/
    head = NULL;
    while (choice) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
	if (!newnode) {
	    printf("Memory allocation failed!");
	    exit(1);
	}
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
        newnode->next = 0;
	
	if (head == NULL) {
	    head = temp = newnode;
	}
	else {
	  temp->next = newnode;
	  temp = newnode;
	}
	count++;
	printf("Enter the choice 1 or 0: ");
	scanf("%d", &choice);
    
    }

    /* print the list*/
    printf("\nPrinting the list!\n");
    temp = head;
    while (temp) {
        printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
    printf("Number of elements: %d\n", count);

    /*free the list*/
    temp = head;
    while (temp) {
        struct Node *next = temp->next;
	free(temp);
	temp = next;
    }

    return 0;
}
