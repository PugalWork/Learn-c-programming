#include<stdio.h>
#include<stdlib.h>

void list_display();
struct Node {
      int data;
      struct Node *next;
};
struct Node *head, *newnode, *temp;

int count_elements();

void find_nth_node_from_end () {
    int count = count_elements();
    int n;
    printf("enter nth node from end: ");
    scanf("%d", &n);
    //boundary checks
    if (n <= 0 || n > count) {
        printf("Enter the valid position!\n");
	return;
    }
    int i = 0;
    temp = head;
    while (i < count - n) {
        temp = temp->next;
	i++;
    }
    printf("%d'st node from the end is %d\n", n, temp->data);
}

int count_elements() {
    int total_elements = 0;
    temp = head;
    while (temp != NULL) {
        temp = temp->next;
        total_elements++;
    }
    return total_elements;
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
    find_nth_node_from_end();
    list_free(); 
    return 0;	
}
