#include<stdio.h>
#include<stdlib.h>
void print1(int* , int);
int main()
{
		int one[] = {0, 1, 2, 3, 4};
		print1(&one[0], 5);
		return 0;
}

void print1(int *ptr, int rows)
{
		int i;
		printf("Address Content\n");
		for(i = 0; i < rows; i++)
			printf("%8u%5d\n",ptr+i, *(ptr+i));
		printf("\n");
}

