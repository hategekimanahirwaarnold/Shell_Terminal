
#include "main.h"

int _bin(char *path, char **p, char *duplicate)
{
    char initial_path[20] = "/bin/";
    int k;
    pid_t child;
    int status, exit_status;

    child = fork();

    if (child == -1)
    {
        perror("Can't create a child process\n");
        return(-1);
    } else if (child == 0)
    {
        if ((k = execve(path, p, environ)) == -1)
        {
            perror("./shell");
            exit(-1);
        }
        else
        {
            printf("k is: %d\n", k);
            exit(0);
        }
    } else
    {
        wait(&status);
        free(duplicate);
        free(p);
        p = NULL;
        _strcpy(initial_path, "/bin/");
        if (WIFEXITED(status))
        {
            exit_status = WEXITSTATUS(status);
            if (exit_status == 0)
            {
                return 1;
            }
            return -1;
        }
        return -1;
    }

}
