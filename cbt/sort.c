#include <stdio.h>
void quick();
void selection();

int main()
{
	FILE *input, *output;
	int count;
	int i, left;
	int temp[50];
	input = fopen("test_data_sorting.txt","r");
	output = fopen("output_sorting.txt","w");
	// initialize
	for(count = 0; count < 50; count++)
	{
		temp[count] = 0;
	}
	count = 0;
	//
	// get the input data from input_file
	while(fscanf(input, "%d", &temp[count]) != EOF)
	{
		count++;
	}
	fclose(input);
	
	selection(temp, count);
	left = 0;
	quick(temp ,left, count);
	
	//write through the outputfile
	for(i = 0; i < count; i++)
	{
		fprintf(output, "%d ", temp[i]);
	}
	fclose(output);
	
	return 0;
}

void quick(int temp[],int left, int right)
{
		int tmp;
		int i = left, j = right;
		int pivot = temp[left];
		if(left < right)
		{
		do{
				do i++; while(temp[i] < pivot);
				do j--; while(temp[j] > pivot);
				if(i < j)
				{
						tmp = temp[i];
						temp[i] = temp[j];
						temp[j] = tmp;

				}
		}while(i < j);

		tmp = temp[left];
		temp[left] = temp[j];
		temp[j] = tmp;

		quick(temp, left, j-1);
		quick(temp, j+1, right);
		}


}
void selection(int temp[], int count)
{
		int small, i, j, tmp;

		for(i = 0; i < count; i++)
		{
				small = i;

				for(j = i + 1; j < count - 1; j++)
						if(temp[small] >  temp[j])
								small = j;

				if(temp[small] != i)
				{
						tmp = temp[small];
						temp[small] = temp[i];
						temp[i] = tmp;
				}
								
		}

}
