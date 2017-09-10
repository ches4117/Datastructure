#include<stdio.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define max_stack_size 10000
//store mouse each move
typedef struct
{
		int row;
		int column;
		int dir;
} element;
//store four directions 
typedef struct
{
		int ver;
		int hor;
} offset;

element stack1[10000], stack2[10000];

//each mouse has unlike pop and push
element pop();
void push();
element pop2();
void push2();

int main()
{
		int i = 0 , j, top1 = 0, top2 = 0, found1 = FALSE, found2 = FALSE, dir1, dir2, meet, max;
		int row1 = 1, column1 = 1, row2 = 99, column2 = 99, begin, mark[101][101], mark2[101][101];
		int next_row1, next_column1, next_row2, next_column2, set = 0;
		char maze[101][101] ,tmp[101], filename[100];
		//(0,0) and (99,99) set 1
		stack1[0].row = 1;
		stack1[0].column = 1;
		stack1[0].dir = 0;

		stack2[0].row = 99;
		stack2[0].column = 99;
		stack2[0].dir = 0;

		FILE *fp, *fo, *fq;
		offset move[4] = {{0,1},{1,0},{0,-1},{-1,0}};
		offset move2[4] = {{0,-1},{-1,0},{0,1},{1,0}};
		element position;
		element position2;

		printf("Please input your filename\n");
		scanf("%s",filename);
		fp = fopen(filename,"r");
		if(fp == NULL)
		{
				printf("error!!\n");
		}
		// read maze
		while(fgets(tmp, 104, fp) != NULL)
		{
				strcpy(maze[i],tmp);
				i++;
		}
		//initialize mark and mark2 to 0, represent they haven't went to the place. 
		for(i = 0; i < 101; i++)
				for(j = 0; j < 101; j++)
				{
						mark[i][j] = 0;
						mark2[i][j] = 0;
				}
		mark[1][1] = 1;
		mark2[99][99] = 1;
		//pop initial point
		position = pop(&top1);
		row1 = position.row;
		column1 = position.column;
		dir1 = position.dir;

		position2 = pop2(&top2);
		row2 = position2.row;
		column2 = position2.column;
		dir2 = position2.dir;

		while(found1 == FALSE && found2 == FALSE)
		{
				//ratA at (1, 1)
				while(dir1 < 4  && found1 == FALSE)
				{
						//each direction was represented by numbers.
						switch(dir1)
						{
								case 0:
										next_row1 = row1 + move[0].ver;
										next_column1 = column1 + move[0].hor;
										if(maze[next_row1][next_column1] == '.' && mark[next_row1][next_column1] == 0)
										{
												//have road then push to stack ,and mark this place.
												position.row = row1;
												position.column = column1;
												position.dir = dir1;
												push(&position, &top1);
												row1 = next_row1;
												column1 = next_column1;
												mark[next_row1][next_column1] = 1;
												dir1 = -1;
										}
										break;
								case 1:
										next_row1 = row1 + move[1].ver;
										next_column1 = column1 + move[1].hor;
										if(maze[next_row1][next_column1] == '.' && mark[next_row1][next_column1] == 0)
										{
												position.row = row1;
												position.column = column1;
												position.dir = dir1;
												push(&position,&top1);
												row1 = next_row1;
												column1 = next_column1;
												mark[next_row1][next_column1] = 1;
												dir1 = -1;
										}
										break;
								case 2:
										next_row1 = row1 + move[2].ver;
										next_column1 = column1 + move[2].hor;
										if(maze[next_row1][next_column1] == '.' && mark[next_row1][next_column1] == 0)
										{
												position.row = row1;
												position.column = column1;
												position.dir = dir1;
												push(&position, &top1);
												row1 = next_row1;
												column1 = next_column1;
												mark[next_row1][next_column1] = 1;
												dir1 = -1;
										}
										break;
								case 3:
										next_row1 = row1 + move[3].ver;
										next_column1 = column1 + move[3].hor;
										if(maze[next_row1][next_column1] == '.' && mark[next_row1][next_column1] == 0)
										{
												position.row = row1;
												position.column = column1;
												position.dir = dir1;
												push(&position, &top1);
												row1 = next_row1;
												column1 = next_column1;
												mark[next_row1][next_column1] = 1;
												dir1 = -1;
										}
										break;
						}
						//set the end point.
						if(row1 == 99 && next_column1 == 99)
						{
								position.row = row1;
								position.column = column1;
								position.dir = dir1;
								push(&position, &top1);
								found1 = TRUE;
								break;
						}
						//if this direction couldn't go, try another road.
						dir1 = dir1 + 1;

						//all road couldn't go, pop last one, and go back.
						if(dir1 == 4)
						{
								position = pop(&top1);
								row1 = position.row;
								column1 = position.column;
								dir1 = 0;
						}
				}

				while(dir2 < 4  && found2 == FALSE)
				{
						switch(dir2)
						{
								case 0:
										next_row2 = row2 + move2[0].ver;
										next_column2 = column2 + move2[0].hor;
										if(maze[next_row2][next_column2] == '.' && mark2[next_row2][next_column2] == 0)
										{
												position2.row = row2;
												position2.column = column2;
												position2.dir = dir2;
												push2(&position2, &top2);
												row2 = next_row2;
												column2 = next_column2;
												mark2[next_row2][next_column2] = 1;
												dir2 = -1;
										}
										break;
								case 1:
										next_row2 = row2 + move2[1].ver;
										next_column2 = column2 + move[1].hor;
										if(maze[next_row2][next_column2] == '.' && mark2[next_row2][next_column2] == 0)
										{
												position2.row = row2;
												position2.column = column2;
												position2.dir = dir2;
												push2(&position2, &top2);
												row2 = next_row2;
												column2 = next_column2;
												mark2[next_row2][next_column2] = 1;
												dir2 = -1;
										}
										break;
								case 2:
										next_row2 = row2 + move2[2].ver;
										next_column2 = column2 + move2[2].hor;
										if(maze[next_row2][next_column2] == '.' && mark2[next_row2][next_column2] == 0)
										{
												position2.row = row2;
												position2.column = column2;
												position2.dir = dir2;
												push2(&position2, &top2);
												row2 = next_row2;
												column2 = next_column2;
												mark2[next_row2][next_column2] = 1;
												dir2 = -1;
										}
										break;
								case 3:
										next_row2 = row2 + move2[3].ver;
										next_column2 = column2 + move2[3].hor;
										if(maze[next_row2][next_column2] == '.' && mark2[next_row2][next_column2] == 0)
										{
												position2.row = row2;
												position2.column = column2;
												position2.dir = dir2;
												push2(&position2, &top2);
												row2 = next_row2;
												column2 = next_column2;
												mark2[next_row2][next_column2] = 1;
												dir2 = -1;
										}
										break;
						}
						if(row2 == 1 && column2 == 1)
						{
								position2.row = row2;
								position2.column = column2;
								position2.dir = dir2;

								push2(&position2, &top2);
								found2 = TRUE;
								break;
						}
						dir2 = dir2 + 1;
						if(dir2 == 4)
						{
								position2 = pop2(&top2);
								row2 = position2.row;
								column2 = position2.column;
								dir2 = 0;
						}
				}

				if(top1 > top2) { max = top1; j = top2;}
				else { max = top2; j = top1;}

				//find whether they meet.
				for(i = 0; i <= max; i++)
				{
						if(stack1[i].row == stack2[i].row && stack1[i].column == stack2[i].column)
						{
								j = i;
								meet = 1;
								break;
						}
				}
		}
		fclose(fp);
		fo = fopen("result.txt","w");

		if(meet == 1)
		{
				//input to result.txt
				for(i = 0; i <= j; i++)
						fprintf(fo, "A:(%d,%d) B:(%d %d)\n " ,stack1[i].column ,stack1[i].row ,stack2[i].column ,stack2[i].row);

				fprintf(fo,"They met.");
		}
		else
		{
				for(i = 0; i <= j; i++)
						fprintf(fo, "A:(%d,%d) B:(%d %d)\n" ,stack1[i].column ,stack1[i].row ,stack2[i].column ,stack2[i].row);
		}
		fclose(fo);
		return 0;
}

element pop(int *top1)
{
		if((*top1) == -1) printf("error!!\n");
		return stack1[(*top1)--];
}

void push(element *position, int *top1)
{
		stack1[++(*top1)] = *position;

}
element pop2(int *top2)
{
		if((*top2) == -1) printf("error!!\n");
		return stack2[(*top2)--];
}

void push2(element *position, int *top2)
{
		stack2[++(*top2)] = *position;

}
