#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct polyNode *polypointer;
typedef struct polyNode{
		float coef;
		int expon;
		polypointer link;
};
polypointer p_a, p_b, start_a = NULL, start_b = NULL;
void PrintPoly();
void attach();
void attach_poly(float a, int b, polypointer *c);
int compare();
polypointer PolyAdd();
polypointer Polysub();
polypointer PolyMul();

int main()
{
		FILE *fo, *fp;
		float tmp_coefficient;
		int tmp_exponent;
		char poly1[100], poly2[100];
		polypointer ans_add, ans_sub, ans_mul;
		//attach polynomia:
		printf("Input the first polynomial\n");
		scanf("%s",poly1);
		printf("Input the second polynomial\n");
		scanf("%s",poly2);

		fo = fopen(poly1,"r");
		fp = fopen(poly2,"r");
		//flie can't open
		if(!fo || !fo)
				printf("Flie open error");
		//attach polynomial_1
		p_a = malloc(sizeof(*p_a));
		while(fscanf(fo, "%f %d", &tmp_coefficient ,&tmp_exponent)!=EOF)
		{
				attach(&tmp_coefficient ,&tmp_exponent ,&p_a);
				if(start_a == NULL)
						start_a = p_a;
		}
		p_a->link = NULL;
		p_a = start_a;

		//attach polynomial_2
		p_b = malloc(sizeof(*p_b));
		while(fscanf(fp, "%f %d", &tmp_coefficient ,&tmp_exponent)!=EOF)
		{
				attach(&tmp_coefficient ,&tmp_exponent ,&p_b);
				if(start_b == NULL)
						start_b = p_b;
		}
		p_b->link = NULL;
		p_b = start_b;

		//printf polynomial_1 and polynomial_2
		printf("A(x) = ");
		printf("%.1fx^%d",p_a->coef ,p_a->expon);
		p_a = p_a->link;
		PrintPoly(p_a);
		
		printf("B(x) = ");
		printf("%.1fx^%d",p_b->coef ,p_b->expon);
		p_b = p_b->link;
		PrintPoly(p_b);
		
		p_a = start_a;
		p_b = start_b;
		//add A(x) and B(x) and print the answer
		ans_add = PolyAdd(p_a, p_b);
		printf("C(x) = ");
		printf("%.1fx^%d",ans_add->coef ,ans_add->expon);
		ans_add = ans_add->link;
		PrintPoly(ans_add);

		//sub A(x) and B(x) and print the answer
		ans_sub = Polysub(p_a, p_b);
		printf("D(x) = ");
		printf("%.1fx^%d",ans_sub->coef ,ans_sub->expon);
		ans_sub = ans_sub->link;
		PrintPoly(ans_sub);
		
		//mul A(x) and B(x) and print the answer
		ans_mul = PolyMul(p_a, p_b);
		printf("E(x) = ");
		printf("%.1fx^%d",ans_mul->coef ,ans_mul->expon);
		ans_mul = ans_mul->link;
		PrintPoly(ans_mul);

		fclose(fo);
		fclose(fp);
		return 0;
}
int compare(int a,int b)
{
		//this function add and sub polynomial
		if(a < b) return -1;
		else if(a == b) return 0;
		else return 1;
}

void attach(float *coefficient, int *exponent, polypointer *ptr)
{
		//create a node to store
		polypointer temp;
		temp = malloc(sizeof(*temp));
		temp->coef = *coefficient;
		temp->expon = *exponent;
		(*ptr)->link = temp;
		*ptr = temp;
}
void attach_poly(float coefficient, int exponent, polypointer *ptr)
{
		//create a node to store
		polypointer temp;
		temp = malloc(sizeof(*temp));
		temp->coef = coefficient;
		temp->expon = exponent;
		(*ptr)->link = temp;
		*ptr = temp;
}

void PrintPoly(polypointer p)
{
		//output the polynomial
		while(p != NULL)
		{
				if(p->expon == 0)
				{
						if(p->coef > 0)
						printf(" +%.1f",p->coef);
						else
						printf(" %.1f",p->coef);
				}
				else
						{
						if(p->coef > 0)
								printf(" +%.1fx^%d",p->coef ,p->expon);
						else 
								printf(" %.1fx^%d",p->coef ,p->expon);
						}

				p = p->link;

		}
		printf("\n");

}

polypointer PolyAdd(polypointer p_a, polypointer p_b)
{
		polypointer c, rear, temp;
		float sum;
		rear = malloc(sizeof(*rear));
		c = rear;
		while(p_a && p_b)
				//compare which exponent is largger
				switch(compare(p_a->expon, p_b->expon))
				{
						//p_a->expon < p_b->expon
						case -1:
								attach_poly(p_b->coef, p_b->expon, &rear);
								p_b = p_b->link;
								break;
								//p_a->expon = p_b->expon
						case 0:
								sum = p_a->coef + p_b->coef;
								if(sum) attach_poly(sum, p_a->expon, &rear);
								p_a = p_a->link; p_b = p_b->link;
								break;
								//p_a->expon > p_b->expon 
						case 1:
								attach_poly(p_a->coef, p_a->expon, &rear);
								p_a = p_a->link;
								break;
				}
		//attach the remainder of the polynomial
		for(; p_a; p_a->link) attach_poly(p_a->coef ,p_a->expon, &rear);
		for(; p_b; p_b->link) attach_poly(p_b->coef ,p_b->expon, &rear);
		rear->link = NULL;

		temp = c; c = c->link; free(temp);
		return c;
}

polypointer Polysub(polypointer p_a, polypointer p_b)
{
		//just like PolyAdd but the polynomial_2 should become negative
		polypointer c, rear, temp;
		float sum;
		rear = malloc(sizeof(*rear));
		c = rear;
		while(p_a && p_b)
				switch(compare(p_a->expon, p_b->expon))
				{
						//p_a->expon < p_b->expon
						case -1:
								p_b->coef = 0 - p_b->coef;
								attach_poly(p_b->coef, p_b->expon, &rear);
								p_b->coef = 0 - p_b->coef;
								p_b = p_b->link;
								break;
								//p_a->expon = p_b->expon
						case 0:
								sum = p_a->coef - p_b->coef;
								if(sum) attach_poly(sum, p_a->expon, &rear);
								p_a = p_a->link; p_b = p_b->link;
								break;
								//p_a->expon > p_b->expon 
						case 1:
								attach_poly(p_a->coef, p_a->expon, &rear);
								p_a = p_a->link;
								break;
				}
		for(; p_a; p_a->link) attach_poly(p_a->coef ,p_a->expon, &rear);
		for(; p_b; p_b->link) {p_b->coef = 0 - p_b->coef; attach_poly(p_b->coef, p_b->expon,&rear); p_b->coef = 0 - p_b->coef;}
		rear->link = NULL;
		temp = c; c = c->link; free(temp);
		return c;
}

polypointer PolyMul(polypointer p_a, polypointer p_b)
{
		polypointer c, rear, temp, previous, insert, start, start_b;
		float sum_coef;
		int sum_expon, i;
		rear = malloc(sizeof(*rear));
		c = rear;
		//store the beginning of the polynomial_2
		start_b = p_b;
		//first set the biggest node
		sum_coef = p_a->coef * p_b->coef;
		sum_expon = p_a->expon + p_b->expon;
		attach_poly(sum_coef, sum_expon, &rear);

		temp = c; c = c->link; free(temp); rear->link = NULL;
		start = c; p_b = p_b->link;
		while(p_a)
		{
				while(p_b)
				{
						
						sum_coef = (p_a->coef) * (p_b->coef);
						sum_expon = p_a->expon + p_b->expon;
						previous = malloc(sizeof(*previous));
						/*polynomial_1 and polynomial_2 multiply and we store the answer at linked list c,
						  everytime we multiply , we check the c to find the location of the result.*/
						while(c)
						{		
								//if their exponent is idential then we add this two coefficient
								if(c->expon == sum_expon)
								{
										sum_coef = sum_coef + c->coef;
										c->coef = sum_coef;
										previous = c;
										break;
								}
								//if the result's exponent is smaller than previous one, but bigger than current one, then we insert a node into the c.
								else if(c->expon < sum_expon && previous->expon > sum_expon)
								{
										insert = malloc(sizeof(*insert));
										insert->coef = sum_coef;
										insert->expon = sum_expon;
										insert->link = c;
										previous->link = insert;
										previous = c;
										break;
								}
								//if we arrived at the end, then we attach
								else if(c->expon > sum_expon && c->link == NULL)
								{
										attach_poly(sum_coef, sum_expon, &rear);
										rear->link = NULL;
										previous =  c;
										break;
								}
								
								previous = c;
								c = c->link;
						}
						c = start;
						p_b = p_b->link;
				}
				p_b = start_b;
				p_a = p_a->link;
		}
		return c;
}
