#include <stdio.h>
#include <stdlib.h>   // for malloc, free
#include<ctype.h>
#include<string.h>
typedef struct Weather {
    float degree;
    char place[100];
} weather;

int main() {
    weather *ptr = (weather*)malloc(sizeof(weather));
    ptr->degree = 23.34;
    snprintf(ptr->place, sizeof(ptr->place), "Palani");
    printf("degree: %f, place: %s\n", ptr->degree, ptr->place);
    free(ptr);
    return 0;
}
