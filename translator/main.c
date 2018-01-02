#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORDMAXLENGTH 19
#define MAX (WORDMAXLENGTH + 1) // Add space for a '\0'
#define MAXWORDS 50 // The max number of English words

int main()
{

    void populateDictionary(char etbl[][MAX],char ftbl[][MAX],int* wordpairs,
                           int maxwords); 
    void printDictionary(char etbl[][MAX],char ftbl[][MAX],int pairs); 
    char english[MAXWORDS][MAX],finnish[MAXWORDS][MAX];
    int wordpairs = 0;
    populateDictionary(english,finnish,&wordpairs,MAXWORDS); 
    printDictionary(english,finnish,wordpairs); 
    return 0;
}
//------------------------------ populateDictionary ------------------------------  
void populateDictionary(char etbl[][MAX],char ftbl[][MAX],int* wordpairs,
                       int maxwords) {
    /*This function asks for 'English word - Finnish word'-pairs and fills them 
     * into the arrays of the main. The total number of pairs must not exceed
     * maxwords. The final number of word pairs is returned to the calling 
     * function.*/

    int targetIndex(char etbl[][MAX], char key[],int wordpairs);
    void addNewWords(char etbl[][MAX],char ftbl[][MAX],char ew[],char fw[],int index,int* wordpairs);
    int newIndex;
    char ew[MAX],fw[MAX];
    while(*wordpairs<maxwords) {
        printf("Enter an English word or 'stop' to terminate: ");
        scanf("%s",ew);
        // strcmp returns '0' when the strings are the same.
        if(!strcmp(ew,"stop")) break; // Exit while loop when 'stop'
        printf("Enter the Finnish word for '%s': ",ew);
        scanf("%s",fw);
        newIndex = targetIndex(etbl,ew,*wordpairs);
        addNewWords(etbl,ftbl,ew,fw,newIndex,wordpairs);
        printf("wordpairs = %d, newIndex = %d, %s = %s\n",*wordpairs,newIndex,ew,fw);
    }
    return;
}
//------------------------------ printDictionary ------------------------------  
void printDictionary(char etbl[][MAX],char ftbl[][MAX],int pairs) {
    int i;
    printf("\n%d word pairs. The contents of the dicrionary are as follows:\n",
            pairs);
    for(i=0;i<pairs;i++) {
        printf("%s = %s\n",etbl[i],ftbl[i]);
    }
    return;
}

//----------------------------- targetIndex------------------------------  
int targetIndex(char etbl[][MAX], char key[],int wordpairs) {
    /* This function finds out the target index in the etbl for the new
     * entry key. The target index is selected so, that the words in the
     * etbl will be in the alphabetical order also once the 'key' has been 
     * inserted into it.*/
   int k = 0; // The index to the etbl.
   if(wordpairs == 0) { // This will be the first element of the etbl.
       k = 0;
   } else {
       while(k< wordpairs && strcmp(etbl[k],key) < 0) {
           k++; // Pass by the elements, which are smaller than key.
       }
   }
   return k;
}
//------------------------------ addNewWords------------------------------------  
void addNewWords(char etbl[][MAX],char ftbl[][MAX],char ew[],char fw[],int index,
                int* wordpairs) {
    /* This function adds a new english word ew into the etbl and the correspon-
     * ding finnish word fw into the ftbl. The index of the new entry is index.
     * Before the new entry can be added all the existing elements from index
     * to the end of the array must be shifted one position to the right. This
     * will create an empty vacancy for the new entry. Once the new entry has been
     * added the number of wordpairs must be incremented by one. */

    int i;
    for(i=*wordpairs-1;i>=index;i--) { // Shift right all the existing elements
        strcpy(etbl[i+1],etbl[i]);     // from index to the end of the arrays.
        strcpy(ftbl[i+1],ftbl[i]);
    }
    strcpy(etbl[index],ew);
    strcpy(ftbl[index],fw);
    (*wordpairs)++;
    return;
}

