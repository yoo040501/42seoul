#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void	*test(void *arg)
{
	for (int i=0;i<10;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	return 0;
}
 
int	main(void)
{
	pthread_t	threads[2];
	int			sts;

	sts = pthread_create(&threads[0], NULL, test, NULL);
	pthread_join(threads[0], NULL);
	//sleep(3);             
	return (0);
}
