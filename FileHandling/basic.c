#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fptr = NULL;
    char name[] = "Hello, Pugal! I'm studying file handling in C";
    fptr = fopen("fileExample.txt", "w");
    if(fptr == NULL) {
       printf("File is not created!\n");
    }
    else {
      printf("File is open to write!\n");
      fputs(name, fptr);
      fputs("\n", fptr);
      char data[100];
      //read the data from the file
      while(fgets(name, 40, fptr) != NULL) {
          printf("The data read from the file is: %s\n", data);
      }
      fclose(fptr);
      printf("File is closed now!\n");

    }
    return 0;
}
