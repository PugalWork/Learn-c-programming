/* a+ mode is used for reading and appending.
 * if file don't exist then it will create a new file
 */

#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fptr = NULL;
    fptr = fopen("fileExample2", "a+");
    if(fptr == NULL) {
       printf("File is not created!\n");
    }
    fputs("Hello, file handling features!", fptr);
    rewind(fptr); 
    //after writing in the file, the cursor will be at the end of the line, 
    //so this rewind fn will move the cursor to the beginning
    
    while(!feof(fptr)) {
       char ch = fgetc(fptr);
       printf("%c", ch);
    }
    printf("\n");
    fputs("Updated lines second time", fptr);
    return 0;
}
