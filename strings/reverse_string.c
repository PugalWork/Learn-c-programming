#include<stdio.h>
#include<string.h>
#include<ctype.h>

void reverse(char *start, char *end);

void reverse_the_word(char str[]) {
     char *start;
     char *end;
     start = str;
     while(*str != '\0') {

	 if(*str == ' ') {
            reverse(start, end);
	    start = str + 1;
	 }
	 else if(*(str + 1) == '\0') {
	   end = str;
	   reverse(start, end);
	 } 
	 end = str;
         str++;
     }
}

void reverse(char *start, char *end) {
     while(start < end) {
         char tmp = *start;
	 *start = *end;
	 *end = tmp;
	 start++;
	 end--;
     }
     //*start = '\0'; - this is a bug bcz, this is already existing string and we are 
     //just reversing it. it has already '\0'. so no need to add
}
int main() {
    char str[] = "This is my programming in Linux";
    int length = strlen(str); //strlen counts only charaters
    
    //int size = sizeof(str); //sizeof counts all chars + '\0'
    
    //printf("length: %d, size: %d\n", length, length1); // 31, 32
    
    reverse(str, &str[length-1]);
    reverse_the_word(str);
    printf("%s\n", str);
    int x = 2;
    printf("printing value x:%d\n", x);
    return 0;
}
