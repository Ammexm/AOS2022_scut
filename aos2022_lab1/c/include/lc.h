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
	Amme: about lab_1
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
