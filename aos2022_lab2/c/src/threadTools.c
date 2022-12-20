#include "../include/lc.h"

/*
    Amme Chan: define founctions for queue operation.
*/
int initQueue(TaskQueue *TQ)
{
    TQ->tail = TQ->head = (TaskNode *)malloc(sizeof(TaskNode));
    if (TQ->head == NULL)
        return 0;
    TQ->head->do_task = NULL;
    TQ->head->arg = NULL;
    TQ->head->next = NULL;
    return 1;
}

int inQueue(TaskQueue *TQ, TaskNode *TN)
{
    if (TN == NULL)
        return 0;
    TQ->tail = TQ->tail->next = TN;
    return 1;
}

TaskNode *deQueue(TaskQueue *TQ)
{
    if (TQ->head == TQ->tail)
    {
        return NULL;
    }
    TaskNode *TN = TQ->head->next;
    if (TN == NULL)
        return NULL;
    TQ->head->next = TN->next;
    if (TN->next == NULL)
    {
        TQ->tail = TQ->head;
    }
    return TN;
}

void destroyQueue(TaskQueue *TQ)
{
    while (TQ->head != TQ->tail)
    {
        TaskNode *TN = deQueue(TQ);
        if (TQ != NULL)
            free(TN);
    }
    free(TQ->head);
}

void *work(void *rank)
{
    // for checkint thread_cur
    long my_rank = (long)rank;

    TaskNode *my_task = Q.head;
    // printf("[WORK ]pthread_%ld: task_%ld\n", my_rank, (long)my_task);

    /*consumer*/
    while (1)
    {
        // get lock
        pthread_mutex_lock(&mutex);
        // prevents preemption
        // sleep(1);

        if (finished)
        {
            // if finish to parse commands input
            // printf("---------------finished to create pthread---------------\n");

            if (my_task == NULL)
            {
                pthread_mutex_unlock(&mutex);
                return NULL;
            }
            // dequeue my_task
            // printf("%d: deQueue\n", finished);
            my_task = deQueue(&Q);

            // unlock
            pthread_mutex_unlock(&mutex);
            // printf("[WORK ]Done pthread_%ld: task_%ld\n", my_rank, (long)my_task);

            if (my_task != NULL)
            {
                (*(my_task->do_task))(my_task->arg);
                // printf("[WORK ]From pthread_%ld: Task %s\n", my_rank, (char *)(my_task->arg));
                free(my_task);
            }
        }
        else
        {
            // if not finish to parse commands input
            // printf("---------------continue to create pthread---------------\n");

            /* Used to block the current thread and
            wait for another thread to wake it up: using pthread_cond_signal() or pthread_cond_broadcast */
            while (pthread_cond_wait(&cond, &mutex) != 0)
                ;

            // dequeue my_task
            // printf("%d: deQueue\n", finished);
            my_task = deQueue(&Q);

            // unlock
            pthread_mutex_unlock(&mutex);
            // printf("[WORK ]After deQueue, pthread_%ld: task_%ld\n", my_rank, (long)my_task);

            if (my_task != NULL)
            {
                (*(my_task->do_task))(my_task->arg);
                // printf("[WORK ]From pthread_%ld: Task %s\n", my_rank, (char *)(my_task->arg));
                free(my_task);
            }
        }
    }
}