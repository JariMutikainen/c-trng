#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX (40 + 1) // Reserve space for 40 chars + '\0'

int main()
    /*This program asks the user for a phrase. It tells if the phrase is a 
     * palindrome. To end the program enter an empty line.*/
{
    char phrase[MAX],forwards[MAX],backwards[MAX];

    while(1) {
        int i = 0, f = 0, b = 0;
        int diffFound = 0;
        printf("Enter a phrase or enter an empty line to terminate\n");
        if(gets(phrase) == NULL) return 0;
        if(strlen(phrase) < 2) return 0;
        while(phrase[i] != '\0') {
            if(isalpha(phrase[i])) forwards[f++] = tolower(phrase[i]);
            i++;
        }
        forwards[f] = '\0';
        // At this point f contains the number of letters in forwards[]
        while(forwards[b] != '\0') {  
                backwards[b] = forwards[f-b-1];  // Reverse the order of the chars.
                b++;
        }
        backwards[b] = '\0';
        // At this point f still contains the number of letters in forwards[]
        b=0;
        while(b <= f) {
            if(forwards[b] != backwards[b]) {
                diffFound = 1;
            }    
            b++;
        }
        if(diffFound) printf("Not a palindrome.\n");
        else printf("It is a palindrome.\n");
    }

    return 0;
}
