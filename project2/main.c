#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define PHIL_COUNT 5

// Define philosophers threads and mutexs & init the chopsticks
pthread_t philosophers[PHIL_COUNT];
pthread_mutex_t mutex_chopsticks = PTHREAD_MUTEX_INITIALIZER;; 
int chopsticks[PHIL_COUNT];

void init()
{
	for(int i = 0; i < PHIL_COUNT; i++) {
		chopsticks[i] = 0;
	}
}

void philosopher(int i)
{
	long int wait_time, eat_time;
	int right = i;
	int left = (i - 1 == -1) ? PHIL_COUNT - 1 : (i - 1);	
	int flag;	

	while(1){
		flag = 0;
		while(!flag) {
			// lock the mutex to 1 thread (philosopher)
			pthread_mutex_lock(&mutex_chopsticks);

			// check if 1 chopstick is picked up
			if (chopsticks[right] || chopsticks[left]) {
				// unlock it for another philosopher
				pthread_mutex_unlock(&mutex_chopsticks); // give up either chopstick unless both are available
				printf("Philosopher #%d can't use both chopsticks. Giving up and thinking.\n", i+1);
				
				wait_time = random() % 1000;
				usleep(wait_time); // wait/think for a random amount of time
				
				continue;											
			}

			printf("Philosopher #%d pondered for %ld seconds.\n",i+1, wait_time);
			// otherwise, pick up both, and lock the chopsticks
			chopsticks[left] = 1;
			chopsticks[right] = 1;
			
			// unlock for another potential philosopher
			pthread_mutex_unlock(&mutex_chopsticks);
			flag = 1;
		}

		printf("Philosopher #%d took both chopsticks. Now eating.\n", i+1);
		eat_time = random() % 1000;
		usleep(eat_time);
		printf("Philosopher #%d ate for %ld seconds. Releasing chopsticks.\n", i+1, eat_time);
		pthread_mutex_lock(&mutex_chopsticks); // give up chopsticks
		
		// reset chopsticks = not held
		chopsticks[left] = 0;
		chopsticks[right] = 0;
		pthread_mutex_unlock(&mutex_chopsticks);
		usleep(random() % 1000);
		
		// sleep for easier output reading
		sleep(2);
	}
}

int main()
{
	init();
	int i;
	
	// Create 1 thread per philosopher
	for(i = 0; i < PHIL_COUNT; i++) {
		pthread_create(&philosophers[i], NULL, philosopher, (void*)i);
	}
	
	// Wait for the target thread to terminate
	for(i = 0; i < PHIL_COUNT; i++){

		pthread_join(philosophers[i],NULL);
	}

	return 0;
} 
