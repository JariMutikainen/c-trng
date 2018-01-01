#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDMAXLENGTH 19
#define MAX (WORDMAXLENGTH + 1) // Add space for a '\0'
#define MAXWORDS 50 // The max number of English words

int main()
{

    int populateDictionary(char etbl[][MAX],char ftbl[][MAX],int maxwords); 
    void printDictionary(char etbl[][MAX],char ftbl[][MAX],int pairs); 
    char english[MAXWORDS][MAX],finnish[MAXWORDS][MAX];
    int wordpairs = populateDictionary(english,finnish,MAXWORDS); 
    printDictionary(english,finnish,wordpairs); 
    return 0;
}
//------------------------------ populateDictionary ------------------------------  
int populateDictionary(char etbl[][MAX],char ftbl[][MAX],int maxwords) {
    /*This function asks for 'English word - Finnish word'-pairs and fills them 
     * into the arrays of the main. The total number of pairs must not exceed
     * maxwords. The final number of word pairs is returned to the calling function.*/


    char ew[MAX],fw[MAX];
    int i = 0;
    while(i<maxwords) {
        printf("Enter an English word or 'stop' to terminate: ");
        scanf("%s",ew);
        // strcmp returns '0' when the strings are the same.
        if(!strcmp(ew,"stop")) break; // Exit while loop when 'stop'
        printf("Enter the Finnish word for '%s': ",ew);
        scanf("%s",fw);
        strcpy(etbl[i],ew);
        strcpy(ftbl[i],fw);
        i++;

        printf("%s = %s\n",ew,fw);
    }
    return i;
}
//------------------------------ printDictionary ------------------------------  
void printDictionary(char etbl[][MAX],char ftbl[][MAX],int pairs) {
    int i;
    printf("\nThe contents of the dicrionary are as follows:\n");
    for(i=0;i<pairs;i++) {
        printf("%s = %s\n",etbl[i],ftbl[i]);
    }
    return;
}
