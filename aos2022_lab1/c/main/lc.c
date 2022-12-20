#include "../include/lc.h"
/*
    Amme: about lab_1
        define global variable
        define "main" function to parse command
*/

// define long chioce
static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"all", no_argument, NULL, 'A'},
    {"suffix", required_argument, NULL, 's'},
    {0, 0, 0, 0}};
// define shortopts: -s val, which requires an associated value
char shortopts[] = "Abhrs:";

// string that points to the current option
char *optarg;
// index of the next element to be processed in argv, initialize to 1
int optind;
// error message printing flag
int opterr;
// contains an invalid option character found
int optopt;

// flags used to mark options
unsigned char flags;
// suffix used to mark
char *suffix;
//	to mark lines of file and nums of files
int totalLines, totalFlies;

int main(int argc, char *argv[])
{
    int index = 0, optc = 0;
    char *filename;
    while (EOF != (optc = getopt_long(argc, argv, shortopts, long_options, &index)))
    {

        // optc = getopt_long(argc, argv, shortopts, long_options, &index);
        // if (optc == -1)
        //     break;

        switch (optc)
        {
        case 'A':
            flags |= 1;
            break;
        case 'b':
            flags |= 2;
            break;
        case 'h':
            printf("Usage: lc [OPTION] ... [FILE | DIR] ...\n"
                   "Print newline counts for each FILE or DIR, and a total line if more than one FILE is specified.\n\n"
                   "With no FILE, or when FILE is -, read standard input.\n\n"
                   "The options below may be used to control print msg\n"
                   "\t-A, --all                     print the total line number only\n"
                   "\t-b                            ignore the Blank line when counting\n"
                   "\t-r                            count directory Recursively\n"
                   "\t-s, --suffix=FILE-SUFFIX    only count the file with specified Suffix\n"
                   "\t-h, --help                    display this Help and exit\n");
            exit(0);
            break;
        case 'r':
            flags |= 4;
            break;
        case 's':
            flags |= 8;
            suffix = optarg;
            break;
        case '?':
            // printf("errno %d: %s\n", errno, strerror(errno));
            printf("[ERROR] Unknown options.\n");
            break;
        default:
            break;
        }
    }

    index = optind;

    if (index < argc)
    {
        // print table headers of output
        printf("line\tfile\n"
               "----\t----\n");
        // In C, 0 means no error
        while (index < argc)
        {
            filename = argv[index++];
            analysis(filename);
        }

        if (totalFlies == 0 && totalLines == 0)
        {
            printf("[ERROR] The input is an empty directory.\n");
        }
        if (totalFlies > 1)
        {
            printf("%4d\t"
                   "total\n",
                   totalLines);
        }
        else if (totalFlies == 1 && (flags & 1))
        {
            printf("%4d\t"
                   "%s\n",
                   totalLines, filename);
        }
    }
    else
    {
        printf("[ERROR %d] No directory file or regular file entered.\n", errno);
        exit(1);
    }
    return 0;
}