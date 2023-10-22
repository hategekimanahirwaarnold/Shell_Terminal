#include "main.h"

void add_dir(location* link,char *path)
{
    location* current;
    location* tmp;
    char *opened_dir;
    // printf("No problem while opening: %s, (in environ: %s) \n", path, _getenv("PWD"));
    // if (_strcmp(_getenv("PWD"), path) == 0)
    // {
        // printf("the same dir!\n");
    //     return;
    // }
    if (link == NULL)
    {
        perror("invalid link");
        return;
    }
    current = link;
    // printf("\nThis should equal the beginning chain\n");
    while (current != NULL)
    {
        // printf("%s\n", current->path);
        current = current->next;
    }
    current = link;
    while (current->next != NULL)
    {
        // printf("%s\n", current->path);
        current = current->next;
    }
    tmp = malloc(sizeof(location));
    if (tmp == NULL)
    {
        perror("malloc tmp");
        return;
    }
    opened_dir = strdup(path);
    tmp->dir = opendir(opened_dir);
    if (tmp->dir == NULL)
    {
        perror("tmp->dir");
        exit(98);
    }
    tmp->path = opened_dir;
    tmp->next = NULL;
    current->next = tmp;
    // printf("\nnew chain => \n\n");
    current = link;
    while (current != NULL)
    {
        // printf("%s\n", current->path);
        current = current->next;
    }
}