#include <stdio.h>
void shift(int *a,int *b,int *c)
{
	int term = *c;
	*c = *b;
	*b = *a;
	*a = term;
} 
void main()
{
	int x=5,y=8,z=10;
	printf("x=%d,y=%d,z=%d\n",x,y,z);
	shift(&x,&y,&z);
	printf("x=%d,y=%d,z=%d\n",x,y,z);
}
