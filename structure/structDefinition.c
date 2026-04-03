#include<stdio.h>
/*
typedef struct Books books; //forward declaration + alias
struct Books{
       char book_name[100];
       int no_books;
       float price;
}; */
//Structure definition + alias combining in one line
typedef struct Books {
        char book_name[100];
	int no_books;
	float price;
}Books;
int main() {
    Books book = {"Book Thief", 2, 400.25};
    printf("Booka Name: %s, No.of Books: %d, Price: %f\n",
           book.book_name, book.no_books, book.price);
    return 0;

}

