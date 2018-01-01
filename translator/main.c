#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDMAXLENGTH 19
#define MAX (WORDMAXLENGTH + 1) // Add space for a '\0'
#define WORDS 50 // The max number of English words

int main()
{
    char ew[MAX],fw[MAX];
    char english[WORDS][WORDMAXLENGTH],finnish[WORDS][WORDMAXLENGTH];
    int i = 0;
    while(1) {
        printf("Enter an English word or 'stop' to terminate: ");
        scanf("%s",ew);
        // strcmp returns '0' when the strings are the same.
        if(!strcmp(ew,"stop")) break; // Exit while loop when 'stop'
        printf("Enter the Finnish word for '%s': ",ew);
        scanf("%s",fw);

        printf("%s = %s\n",ew,fw);
    }
    return 0;
}
