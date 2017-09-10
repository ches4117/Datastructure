#include<stdio.h>

int a[20][20],reach[20],n;
void dfs();
int main()
{
		int i,j,count=0;
		int begin;
		FILE *input;
		input = fopen("test_data_dfs.txt", "r");
		if(input == NULL)
		{
				return 1;
		}

		fscanf(input,"%d",&n);
		for(i=1;i<=n;i++)
		{
				reach[i]=0;
				for(j=1;j<=n;j++)
						a[i][j]=0;
		}

		for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
						fscanf(input,"%d",&a[i][j]);
		printf ("\nThe output is\n");
		begin = 1;
		dfs(begin);
		printf("\n");
		for(i=1;i<=n;i++)
		{
				if(reach[i])
						count++;
		}
		if(count==n)
				printf("\n Graph is connected \n");
		else
				printf("\n Graph is not connected \n");

		return 0;
}

void dfs(int begin)
{
		int i, j;
		reach[begin] = 1;
		for(i = begin; i <= n; i++)
		{
				for(j = 1; j <= n; j++)
				{
						if(a[i][j] == 1 && reach[j] != 1)
						{
									reach[j] = 1;
									printf("%d->%d\n",i ,j);
									dfs(j);
						}
				}
		}


}
