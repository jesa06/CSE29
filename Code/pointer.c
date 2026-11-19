#include <stdio.h>
#include <stdint.h>


int main(){
	uint32_t arr[10];
	uint32_t* parr = arr;
	//char* parr = (char*) arr; //convert it to character pointer 

	arr[0] = 1000;
	arr[1] = 2000;
	printf("ptr: %p\n", arr);

	printf("arr[0]: %d\n", *(arr+0)); // add 0 and dereference...give me what is stored there
	
	printf("arr[1]: %d\n", parr[1]);
	
	return 0;
}
