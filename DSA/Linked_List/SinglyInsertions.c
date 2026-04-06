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
void insert_at_begin() {
     newnode = (struct Node*)malloc(sizeof(struct Node));
     printf("Enter the element you want to insert in the beginning: ");
     scanf("%d", &newnode->data);

     /*Insert newnode in the beginning of the list*/
     newnode->next = head;
     head = newnode;
     printf("After inserting an element in the beggining!\n");
     list_display();

}

void insert_at_end() {
     newnode = (struct Node*)malloc(sizeof(struct Node));
     if (!newnode) {
         printf("malloc failed\n");
	 return;
     }
     printf("Enter the element which you want to insert at the end: ");
     scanf("%d", &newnode->data);
     newnode->next = NULL;
     /* handle empty list*/
     if (head == NULL ) {
	 head = newnode;
	 return;
     }
     temp = head;
     while (temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = newnode;
     temp = newnode;
     printf("After inserting element at the end of the list!\n");
     list_display();
}

void insert_at_pos() {
    int total_elements = count_elements();
    int pos, i = 1;
    printf("Which position you want to insert ? ");
    scanf("%d", &pos);
    if (pos < 1 || pos > total_elements + 1) {
	printf("Invalid position. Enter between 1 and %d\n", total_elements + 1);
	return;
    }
    else {
       printf("Enter the element which you want to insert at the position %d : ", pos);
       newnode = (struct Node*)malloc(sizeof(struct Node));
       if (!newnode) {
           printf("malloc failed\n");
	   return;
       }
       scanf("%d", &newnode->data);
       newnode->next = NULL;
       if (pos == 1) {
           newnode->next = head;
	   head = newnode;
	   list_display();
	   return;
       }
       temp = head;
       while (i < pos - 1) {
           temp = temp->next;
	   i++;
       }
       newnode->next = temp->next;
       temp->next = newnode;
       temp = newnode;
       list_display();
    }

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
    insert_at_begin();
    insert_at_end();
    insert_at_pos();
    list_free();
    return 0;	
}
