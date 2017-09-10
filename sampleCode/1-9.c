#include<stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void perm(char [], int, int);
int main()
{
	char list[4] = {'a', 'b', 'c', 'd'};
	perm(list, 0, 3);
	return 0;
}

void perm(char *list, int i, int n)
{
	int j, tmp;
	if(i == n)
	{
		for(j = 0; j <= n; j++)
			printf("%c",list[j]);
		printf("\n");
	}
	else
	{
		for(j = i; j <= n; j++)
		{
			SWAP(list[i], list[j], tmp);
			perm(list, i+1, n);
			SWAP(list[i], list[j], tmp);
		}
	}
}
