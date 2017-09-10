#include<stdio.h>
#define FALSE 0
#define TRUE 1

void menu();
void dfs();
void prim();
void dijks();
int matrix[20][20], visit[20], num;
int dist[20];
int main()
{
		int choose, end = 0;
		int i, j, count, begin;
		while(1)
		{
				menu();
				scanf("%d",&choose);

				switch(choose)
				{
						case 1:

								scanf("%d",&num);
								//input the matrix.
								for(i = 1; i <= num; i++)
								{
										visit[i] = 0;
										for(j = 1; j <= num; j++)
												scanf("%d",&matrix[i][j]);
								}

								count = 0;
								dfs(1);

								for(i=1; i<=num; i++)
								{
										if(visit[i])
												count++;
								}
								//if visied vertex doesn't equal to the number of the vertex, then it is not connected.
								if(count == num)
										printf("\nGraph is connected.\n");
								else
										printf("\nGraph is not connected.\n");
								break;

						case 2:
								scanf("%d",&num);
								for(i = 1; i <= num; i++)
								{
										visit[i] = 0;
										for(j = 1; j <= num; j ++)
										{
												scanf("%d",&matrix[i][j]);
												//set 0 to a very big number.
												if(matrix[i][j] == 0)
														matrix[i][j] = 999;
										}
								}
								prim(1);
								break;

						case 3:
								scanf("%d",&num);
								for(i = 0; i < num; i++)
								{
										for(j = 0; j < num; j ++)
										{
												scanf("%d",&matrix[i][j]);
												if(matrix[i][j] == 0)
														matrix[i][j] = 999;
										}
								}

								scanf("%d",&begin);
								dijks(&begin);
								break;

						case 4:
								end = 1;
								break;
				}

				if(end == 1) break;
		}


}

void menu()
{
		printf("\nWhich thing you want to do?\n");
		printf("1. Depth First Search\n");
		printf("2. Prim's algorithm\n");
		printf("3. Dijkstra's algorithm\n");
		printf("4. Nothing\n");
}

void dfs(int v)
{
		int i;
		//set initial is visited.
		visit[v] = TRUE;
		for(i = 1; i <= num; i++)
		{
				if(matrix[v][i] && !visit[i])
				{
						//if the next vertex is not visited, then go to this vertex, and run its line.
						printf("\n %d->%d",v, i);
						dfs(i);
				}
		}


}
void prim(int begin)
{
		int mincost = 0, min;
		int from, to, u, v, count = 1;
		int i, j;

		mincost = 0;
		visit[begin] = TRUE;
		while(count < num)
		{
				for(i = 1, min = 999; i <= num; i++) 
						for(j = 1; j <= num; j++)
								//rec the neighbor minimum edge and from where to where.
								if(matrix[i][j] < min)
										if(visit[j] != 0)
										{
												min = matrix[i][j];
												from = u = i;
												to = v = j;
										}

				if(visit[u] == 0 || visit[v] == 0)
				{
						//printf the weight and from ,to.
						printf("\n Edge %d:(%d %d) cost:%d",count++ ,from ,to ,min);
						mincost += min;
						visit[from] = 1;
				}

				matrix[from][to] = matrix[to][from] = 999;
		}

		printf("\n Minimun cost=%d\n",mincost);
}
void dijks(int *begin)
{
		int i, j, count = 2, flag[20], min, u, w;
		for(i = 0; i < num; i++)
				flag[i] = 0, dist[i] = matrix[*begin][i];
		
		printf("\nAdd node %d, step %d:",*begin ,count - 1);
		
		for(i = 0 ; i < num; i++)
		{
			if(dist[i] == 999) printf("0 ",dist[i]);
			else printf("%d ",dist[i]);
		}
		printf("\n");
		while(count < num)
		{
				min=99;
				//find the least weight.
				for(w = 0; w < num; w++)
						if(dist[w] < min && !flag[w])
								min = dist[w] ,u = w;
				flag[u]=1;
				count++;
				printf("Add node %d, step %d:",u ,count - 1);
				for(w = 0; w < num; w++)
						if((dist[u] + matrix[u][w] < dist[w]) && !flag[w])
								//update the matrix.
								dist[w] = dist[u] + matrix[u][w];

				for(i = 0 ; i < num; i++)
				{
					if(dist[i] == 999) printf("0 ",dist[i]);
					else printf("%d ",dist[i]);
				}

				printf("\n");
		}

}
