#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fptr = NULL;
    //char name[] = "Hello, Pugal! I'm studying file handling in C";
    fptr = fopen("fileExample.txt", "r");
    if(fptr == NULL) {
       printf("File is not created!\n");
    }
    else {
      printf("File is open to write!\n");
      //fputs(name, fptr);
      //fputs("\n", fptr);
      char data[100];
      //read the data from the file
      while(fgets(data, 100, fptr) != NULL) {
          printf("%s", data);
      }
      //fputs("\n", fptr);
      fclose(fptr);
      printf("File is closed now!\n");

    }
    return 0;
}
