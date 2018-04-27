#include <stdio.h>
#include <pthread.h>

int array[1000];

void* sum(void* arg)
{
	//printf("\nargument is: %d", (int *)arg);
	int temp = (int *)arg;
	temp = temp * 100;
	int i = temp;
	//printf("\ni: %d", i);
	int j = temp + 100;
	//printf("\nj: %d", j);
	int sum = 0;
	for(i; i<j; i++)
	{	
		sum += array[i];
	}
	printf("\nSum is %d",sum);
	return sum;
}

int main()
{
	int i = 0;
	for(i; i<1000; i++)
	{
		array[i]=i+1;
	}

	pthread_t tid[10];	
	int j = 0;
	int *p = 0;
	int TotalSum=0;
	
	for(j; j<10; j++)
	{
		pthread_create(&tid[j], NULL, sum, j);
	}
	
	j = 0;
	for(j; j<10; j++)
	{
		// here i'm unable to handle the returned value of function sum
		pthread_join(tid[j], (void *)p);
		//printf("\nSum is %d", (int *)p);
		TotalSum += (int *)p;
	}
	printf("\n\n\nSum of 1st 1000 numbers is: %d", TotalSum);
	
	return 0;
}
