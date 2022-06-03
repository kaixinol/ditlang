#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char** split(char **arr, char *str, const char *del);
char** split(char **arr, char *str, const char *del)
{
    char *s =NULL;
    s=strtok(str,del);
    printf("LIB address=%llu\n",(unsigned long long)s);
    int i=0;
    while(s != NULL)
    {
        arr[i]=(char*)malloc(sizeof(char)*strlen(s));
        i++;
        *arr++ = s;
        printf("PTR %llu\n",(unsigned long long)&arr[i]);
        s = strtok(NULL,del);
    }
    return &arr[0];
}
