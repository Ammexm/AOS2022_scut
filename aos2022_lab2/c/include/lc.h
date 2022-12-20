#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <getopt.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>
#include <errno.h>

/*
    Amme: about lab_2
        define the header files
        define related functions
*/

// string that points to the current option
extern char *optarg;
// index of the next element to be processed in argv, initialize to 1
extern int optind;
// error message printing flag
extern int opterr;
// contains an invalid option character found
extern int optopt;

// define thread params.
extern int thread, finished, ret;
// extern struct TaskNode;
// extern struct TaskQueue;
typedef struct TaskNode
{
    void *(*do_task)(void *arg);
    void *arg;
    struct TaskNode *next;
} TaskNode;
// thread queue
typedef struct TaskQueue
{
    TaskNode *head;
    TaskNode *tail;
} TaskQueue;
// add them for extren
// extern TaskNode;
// extern TaskQueue;
extern TaskQueue Q;
extern pthread_mutex_t mutex, printmutex;
extern pthread_cond_t cond;

// flags used to mark options
extern unsigned char flags;
// suffix used to mark
extern char *suffix;
//	to mark lines of file and nums of files
extern int totalLines;
extern int totalFlies;

// define function "fileAnalysis" used to analyse files
void analysis(char *fileName);
// define function "dirAnalysis" used to analyse dirtory
void dirAnalysis(char *fileName);
// define function "countLines" used to count lines
void countLines(char *fileName);

// functions for thread operation
extern void *work(void *rank);
extern int initQueue(TaskQueue *TQ);
extern int inQueue(TaskQueue *TQ, TaskNode *TN);
extern TaskNode *deQueue(TaskQueue *TQ);
extern void destroyQueue(TaskQueue *TQ);
