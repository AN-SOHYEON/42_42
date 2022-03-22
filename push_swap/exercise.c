#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int        main(int argc, const char *argv[])
{
    char    *tabstr1;
    char    *tabstr2;
    char    *tabstr3;
    char    *tabstr4;
    char    *tabstr5;
    int        i;
    printf("1\n");
    i = 0;
    tabstr1 = ft_split("          ", ' ');
    while (tabstr1[i] != NULL)
    {
        printf("    %s\n", tabstr1[i]);
        i++;
    }
    printf("\n\n");
    printf("2\n");
    i = 0;
    tabstr2 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    while (tabstr2[i] != NULL)
    {
        printf("    %s\n", tabstr2[i]);
        i++;
    }
    printf("\n\n");
    printf("3\n");
    i = 0;
    tabstr3 = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
    while (tabstr3[i] != NULL)
    {
        printf("    %s\n", tabstr3[i]);
        i++;
    }
    printf("\n\n");
    printf("4\n");
    i = 0;
    tabstr4 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    while (tabstr4[i] != NULL)
    {
        printf("    %s\n", tabstr4[i]);
        i++;
    }
    printf("\n\n");
    printf("5\n");
    i = 0;
    tabstr5 = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
    while (tabstr5[i] != NULL)
    {
        printf("    %s\n", tabstr5[i]);
        i++;
    }
    printf("\n\n");
    return (0);
}