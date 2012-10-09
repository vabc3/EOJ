#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void rand_init()
{
	srand(time(NULL));
}

int rand_n(int n)
{
	return rand()%n;
}


int main()
{
	rand_init();
	int i=0;
	for(i=0;i<20;i++){
		printf("%d\n",rand_n(5));
	}
}
