#include<stdio.h>
typedef struct{
    char name[50];
    int age;
}Author;

typedef struct {
    char title[100];
    int pages;
    float price;
    Author author;
}Books;

int main() {
    Books book = {"Da vinci code", 456, 365.34, {"Dan Brown", 65}};
    printf("Favorite Book Details!\n");
    //printf("Title: %s\nNumber of Pages: %d\nPrice: %.2f\nAuthor Name: %s\nAuthor's age: %d\n",
           //book.title, book.pages, book.price, book.author.name, book.author.age); */
    Books *ptr = &book;
    printf("Author Name: %s\n", ptr->author.name);
    
    return 0;
}
