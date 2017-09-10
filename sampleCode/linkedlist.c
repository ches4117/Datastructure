#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
	int num;
	listPointer next;
};

void insert(listPointer*);

int main()
{
	listPointer first;
	int i;
	first = malloc(sizeof(*first));
	first->num = 1;
	first->next = NULL;
	insert(&first);
	
	printf("%d\n",first->num);
	printf("%d\n",first->next->num);	
	return 0;
}

void insert(listPointer *first)
{
	int num;
	listPointer x;
	x = malloc(sizeof(*x));
	
	scanf("%d",&num);
	x->num = num;
	x->next = NULL;

	(*first)->next = x;
	
}
