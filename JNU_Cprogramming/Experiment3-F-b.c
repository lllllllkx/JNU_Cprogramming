#include <stdio.h>
#include <math.h>

void calculation(int a,int b,int c,int d,int e,int *sum,float *ave,float *stddev)
{
	int arr[]={a,b,c,d,e};
	*sum = 0;
	int i;
	float n;
	for(i=0;i<5;i++)
	{
		*sum += arr[i];
	}
	*ave = *sum * 1.0 / 5.0;
	
	for(i=0;i<5;i++)
	{
		n += (arr[i] - *ave) * (arr[i] - *ave);
	}
	n /= 5.0;
	*stddev = sqrt(n);
}
int main()
{
	int n1,n2,n3,n4,n5;
	printf("Enter five integers");
	scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
	int sum;
	float ave,stddev;
	calculation(n1,n2,n3,n4,n5,&sum,&ave,&stddev);
	printf("sum = %d\n",sum);
	printf("average = %f\n",ave);
	printf("standard deviation = %f\n",stddev); 
}
