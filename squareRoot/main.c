#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
    // This program uses the random numbers to estimate the square root
    // of a given integer.
{
    int findPredecessor(int num);
    double estimateSqrt(int min, int num, int iterations);
    int min = 0, answ = 0, iterations = 1;
    printf("This program calculates the square root of the given number.\n\n");
    while(1) {  // Runs until the user hits <ctrl>-c.
        printf("Enter an integer number between 0 and %d : ",MAX);
        scanf("%d",&answ);
        printf("Enter the number of iterations : ");
        scanf("%d",&iterations);
        min = findPredecessor(answ);

        printf("The predecessor is %d.\n",min);

        printf("The estimated squareroot of %d is %5.3f.\n",answ,
                estimateSqrt(min,answ,iterations));
    }

    printf("Hello world!\n");
    return 0;
}
//------------------------------  findPredecessor ------------------------------ 
int findPredecessor(int num) 
{
    // This function returns the largest integer the square of which is still
    // smaller than num.
    int i = 0;
    while(i * i <= num) i++;
    return i-1;
}
//------------------------------ estimateSqrt ------------------------------ 
double estimateSqrt(int min, int num, int iterations)
{
    int smallerSqrs = 0;
    double candidate;
    int i;
    srand(time(0));  // Seed the rand()
    for(i=0;i<iterations;i++) {
        candidate = min + rand() / (RAND_MAX + 1.0);
        if(candidate * candidate < num) smallerSqrs++;
    }
    return (double)min + ((double)smallerSqrs) / ((double)iterations);
}

