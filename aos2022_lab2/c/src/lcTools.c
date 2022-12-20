#include "../include/lc.h"

/*
    Amme Chan: function "countLines" is used to count lines.
*/
void countLines(char *fileName)
{
    char *fnType = strrchr(fileName, '.');
    if (fnType == NULL)
    {
        // no files
        // printf("errno %d: %s\n", errno, strerror(errno));
        printf("[ERROR] Not a text file: %s\n", fileName);
        return;
    }
    if ((flags & 8) && (strcmp(++fnType, suffix) != 0))
    {
        // no files matching the suffix requirements
        return;
    }

    FILE *fp;
    int c = '\n', row = 0, pre = 0;

    // try to open file
    // provides exception handling, such as unreadable file permissions
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("[ERROR %d] Failed to open file: %s\n", errno, fileName);
        exit(1);
    }
    // read the file and break when the file is complete

    while (!feof(fp))
    {
        pre = c;
        c = fgetc(fp);
        // if line is non-empty
        if (((!(flags & 2)) || (pre != '\n')) && (c == '\n'))
        {
            row++;
        }
    }
    // if last line is non-empty
    if (pre != '\n')
    {
        row++;
    }
    if (flags & 16)
    {
        pthread_mutex_lock(&printmutex);
        if (!(flags & 1))
        {
            printf("%4d\t%s\n", row, fileName);
        }
        totalFlies++;
        totalLines += row;
        pthread_mutex_unlock(&printmutex);
        free(fileName);
    }
    else
    {
        if (!(flags & 1))
        {
            printf("%4d\t%s\n", row, fileName);
        }
        totalFlies++;
        totalLines += row;
    }
    fclose(fp);
}

/*
    Amme Chan: function "dirAnalysis" is used to analyse dirtory
*/
void dirAnalysis(char *fileName)
{
    DIR *dir;
    char pn[255], *Pn;

    int len = strlen(fileName);
    if (fileName[len - 1] == '/')
        fileName[--len] = 0;

    if ((dir = opendir(fileName)) == 0)
    {
        // printf("errno %d: %s\n", errno, strerror(errno));
        printf("[ERROR %d] Failed to open directory: %s\n", errno, fileName);
        exit(1);
    }

    struct dirent *stdir;
    while (1)
    {
        if ((stdir = readdir(dir)) == 0)
        {
            break;
        }

        if (stdir->d_type == 8)
        {
            if (flags & 16)
            {
                Pn = (char *)malloc(sizeof(char) * (strlen(fileName) + 2 + strlen(stdir->d_name)));
                sprintf(Pn, "%s%c%s", fileName, '/', stdir->d_name);
                TaskNode *TN = (TaskNode *)malloc(sizeof(TaskNode));
                TN->do_task = &countLines;
                TN->arg = (void *)Pn;
                TN->next = NULL;

                pthread_mutex_lock(&mutex);

                // printf("inQueue: TN->arg_%s\n", (char *)TN->arg);
                inQueue(&Q, TN);

                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
            }
            else
            {
                // a regular file: stdir->d_type = 8
                sprintf(pn, "%s%c%s", fileName, '/', stdir->d_name);
                countLines(pn);
            }
        }
        else if ((flags & 4) && (stdir->d_type == 4) && (strcmp(stdir->d_name, ".") != 0) && (strcmp(stdir->d_name, "..") != 0))
        {
            // a directory file: stdir->d_type = 4
            sprintf(pn, "%s%c%s", fileName, '/', stdir->d_name);
            dirAnalysis(pn);
        }
    }
    closedir(dir);
}

/*
    Amme Chan: function "analysis" is used to analyse files.
*/
void analysis(char *fileName)
{
    // "buf" is used to obtain information about the file.
    struct stat buf;
    char *Pn;
    if (stat(fileName, &buf) < 0)
    {
        // printf("errno %d: %s\n", errno, strerror(errno));
        printf("[ERROR %d] Stat error.\n", errno);
        exit(1);
    }

    // "buf.st_mode" is used to get the file type info.
    if (S_ISREG(buf.st_mode))
    {
        if (flags & 16)
        {
            Pn = (char *)malloc(sizeof(char) * strlen(fileName) + 1);
            sprintf(Pn, "%s", fileName);
            TaskNode *TN = (TaskNode *)malloc(sizeof(TaskNode));
            TN->do_task = &countLines;
            TN->arg = (void *)Pn;
            TN->next = NULL;

            pthread_mutex_lock(&mutex);

            printf("inQueue: TN->arg_%s\n", (char *)TN->arg);
            inQueue(&Q, TN);

            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            // If it is a regular file, just go to count lines directly.
            countLines(fileName);
        }
    }
    else if (S_ISDIR(buf.st_mode))
    {
        // Else, analysis needs to continue.
        dirAnalysis(fileName);
    }
    else
    {
        // File type exception
        // printf("errno %d: %s\n", errno, strerror(errno));
        printf("[ERROR %d] File type is not a directory file or a regular file.\n", errno);
        exit(1);
    }
}