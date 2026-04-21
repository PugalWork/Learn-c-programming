#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
   int data;
   struct Node *next;
} Node;

void create_list(Node **head) {
     int num_ele = 0;
     Node *temp;
     printf("How many elements you want to enter ? ");
     scanf("%d", &num_ele);
     while (num_ele--) {
	 Node *newnode = (Node*)malloc(sizeof(Node));
         if (newnode == NULL) {
             printf("malloc failed!\n");
	     return;
         }
         printf("Enter an element: ");
         scanf("%d", &newnode->data);
         newnode->next = NULL;	 

         if (*head == NULL) {
             temp = *head = newnode;
         } else {
	     temp->next = newnode;
	     temp = newnode;
	 }
     }

}

void display_list (Node **head) {
     Node *temp = *head;
     while (temp != NULL) {
         printf("%d ", temp->data);
	 temp = temp->next;
     }
}

void find_nth_node(Node **head) {
     Node *p1, *p2;
     p1 = *head;
     p2 = *head;
     int n;
     printf("Enter the nth node which you want to display from the end of the list\n");
     scanf("%d", &n);
     
     for (int i = 0; i < n; i++) {
          if (p2 == NULL) {
	      printf("Invalid position. List has fewer options!");
	      return;
	  }
	  p2 = p2->next;
     }
     while (p2 != NULL) {
         p1 = p1->next;
	 p2 = p2->next;
     }
     printf("%d'th position element from the end of the list is %d\n", n, p1->data);
}

int main() {
    Node *head = NULL;
    create_list(&head);
    display_list(&head);
    find_nth_node(&head);


}
