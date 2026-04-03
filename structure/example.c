#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct Employee{
   int employee_no;
   int experince_in_yrs;
   char name[30]; // character array - we know size at compile time, we can modify it.
   char *nickname; //string literal, can't modify
   char *firstname;
};

void dynamic_allocation() {
    struct Employee *ptr = malloc(sizeof(struct Employee));
    ptr->firstname = "Hello";
    ptr->nickname = "cookie";
    //ptr->name = "Pugal";
    printf("\n**%s %s***\n", ptr->firstname, ptr->nickname);
    free(ptr);
}

int main()
{
    struct Employee emp;
    emp.employee_no = 1234;
    emp.experince_in_yrs = 4;
    strncpy(emp.name, "Hullu", sizeof(emp.name)-1);
    emp.name[sizeof(emp.name)-1] = '\0';
    
    // We can modify char array
    emp.name[1] = 'e';
    // strncpy(emp.name, "Hello Pugal", sizeof(emp.name)-1);
    // emp.name[sizeof(emp.name)-1] = '\0';
    
    /* We can't modify string literal, we can make the pointer to point to different literal*/
    emp.nickname = "Pookie";
    emp.nickname = "kunu";
    //emp.nickname[0] = 'C'; // Wrong
   
   emp.firstname = malloc(20);
   strncpy(emp.firstname, "Monkey", 19);
   emp.firstname[19] = '\n';
   
    //printing the deatils
    printf("*****Employee Details*****\n");
    printf("Employee No: %d\nEmployee Name: %s\nYears of Experience: %d\nNickname: %s\nFirst name: %s\n",
           emp.employee_no, emp.name, emp.experince_in_yrs, emp.nickname, emp.firstname);
    free(emp.firstname);
    dynamic_allocation();
    return 0;
}

