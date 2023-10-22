#include "main.h"


void _chdir(char *buf)
{
    char *sep = "\n ", *home, *new_pwd;
    char *path = _strtok(buf, sep), cwdir[1024] = "";
    static int num = 0;
    int changed;
    static location *dirs;
    location *current = NULL;

    path = _strtok(NULL, sep);
    if (num == 0)
    {
        // printf("dirs is null\n");
        dirs = malloc(sizeof(location));
        dirs = linked_dir();
        // printf("start path: %s\n", dirs->path);
        num++;
    }
    current = dirs;
    // printf("\n**** beginning chain: => \n");
    while (current != NULL)
    {
        // printf("%s\n", current->path);
        current = current->next;
    }
    if (path == NULL)
    {
        if (strcmp(_getenv("PWD"), _getenv("HOME")) == 0)
            return;
        _setenv("PWD", _getenv("HOME"), 1);
        changed = chdir(_getenv("HOME"));
        if (changed == -1)
        {
            perror("bash cd:");
            return;
        }
        getcwd(cwdir, 1024);
        // printf("cwdir (in home): %s\n", cwdir);
        add_dir(dirs, cwdir);
    } else if (_strcmp(path, "-") != 0)
    {
        // printf("We are in any path section: %s\n", path);
        // printf("\n***** before calling add_dir fx: => \n");
        while (current != NULL)
        {
            // printf("%s\n", current->path);
            current = current->next;
        }
        _strcat(cwdir, _getenv("PWD"));
        _strcat(cwdir, "/");
        _strcat(cwdir, path);
        current = dirs; 

        changed = chdir(cwdir);
        if (changed == -1)
        {
            perror("bash: cd");
            return;
        }
       
        _setenv("PWD", getcwd(cwdir, 1024), 1);
        // printf("The new pwd: %s\n", cwdir);
        // printf("There is no problem here\n");
      
        add_dir(dirs, cwdir);
    } else
    {
        // printf("We are in - section\n");
        current = dirs;
        while(current->next->next != NULL) 
        {
            current = current->next;
        }
        _setenv("PWD", current->path, 1);
        // printf("new env: %s\n", _getenv("PWD"));
        add_dir(dirs, _getenv("PWD"));
        changed = chdir(current->path);
        if (changed == -1)
        {
            perror("bash: cd");
            return;
        }
    }
}