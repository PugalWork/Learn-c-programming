#include<stdio.h>
typedef struct Weather {
       float degree;
       char place[100];
}weather;

int main() {
    weather w = {32.23, "Bangalore"};
    weather *ptr = &w;
    printf("size of w: %lu\n", sizeof(w));
    printf("degree: %f, place: %s", ptr->degree, ptr->place);
    return 0;
}
