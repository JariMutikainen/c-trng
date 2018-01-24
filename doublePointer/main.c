#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *titles[] = {
        "A tale of two cities",
        "Wuthering Heights",
        "Don Quixote",
        "Odyssey",
        "Moby-Dick",
        "Hamlet",
        "Gulliver's travels"
    };

    char **bestBooks[3];
    char **englishBooks[4];

    bestBooks[0] = &titles[0];
    bestBooks[1] = &titles[3];
    bestBooks[2] = &titles[5];

    englishBooks[0] = &titles[0];
    englishBooks[1] = &titles[1];
    englishBooks[2] = &titles[5];
    englishBooks[3] = &titles[6];

    // Print 'a' , the 2nd char in 'Hamlet'
    printf("*(*(*(bestBooks + 1) + 2) + 1) = %c\n",
            *(*(*(bestBooks + 1) + 2) + 1) );

    
    // Print 'amlet' part of 'Hamlet'
    printf("(*(*(bestBooks + 1) + 2) + 1) = %s\n",
            (*(*(bestBooks + 1) + 2) + 1) );


    // Print the 1st 'y' in 'Odyssey'.
    printf("*(*(*(bestBooks + 1)) + 2)  = %c\n",
            *(*(*(bestBooks + 1)) + 2)  );
    return 0;
}
