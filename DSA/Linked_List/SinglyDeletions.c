#include<stdio.h>
#include<stdlib.h>

void list_display();
struct Node {
      int data;
      struct Node *next;
};
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

void delete_from_begin() {
    if(head == NULL) {
       printf("No elements in the list");
       return;
    }
    temp = head;
    head = head->next;
    free(temp);
    list_display();
          
}

void delete_from_end() {
    if (head == NULL) {
        printf("No elements in the list\n");
	return;
    }
    temp = head;
    struct Node *prev;
    while (temp->next != NULL) {
        prev = temp;
	temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    list_display();
}

void delete_from_pos() {
    int total = count_elements();
    int pos, i = 1;
    if (total == 0) {
        printf("There is no element to delete\n");
	return;
    }
    printf("Enter the position which you want to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > total +1) {
        printf("Enter the valid position to delete between 1 and %d:", total + 1);
	return;
    }
    if (pos == 1) {
        delete_from_begin();
	return;
    }
    temp = head;
    struct Node *next;
    while (i < pos) {
	   temp = temp->next;
	   i++;
    }
    next = temp->next;
    temp->next = next->next;
    free(next);
    list_display();

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
   delete_from_begin();
   delete_from_end();
   delete_from_pos();
   list_free();
   return 0;	
}
