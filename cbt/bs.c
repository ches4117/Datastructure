#include <stdio.h>
int binary();
int main()
{
	FILE *input;
	int count;
	int i;
	int temp[50];
	int find_number, begin = 0, ans;
	input = fopen("test_data_bs.txt","r");
	// initialize
	for(count = 0; count < 50; count++)
	{
		temp[count] = 0;
	}
	count = 0;
	
	// get the input data from input_file
	while(fscanf(input, "%d", &temp[count]) != EOF)
	{
		count++;
	}
	find_number = temp[count-1];
	count -= 2;
	
	ans = binary(temp, begin, count, find_number);
	if (ans == 0) printf("not found\n");
	else printf("found\n");
	fclose(input);

	return 0;
}

int binary(int temp[], int begin, int count, int find_number)
{
		int middle = (begin + count)/2;
		if(temp[middle] == find_number)
				return 1;
		else if(middle >= begin && middle < count)
		{
				if(temp[middle] < find_number)
					binary(temp,(middle + count)/2 ,count, find_number);
				else
					binary(temp, begin ,(middle + begin)/2, find_number);

		}
		
		else return 0;

}
