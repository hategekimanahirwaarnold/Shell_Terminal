#include "main.h"

location* linked_dir()
{
    char *token;
    char *env = _getenv("PWD");
    DIR *dir = opendir("/");
    location *current, *head, *tmp;
    char curr_path[1024] = "";
    
    head = malloc(sizeof(location));
    if (head == NULL)
    {
        perror("Can't initiate memory location of the head node");
        kill(getpid(), SIGINT);
    }
    if (dir == NULL)
    {
        perror("Can't open the root directory\n");
        kill(getpid(), SIGINT);
    }
    head->dir = dir;
    head->path = env;
    head->next = NULL;
    // token = _strtok(env, "/");

    // for (current = head; token != NULL; token = _strtok(NULL, "/"))
    // {
    //     tmp = malloc(sizeof(location));
    //     if (tmp == NULL)
    //     {
    //         perror("Can't initiate memery for tmp!");
    //         exit(98);
    //     }
    //     _strcat(curr_path, "/");
    //     _strcat(curr_path, token);
    //     // printf("Here is the current path %s\n", curr_path);

    //     tmp->dir = opendir(curr_path);
    //     if (tmp->dir == NULL)
    //     {
    //         dprintf(2, "Can't open directory: %s\n", curr_path);
    //         exit(98);
    //     }
    //     tmp->path = curr_path;
    //     tmp->next = NULL;
    //     current->next = tmp;
    // }
    // current = head;
    // while (current != NULL)
    // {
    //     printf("%s\n", current->path);
    //     current = current->next;
    // }
    return(head);
}
