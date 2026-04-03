#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fp = NULL;
    fp = fopen("fileExample.txt", "a");
    if (fp == NULL) {
        printf("File is not open\n");
	exit(1);
    }
    fputs("\n*********This is from fileAppend.c!********\n", fp);
    fprintf(fp, "\nI'm watching jenny's lectures!\n");
    return 0;

}
