
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t printer;

void* printJob(void* arg)
{
    int user = *(int*)arg;

    printf("User %d is waiting for the printer.\n", user);

    sem_wait(&printer);

    printf("User %d allocated the printer.\n", user);
    printf("User %d is printing...\n", user);

    sleep(1);

    printf("User %d released the printer.\n\n", user);

    sem_post(&printer);

    return NULL;
}

int main()
{
    pthread_t users[3];
    int id[3] = {1, 2, 3};

    sem_init(&printer, 0, 1);

    printf("SHARED PRINTER MANAGEMENT\n\n");

    for(int i = 0; i < 3; i++)
    {
        pthread_create(&users[i], NULL, printJob, &id[i]);
    }

    for(int i = 0; i < 3; i++)
    {
        pthread_join(users[i], NULL);
    }

    sem_destroy(&printer);

    printf("All printing jobs completed.\n");

    return 0;
}
