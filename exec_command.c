#include "main.h"

int exec_command(char *original)
{
    char *path, *tok, *dup, *duplicate, *token, **p, **arr;
    char initial_path[20] = "/bin/";
    int i, n,k;
    pid_t child;
    int status, exit_status;
    char sep[] = "\n ";

    duplicate = strdup(original);
    token = _strtok(duplicate, sep);
    if (token == NULL)
    {
        free(duplicate);
            return(-1);
    }
    path = malloc(strlen(token) + strlen(initial_path) + 1);
    if (strchr(token, '/') == NULL)
    {
        k = find_function(token, original);
        if (k == 0)
            return(0);
        strcat(initial_path, token);
        path = initial_path;
    } else
        path = (token);
    p = malloc(sizeof(char *) * (strlen(original) + 1));
    if (p == NULL)
    {
        perror("Memory allocation failed\n");
        free(duplicate);
        free(path);
        return(-1);
    }
    p[0] = path;
    for (i = 1; (token = _strtok(NULL, sep)) != NULL; i++)
    {
        p[i] = token;
    }
    p[i] = NULL;

    // printf("Path: **%s**\n", p[0]);
    // if (p[0] != NULL)
    // {
    //     for (i = 0; p[i]; i++)
    //     {
    //         printf("p[%d]: **%s**\n", i, p[i]);
    //     }
    // } else
    // {
    //     printf("No arguments\n");
    // }

    return (_bin(path, p, duplicate));

}
