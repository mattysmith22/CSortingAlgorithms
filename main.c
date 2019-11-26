#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* helpmsg = "USAGE\n"
                "bubble\n"
                "betterbubble\n"
                "insertion\n"
                "merge\n"
                "quick\n"
                "cocktail (also known as shuttle)\n"
                "selection\n";

void (*getfunc(char *strin))(int[], int);
void printhelp();

int main(int argc, char** argv)
{
    int i, *arr;
    void (*sortfunc)(int[], int);
    char *cptr;
    if(argc < 3)
        printhelp();
    
    if(!(sortfunc = getfunc(argv[1])))
        printhelp();
    
    arr = malloc((argc - 2)*sizeof(int));
    for(i = 0; i < argc - 2; i++)
    {
        arr[i] = strtol(argv[i + 2], &cptr, 10);
        if(*cptr != '\0')
        {
            fprintf(stderr,"Error: number at element %d [%s] cannot be parsed\n", i + 1, argv[i + 2]);
            return 2;
        }
    }

    sortfunc(arr, argc-2);
    for(i = 0; i < argc - 2; i++)
        printf("%d\n", arr[i]);
    free(arr);
    
    return 0;
}

void (*getfunc(char *strin))(int[], int)
{
    if(strcmp(strin, "bubble")==0)
        return bubble_sort;
    else if(strcmp(strin, "betterbubble")==0)
        return better_bubble_sort;
    else if(strcmp(strin, "insertion")==0)
        return insertion_sort;
    else if(strcmp(strin, "merge")==0)
        return merge_sort;
    else if(strcmp(strin, "quick")==0)
        return quick_sort;
    else if(strcmp(strin, "cocktail")==0)
        return cocktail_sort;
    else if(strcmp(strin, "shell")==0)
        return shell_sort;
    else if(strcmp(strin, "selection")==0)
        return selection_sort;
    else
        return NULL;
}

void printhelp()
{
    fprintf(stderr, "%s", helpmsg);
    exit(1);
}