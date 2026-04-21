#include<stdio.h>
#include<stdlib.h>

void list_display();
typedef struct Node {
      int data;
      struct Node *next;
} Node;
struct Node *head, *newnode, *temp;

int count_elements() {
    int total_elements = 0;
    temp = head;
    while (temp != NULL) {
        temp = temp->next;
        total_elements++;
    }
    return total_elements;
}

Node* reverse_list(Node *head) {
    // Base Condition
    if (head == NULL || head->next == NULL) {
        return head;
    } 
    Node *newnode = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;

    return newnode;

}

void list_display() {
     temp = head;
     while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
     }
     printf("\n");

}

void create_list() {
    int num_ele = 0, i = 0;
    printf("\nHow many elements you want to insert ? ");
    scanf("%d", &num_ele);
    if (num_ele == 0) {
        printf("0 elements entered\n");
	return;
    }
    head = NULL;
    while (i < num_ele) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        if (!newnode) {
	    printf("Memory allocation failed!");
	    return;
	}
	printf("Enter the data: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if (head == NULL) {
	    head = temp = newnode;
	    i++;
	} else {
	temp->next = newnode;
	temp = newnode;
	i++;
	}
    }
}

void list_free() {
     temp = head;
     while (temp != NULL) {
         struct Node *next = temp->next;
	 free(temp);
	 temp = next;
     }

}
int main() {
    create_list();
    list_display();
    head = reverse_list(head);
    list_display();
    list_free();
    return 0;	
}
