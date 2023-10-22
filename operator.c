#include "main.h"

/**
 * handle_and_or_true - Handle AND or OR operations with true condition
 * @or: The original command string
 * @x: The logical operator and the following command
 * @and: If true, it's a logical AND operation; otherwise, it's a logical OR operation
 */
void handle_and_or_true(char *or, char *x, bool and)
{
    char *compute, *new_str;
    int n, result;

    compute = malloc(strlen(or) - strlen(x) + 2);
    strncpy(compute, or, strlen(or) - strlen(x));
    result = exec_command(compute);

    new_str = malloc(strlen(x) - 1);
    for (n = 0; x[n + 2] != '\0'; n++)
    {
        new_str[n] = x[n + 2];
    }
    new_str[n] = '\0';

    if (and)
    {
        if (result == -1)
            _operator(false, new_str, false, false);
        else
            _operator(true, new_str, false, false);
    }
    else
    {
        if (result == -1)
            _operator(true, new_str, false, false);
        else
            _operator(false, new_str, false, true);
    }

    // free(compute);
    // free(new_str);
}

/**
 * _operator - Handle logical AND and OR operations
 * @doIt: Indicates whether to execute the command
 * @string: The input string
 * @start: Indicates if it's the start of a logical operation
 * @wasOr: Indicates if the previous logical operation was an OR operation
 */

void _operator(bool doIt, char *string, bool start, bool wasOr)
{
    char *new_str = NULL, *compute = NULL, *or;
    char *x = strstr(string, "&&");
    char *y = strstr(string, "||");
    int n, result;
    unsigned long int w = (unsigned long int)x;
    unsigned long int z = (unsigned long int)y;

    if (((w < z) && w != 0) ||(w && z == 0))
    {
      
        if (start == true || (doIt == true))
        {
            or = malloc(sizeof(string));
            or = strdup(string);
            handle_and_or_true(or, x, true);
        } else
        {
            new_str = malloc(strlen(x));
            for (n = 0; n < (_strlen(x) - 2); n++)
            {
                new_str[n] = x[n + 2];
            }
            new_str[n] = '\0';
            _operator(wasOr? true : false, new_str, false, false);
        }

    } else if (((z < w) && z != 0) || (z && w == 0))
    {
        if ((doIt == true) || start == true)
        {
            or = malloc(sizeof(string));
            or = strdup(string);
            handle_and_or_true(or, y, false);
        } else 
        {
            new_str = malloc(strlen(y));
            for (n = 0; n < (_strlen(y) - 2); n++)
            {
                new_str[n] = y[n + 2];
            }
            new_str[n] = '\0';
                _operator(wasOr? false : true, new_str, false, true);
        }
            
    } else
    {
        if (doIt == true && wasOr == false)
            exec_command(string);
    }
}

// /**
//  * _operator - Handle logical AND and OR operations
//  * @doIt: Indicates whether to execute the command
//  * @string: The input string
//  * @start: Indicates if it's the start of a logical operation
//  * @wasOr: Indicates if the previous logical operation was an OR operation
//  */
// void _operator(bool doIt, char *string, bool start, bool wasOr)
// {
//     char *new_str = NULL, *compute = NULL, *or = NULL;
//     char *x = strstr(string, "&&");
//     char *y = strstr(string, "||");
//     int n, result;
//     unsigned long int w = (unsigned long int)x;
//     unsigned long int z = (unsigned long int)y;

//     if ((w < z && w != 0) || (w && z == 0))
//     {
//         if (start == true || doIt == true)
//         {
//             or = strdup(string);
//             handle_and_or_true(or, x, true);
//             free(or);
//         }
//         else
//         {
//             new_str = malloc(strlen(x));
//             for (n = 0; n < (_strlen(x) - 2); n++)
//             {
//                 new_str[n] = x[n + 2];
//             }
//             new_str[n] = '\0';
//             _operator(wasOr ? true : false, new_str, false, false);
//         }
//     }
//     else if ((z < w && z != 0) || (z && w == 0))
//     {
//         if (doIt == true || start == true)
//         {
//             or = strdup(string);
//             handle_and_or_true(or, y, false);
//             free(or);
//         }
//         else
//         {
//             new_str = malloc(strlen(y));
//             for (n = 0; n < (_strlen(y) - 2); n++)
//             {
//                 new_str[n] = y[n + 2];
//             }
//             new_str[n] = '\0';
//             _operator(wasOr ? false : true, new_str, false, true);
//         }
//     }
//     else
//     {
//         if (doIt == true && !wasOr)
//         {
//             exec_command(string);
//         }
//     }
//     free(new_str);
// }
