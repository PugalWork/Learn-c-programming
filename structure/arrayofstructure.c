#include<stdio.h>
#include<stdbool.h>

typedef struct Device {
   int id;
   bool is_active;
}Device;


int main() {
        Device devs[2];
        
        //fill the device details
        for(int i = 0; i < 2; i++) {
            devs[i].id = i + 1;
            devs[i].is_active = true;
        }
        
        //print the device details
         for(int i = 0; i < 2; i++) {
             printf("devs[%d] id: %d, is_active: %s\n", i, devs[i].id, devs[i].is_active?"true":"false");  
           
        }
        
   return 0;
}


