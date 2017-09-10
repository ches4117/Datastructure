nclude<stdio.h>
#include<stdlib.h>
#include<time.h>
float bubble();
void  quick();
float selection();

int main()
{
		FILE *fp, *fo;
		int num1[60000], num2[60000], num3[60000];
		int i = 0, j;
		float t_bubble, t_quick, t_selection;
		char filename[100];
		printf("Input the filename.\n");
		scanf("%s",filename);
		fp = fopen(filename,"r");
		fo = fopen("output.txt","w");

		if(fp == NULL) printf("error!!\n");

		while(fscanf(fp, "%d", &num1[i])!=EOF)
		{num2[i] =  num1[i]; num3[i] = num1[i]; i++;}
		//three sorting.
		printf("\nWe will do following sorting algorithm\n");
		printf("1. Bubble sort.\n");
		printf("2. Quick sort.\n");
		printf("3. Selection sort.\n");
		printf("The result will be stored in output.txt.\n");
		printf("Press any key to continue.\n");
		getc(stdin);

		t_bubble = bubble(num1, i);
		
		//quick sort set clock outside.
		clock_t start = clock();
		quick(num2, 0, i);
		clock_t end = clock();
		t_quick = ((end-start)/(float)CLOCKS_PER_SEC);

		t_selection = selection(num3, i);
		for(j = 0; j < i; j++)
				fprintf(fo,"%d ",num3[j]);

		printf("\nBubble sort time cost: %f\n",t_bubble);
		printf("Quick sort time cost: %f\n",t_quick);
		printf("Selection sort time cost: %f\n",t_selection);

		printf("\nSpead rank\n");
		printf("Rank1: qucik sort\n");
		printf("Rank2: Selection sort\n");
		printf("Rank3: Bubble sort\n");

		return 0;
}

float bubble(int num[], int rec_num)
{
		int i, j, swap;
		clock_t start = clock();
		//Every loop will find the biggest one.

		for(i = 0; i < rec_num - 1; i++)
				for(j = 0; j < rec_num - i - 1; j++)
				{
						if(num[j] > num[j+1])
						{
								swap = num[j];
								num[j] = num[j+1];
								num[j+1] = swap;
						}
				}
		clock_t end = clock();
		return ((end - start)/(float)CLOCKS_PER_SEC);
}

void quick(int num[], int left, int right)
{
		int i, j, pivot, tmp;

		if(left < right)
		{
				i = left; j = right + 1;
				pivot = num[left];
				do{
						//Find the biggest at left and smallest at right.
						//If i is not equal to j then change these two value.
						do i++; while(num[i] < pivot);
						do j--; while(num[j] > pivot);

						if(i < j) 
						{
								tmp = num[i];
								num[i] = num[j];
								num[j] = tmp;
						
						}
				}while (i < j);
						tmp = num[left];
						num[left] = num[j];
						num[j] = tmp;

						quick(num, left, j-1);
						quick(num, j+1, right);
		}

}

float selection(int num[], int rec_num)
{
		int i, j, position, tmp;
		clock_t start = clock();
		for ( i = 0 ; i < ( rec_num - 1 ) ; i++ )
		{
				//Every loop will find the smallest one, and set it at the beginning.
				position = i;

				for ( j = i + 1 ; j < rec_num ; j++ )
				{
						if ( num[position] > num[j] )
								position = j;
				}
				if ( position != i )
				{
						tmp = num[i];
						num[i] = num[position];
						num[position] = tmp;
				}
		}
		clock_t end = clock();
		return ((end - start)/(float)CLOCKS_PER_SEC);

}
