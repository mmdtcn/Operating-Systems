/**
 * C program to list all files and sub-directories in a directory.
 */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


void listFiles(const char *path);

int main()
{
    // Directory path to list files
    char path[100];

    // Input path from user
    printf("Enter path to list files: ");
    scanf("%s", path);

    listFiles(path);

    return 0;
}


/**
 * Lists all files and sub-directories at given path.
 */
void listFiles(const char *path)
{
    struct dirent *dp;
    DIR *dir = opendir(path);

    // Unable to open directory stream
    if (!dir) 
        return; 

    while (//TODO: use readdir on the path. Assign the return value to the dp.) != NULL)
    {
        //TODO: print d->name part of the dp
    }

    // Close directory stream
    closedir(dir);
}
