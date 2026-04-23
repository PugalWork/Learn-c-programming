#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
} Node;
void display_list(Node *head) {
    Node *temp = NULL;
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
	temp = temp->next;
    }
    printf("\n");
}
Node* merge_lists(Node *list1, Node *list2) {
     if (list1 == NULL) return list2;
     if (list2 == NULL) return list1;
     Node *head = NULL;
     Node  *temp = NULL;
     if (list1->data < list2->data) {
         head = list1;
	 list1 = list1->next;
     } else {
         head = list2;
	 list2 = list2->next;
     }
     temp = head;
     while (list1 != NULL && list2 != NULL ) {
         if (list1->data < list2->data) {
	     temp->next = list1;
	     temp = list1;
	     list1 = list1->next;
	 } else {
	     temp->next = list2;
	     temp = list2;
	     list2 = list2->next;
	 }
     }
     temp->next = list2;
     return head;

}

void create_list(Node **head) {
     Node *temp, *newnode;
     int num_ele;
     printf("Enter how many ele u want to insert: ");
     scanf("%d", &num_ele);

     while (num_ele--) {
         newnode = (Node*)malloc(sizeof(Node));
         if (newnode == NULL) {
             printf("malloc failed!\n");
	     return;
         }
	 printf("Enter the data: ");
	 scanf("%d", &newnode->data);
	 newnode->next = NULL;
	 if (*head == NULL) {
	     *head = temp = newnode;
	 } else {
	     temp->next = newnode;
	     temp = newnode;
	 }
     }
     
}

int main() {
    Node *list1 = NULL, *list2 = NULL, *newhead = NULL;
    printf("Filling List1!\n");
    create_list(&list1);
    printf("Filling List2!\n");
    create_list(&list2);
    newhead = merge_lists(list1, list2); 
    printf("Printing the merged list!\n");
    display_list(newhead);
}
