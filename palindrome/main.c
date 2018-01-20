#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX (40 + 1) // Reserve space for 40 chars + '\0'

int main()
    /*This program asks the user for a phrase. It tells if the phrase is a 
     * palindrome. To end the program enter an empty line.*/
{
    void trimArray(const char* p, char* f);
    void reverseArray(const char* f, char* r);
    int isPalindrome(const char* f, const char* r);
    char phrase[MAX],forwards[MAX],backwards[MAX];

    while(1) {
        printf("Enter a phrase or enter an empty line to terminate\n");
        if(gets(phrase) == NULL) return 0;
        if(strlen(phrase) < 2) return 0;

        trimArray(phrase,forwards);
        printf("phrase = %s, forwards = %s\n",phrase,forwards);
        reverseArray(forwards, backwards);
        printf("phrase = %s, forwards = %s backwards = %s\n",phrase,forwards,backwards);

        if(!isPalindrome(forwards,backwards)) printf("Not a palindrome.\n");
        else printf("It is a palindrome.\n");
    }

    return 0;
}
//------------------------------ trimArray ------------------------------  
void trimArray(const char* p, char* f) {
    // Traverse the array p and copy all the alphanumeric chars of it into the
    // array f. 
    while(*p != '\0') {
        if(isalpha(*p)) {
            *f = tolower(*p);
            f++;
        }
        p++;
    }
    *f = '\0';
    return;
}

//------------------------------ reverseArray ------------------------------  
void reverseArray(const char* f, char* r) {
    // Traverse the array f and copy all the elements into the array r in the
    // reverse order.
    int length = strlen(f);
    int i;
    for(i=0;i<length;i++) {
        *(r+i) = *(f+length-1-i);
    }
    *(r + length) = '\0';
    return;
}
//------------------------------ isPalindrome ------------------------------  
int isPalindrome(const char* f, const char* r) {
    // This function returns a 1 if the two arrays f and r are identical.
    // Otherwise it returns a zero.
    if(strlen(f) != strlen(r)) return 0;
    while( *f != '\0') {
        if(*f++ != *r++) return 0;
    }
    return 1;
}
