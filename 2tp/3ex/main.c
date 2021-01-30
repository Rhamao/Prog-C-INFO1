#include <stdio.h>
#include <stdlib.h>

int print_inc_desc_iter(int max);
int print_inc_desc_rec(int max);
int print_desc_rec(int max);
int print_inc_rec(int lo, int hi);

int main(int argc, char *argv[])
{
	print_inc_desc_iter(10);
	printf("\n");
	print_inc_desc_rec(10);
	return EXIT_SUCCESS;
}

int print_inc_desc_iter(int max)
{
	int i;
	for (i = 10; i > 0; i--)
		printf("%d ", i);
	for (i = 1; i < 11; i++)
		printf("%d ", i);
	return 1;
}

int print_inc_desc_rec(int max)
{
	if (max < 0)
		return -1;

	print_desc_rec(max);
	print_inc_rec(1, max);
	printf("\n");
	
	return 1;
}

int print_desc_rec(int max)
{
	if (max <= 0)
		return 0;

	printf("%d ", max);
	max--;
	print_desc_rec(max);
}

int print_inc_rec(int lo, int hi)
{
	if (lo > hi)
		return 0;

	printf("%d ", lo);
	lo++;
	print_inc_rec(lo, hi);
}
