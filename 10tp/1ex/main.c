#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void swap_mem(void* z1, void* z2, size_t size);

int main(int argc, char *argv[]){

	int a = 1, b = 2;
	double aa = 1.0, bb = 2.0;
	double aaa = 1.0, bbb = 2.0;  

	swap_mem(&a, &b, sizeof(int));
	swap_mem(&aa, &bb, sizeof(double));
	swap_mem(&aaa, &bbb, sizeof(double));

	printf("%d %d\n", a, b);
	printf("%f %f\n", aa, bb);
	printf("%f %f\n", aaa, bbb);	
	
	return EXIT_SUCCESS;
}

void swap_mem(void* z1, void* z2, size_t size){
	void* buff = malloc(size);
	if (buff == NULL){
        printf("Cannot allocate memory");
        return;
    }
    memcpy(buff, z2, size); 
    memcpy(z2, z1, size);
    memcpy(z1, buff, size);
}
