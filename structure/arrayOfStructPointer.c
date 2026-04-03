#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define MAX_DEVICES 10
typedef struct Device {
   int id;
   bool is_active;
}Device;

Device *device_create(int id) {
   Device *d = malloc(sizeof(Device));
   if(!d) {
      printf("Memory allocation failed!\n");
      exit(1);
   }
   d->id = id;
   d->is_active = true;
   return d;
}

int main() {
	Device *devs[2];

	//initialize to null
	for(int i = 0; i < 2; i++) {
	    devs[i] = NULL;
	}
	devs[0] = device_create(1);
        devs[1] = device_create(2);

	//print the details
	for(int i = 0; i < 2; i++) {
	    printf("Device %d details:\nid: %d\nActive: %s\n", i + 1, devs[i]->id, devs[i]->is_active? "true": "false");
	}

	//free the pointers
	
	for(int i = 0; i < 2; i++) {
	    free(devs[i]);
	}
   return 0;	
}
