#include <stdio.h>
#include <stdlib.h>

int power_iter(int a, unsigned int n);
int power_rec(int a, unsigned int n);

int main(int argc, char *argv[])
{

	printf("2^8=%d 2^16=%d\n", power_iter(2,8), power_rec(2,16));
	return EXIT_SUCCESS;
}

int power_iter(int a, unsigned int n){
	int i;
	int buff = a;

	if(n==0)
		return 1;
	else if (n==1)
		return a;

	for (i = 0; i < n-1; i++)
		a *= buff;

	return a;
}

int power_rec(int a, unsigned int n){
    if (n != 0)
        return (a * power_rec(a, n - 1));
    else
        return 1;
}
