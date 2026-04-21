#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

int count_list (Node *head) {
    Node *temp = head;
    int count = 0;
    while (temp) {
        temp = temp->next;
	count++;
    }
    return count;
}

void insert_at_begin (Node **head) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("malloc failed");
	return;
    }
    printf("Enter the ele you want to insert at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void insert_at_end (Node **head) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("malloc failed");
	return;
    }
    Node *temp = *head;
    printf("Enter the ele u want to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at_pos (Node **head) {
    int count = count_list(*head);
    int pos;
    Node *temp = *head;
    printf("Enter the pos, you want to insert ?");
    scanf("%d", &pos);
    if (pos > count || pos < 0) {
        printf("Enter valid postition!");
	return;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    printf("Enter the ele you want to insert at the pos %d : ", pos);
    scanf("%d", &newnode->data);
    int i = 1;
    while (i < pos - 1) {
        temp = temp->next;
	i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

void display_list (Node **head) {
     Node *temp = *head;
     while (temp != NULL) {
         printf("%d ", temp->data);
	 temp = temp->next;
     }
     printf("\n");
}

void create_list (Node **head) {
    int num_ele = 0;
    printf("Enter how many elements you want to insert: ");
    scanf("%d", &num_ele);
    *head = NULL;
    Node *temp = NULL;
    while (num_ele) {
        Node *newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL) {
	    printf("Memory allocation failed");
	    return;
	}
	printf("Enter the element: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if (*head == NULL) {
	    *head = temp = newnode;
	} else {
	    temp->next = newnode;
	    temp = newnode;
	}
        num_ele--; 
    }
}

int main() {

    Node *head = NULL;
    create_list(&head);
    display_list(&head);
    insert_at_begin(&head);
    display_list(&head);
    insert_at_end(&head);
    display_list(&head);
    insert_at_pos(&head);
    display_list(&head);
}
