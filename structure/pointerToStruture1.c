#include<stdio.h>
#include<string.h>
struct Device {
   int id;
   int ip_address;
   char name[30];
   int numbers[10];
   int is_active;
};
int main() {

	struct Device d;
	struct Device *dev = &d;
	dev->id = 11222;
	dev->ip_address = 0xC0A80101;
	dev->is_active = 1;
	strncpy(dev->name, "HP LAPTOP", sizeof(dev->name)-1);
        dev->name[sizeof(dev->name) - 1] = '\0';	

	//using memcpy
	//int num[10];
	int num[10] = {1, 2, 3, 4, 5, 6, 7};
	memcpy(dev->numbers, num, sizeof(dev->numbers));
	printf(" Device ID: %d, ip_address: %x, name: %s, is_active: %d\n",
		dev->id, dev->ip_address, dev->name, dev->is_active);
	printf("numbers: %d %d %d %d\n", dev->numbers[0], dev->numbers[1], dev->numbers[2], dev->numbers[3]);
	return 0;
}
