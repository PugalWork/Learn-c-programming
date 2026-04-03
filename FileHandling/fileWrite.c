/* Covered fopen() w mode which is write mode. This mode will overwrite the file if there is already content is present.
 * fputc() - to write a charater
 * fputs() - to write string
 * fprintf() - to write formatted multiple type data. works like printf() function.
 */

#include<stdio.h>
#include<stdlib.h> //exit() function is in this library
int main() {
    FILE *fp = NULL;
    
    //open the file
    fp = fopen("fileExample.txt", "w");
    if (fp == NULL) {
        printf("File is not open");
	exit(1);
    }
    // write a char to the file

    char ch = 'P';
    fputc('C', fp);
    
    //fputc('\n', fp); //for a new line
    
    fprintf(fp, "\n"); //for a new line
    
    //write a string to a file

    fputs("Hello, Puagl!\n", fp);
    
    //formatted output function, fprintf, we can write multiple type of data

    int age = 25;
    char name[] = "Pugal";
    fprintf(fp, "My name is %s, and my age is %d\n", name, age);

    //write a paragraph and store in the file

    char para[] = "Hello, everyone!.\nThis is a software engineer in India working and writing this file" \
                  "\nHope this paragraph enters in the desired file\n";
    fputs(para, fp);

    //always close the file at the end
    fclose(fp);
    return 0;
      
}
