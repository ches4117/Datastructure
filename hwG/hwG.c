#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void easy_hash();
void hard_hash();

//I doesn't use linear probing, but use linked list to solve collision.
typedef struct node
{
		char str[100];
		struct node* next;
}newnode;

int main()
{
		char input[10000], str[100];
		FILE *fp, *fo;
		printf("Input a short string.\n");
		fgets(input,100,stdin);
		easy_hash(input);

		printf("Input the name of the next input file.\n");
		scanf("%s",str);

		fp = fopen(str,"r");
		fgets(input,10000,fp);
		hard_hash(input);
		fclose(fp);

		return 0;
}

void easy_hash(char input[])
{
		//use a string to store each block of input.
		char *token;
		int collision = 0, hashdiv = 10, num_data = 0, full_data = 0;
		long int tmp, i;
		newnode *bucket[10], *tmp_node, *new_node;

		token = strtok(input," ");
		for(i = 0; i < 10; i++)
		{
			bucket[i] = (newnode*)malloc(sizeof(newnode));
			strcpy(bucket[i]->str," ");
			bucket[i]->next = NULL;
		}

		while(token != NULL)
		{
				//I use % as my hash function
				tmp = token[0];
				tmp %= hashdiv;
				if(!(strcmp(bucket[tmp]->str," ")))
						strcpy(bucket[tmp]->str,token);
				else
				{
					//If the bucket has thing, then find its next whether is NULL.
					tmp_node = bucket[tmp];

					while(tmp_node != NULL)
					{
						//If next doesn't NULL, then collisin add one, and turn to next.
						collision++;
						if(tmp_node->next == NULL)
							break;
					}

					new_node = malloc(sizeof(newnode));
					strcpy(new_node->str,token);
					new_node->next = NULL;
					tmp_node->next = new_node;

					num_data++;
					token = strtok(NULL," \n");
					continue;
				}
				full_data++;
				num_data++;
				token = strtok(NULL," \n");
		}
		
		
		for(i = 0; i < 10; i++)
		{
				printf("bucket[%d]: ",i);
				while(bucket[i] != NULL)
				{
						printf("%s",bucket[i]->str);
						bucket[i] = bucket[i]->next;
						if(bucket[i]) printf(" -> ");
				}
					
				printf("\n");
		}

		printf("\nnumber of data: %d\n",num_data);
		printf("number of buckets: %d\n",hashdiv);
		printf("filled buckets: %d\n",full_data);
		printf("empty buckets: %d\n",10 - full_data);
		printf("collisions: %d\n",collision);

}

void hard_hash(char input[])
{
		char *token;
		int collision = 0, hashdiv, num_data = 0, full_data = 0;
		int tmp, i;
		newnode *bucket[1000], *tmp_node, *new_node;

		//Input the bucket number you want.
		printf("Input the number of bucket.\n");
		scanf("%d",&hashdiv);

		token = strtok(input," ");
		for(i = 0; i < hashdiv; i++)
		{
			bucket[i] = (newnode*)malloc(sizeof(newnode));
			strcpy(bucket[i]->str," ");
			bucket[i]->next = NULL;
		}

		while(token != NULL)
		{
				tmp = (token[0]%hashdiv);
				if(!(strcmp(bucket[tmp]->str," ")))
						strcpy(bucket[tmp]->str,token);
				else
				{
					
					tmp_node = bucket[tmp];

					while(tmp_node != NULL)
					{
						collision++;
						if(tmp_node->next == NULL)
							break;
						tmp_node = tmp_node->next;
					}

					new_node = malloc(sizeof(newnode));
					strcpy(new_node->str,token);
					new_node->next = NULL;
					tmp_node->next = new_node;

					num_data++;
					token = strtok(NULL," \n");
					continue;
				}
				full_data++;
				num_data++;
				token = strtok(NULL," \n");
		}
		
		
		for(i = 0; i < hashdiv; i++)
		{
				printf("bucket[%d]: ",i);
				while(bucket[i] != NULL)
				{
						printf("%s",bucket[i]->str);
						bucket[i] = bucket[i]->next;
						if(bucket[i]) printf(" -> ");
				}
					
				printf("\n");
		}

		printf("\nnumber of data: %d\n",num_data);
		printf("number of buckets: %d\n",hashdiv);
		printf("filled buckets: %d\n",full_data);
		printf("empty buckets: %d\n",hashdiv- full_data);
		printf("collisions: %d\n",collision);
}

/*This question if I use linear probing, it shoule has 200~300 space to store the data.
If using chaining to solve the problem of collision, is uses smaller space.*/
