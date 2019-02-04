#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SETS 5 // The number of 7-integer sets
#define LARGEST_NUM 40

int main() {
    // This program takes advantage of the random number generator to generate
    // 5 sets of lotto numbers - 7 numbers in each set. Every number is unique
    // - i.e. it is used only once.
    //
    void printLottoSets(int tbl[][7], int rows);
    void makeASet(int* set,int setSize,int numberInUse[], int size);
    void bubbleSort(int set[],int setSize);
    int numberInUse[LARGEST_NUM+1] = {0}; // Lotto numberInUse. 0 is not in use.
    int lottoSets[SETS][7] = {{0}}; // 7 numberInUse in each set.
    int row;
    srand(time(0)); // Seed the random number generator based on the current time.
    for(row=0;row<SETS;row++) {
        makeASet(lottoSets[row],7,numberInUse,LARGEST_NUM+1);
    }
    printf("The lotto numbers in a random order:\n");
    printLottoSets(lottoSets,SETS);

    // Sort the lotto numbers into the ascending order in each set.
    for(row=0;row<SETS;row++) {
        bubbleSort(lottoSets[row],7);
    }
    printf("\n\nThe lotto numbers in the ascending order after a bubble sort:\n");
    printLottoSets(lottoSets,SETS);

    printf("Hello world!\n");
    return 0;
}
//------------------------------ bubbleSort ------------------------------  
void bubbleSort(int set[],int setSize) {
    // This function sorts the elements of the table set[] into the
    // ascending order.
    int i,j,temp;
    for(i=0;i< setSize-1;i++) {
        for(j=i+1;j<setSize;j++) {
            if(set[j] < set[i]) {
                temp = set[i];  // Swap
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }
    return;
}

//------------------------------ makeASet ------------------------------  
void makeASet(int* set,int setSize,int numberInUse[], int size) {
    // This function generates a set of 7 lotto numbers. The numbers
    // are unique and not used in any ione of the other sets of lotto numbers.
    int drawANumber(int numberInUse[],int size);
    int c;
    for(c=0;c<setSize;c++) {
        *(set + c) = drawANumber(numberInUse,size);
    }
    return;
}
//------------------------------ printLottoSets ------------------------------  
void printLottoSets(int tbl[][7], int rows) {
    int r,c;
    for(r=0;r<rows;r++){
        for(c=0;c<7;c++){
            printf("%3d",tbl[r][c]);
        }
        printf("\n"); // Line feed at the end of every set
    }
    return;
}
//------------------------------ drawANumber ------------------------------  
int drawANumber(int numberInUse[],int size) {
    // This function draws a new random number in the range of 1-40.
    // If the drawn number has already been used it selects the 1st unused
    // bigger number instead. After 40 the next bigger is 1 (= roll over).
    int jmRandom(int min, int max);
    int findThe1stUnused(int start,int numberInUse[],int size);
    int rV = jmRandom(1,40);  // returns a random number in the range of 1-40.
    if(numberInUse[rV]) {
        // Find the 1st larger and unnused starting from rV+1.
        rV = findThe1stUnused(rV+1,numberInUse,size);
    }
    numberInUse[rV] = 1; // Mark the entry as being in use from now on.
    return rV;
}

//------------------------------ jmRandom ------------------------------  
int jmRandom(int min, int max) {
    // This function generates a random number in the range of min - max.
    int offset = rand() / (RAND_MAX + 1.0) * (max-min+1);
    return min + offset;
}
//------------------------------ findThe1stUnused --------------------  
int findThe1stUnused(int start,int numberInUse[],int size) {
    // This function searches the numberInUse[] starting at start until
    // it finds the 1st unused integer - -i.e. the value is 0. If it reaches
    // the end of the table before finding it, it will roll over to 1 and
    // continue from there on.
    int indx = start;
    while(numberInUse[indx]) { // Skip all the non-zero elements.
        indx = (indx == LARGEST_NUM) ? 1 : (indx + 1); // Roll over at 40
    }
    return indx;
}

