#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// single lane road
// 2 threads (east & west ppl)
// only 1 thread can cross the road
// when traveling, sleep for random amount of time

pthread_t east[3];
pthread_t west[3];
pthread_mutex_t lock;
int counter, choose_dir, choose_action;

char actions[5][50] = {"is playing temple run.",
                       "is eating candy.",
                       "is texting their girlfriend.",
                       "is doing a handstand.",
                       "is feeding their dog."};

void* walk(void* arg){
    // lock the road
    pthread_mutex_lock(&lock);

    // randomly choose an action between 5 and 0
    choose_action = rand()%((5+1)-1) + 0;
    int wait_time = rand()%((50+1)-1) + 1;

    // depending on the direction, choose the following string outputs
    // also choose the random action
    if (choose_dir == 1){
        printf("East village %d is traveling on the road.\n", counter);
        usleep(wait_time);
        printf("East village %d %s\n", counter, actions[choose_action]);
        printf("East village %d finished crossing the road.\n",counter);
    } else if (choose_dir == 2){
        printf("West village %d has started its journey.\n", counter);
        usleep(wait_time);
        printf("Wast village %d %s\n", counter, actions[choose_action]);
        printf("West village %d finished the exchange.\n",counter);
    }
    printf("--------------------------------------------\n");

    // unlock the thread
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void) {
    // create a random seed
    srand(time(NULL));
    int error_east, error_west;

    // initialize the mutex and alert the user if it fails
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init has failed\n");
        return 1;
    }

    int i = 0;
    while (i != 100) {
        // choose a random people # in east/west
        counter = rand()%((3+1)-1) + 1;

        // choose randomly between east/west and join the thread
        // prevent deadlock by creating 1 thread at a time
        // and locking the mutex
        choose_dir = rand()%((2+1)-1) + 1;
        if (choose_dir == 1) {
            error_east = pthread_create(&east[counter], NULL, &walk, NULL);
            pthread_join(east[counter], NULL);
        } else if (choose_dir == 2) {
            error_west = pthread_create(&west[counter], NULL, &walk, NULL);
            pthread_join(west[counter], NULL);
        }
        i++;
    }
    return 0;
}