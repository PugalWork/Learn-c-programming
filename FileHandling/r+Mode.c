/* r+ mode reads and modify the existing content
 * use this mode if you want to modify the content
 * if there is no existing content available then it just writes in the file. but file should exist.
 */

#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fptr = NULL;
    fptr = fopen("fileExample2", "r+");
    if(fptr == NULL) {
       printf("File is not created!\n");
    }
    else {
      printf("File is open to modify the content!\n");
      
      // this will modify the existing content with this below input
      fputs("This is r plus mode\n", fptr);
      fputc('Z', fptr);
      fclose(fptr);
      printf("Content is modified and file is closed now!\n");

    }
    return 0;
}
