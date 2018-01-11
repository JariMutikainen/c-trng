#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int val;
    int cnt;
} NodeType;

int main()
{
    void printAll(NodeType** tbl, int elements);
    int binarySearch(NodeType** tbl, int elements);
    NodeType *numbers[MAX]; // An array of pointers.
    NodeType *new;
    int total = 0;          // Total number of entries in the numbers[]
    int rply = 2;
    printf("This program asks for integers one at a time. \n");
    printf("It calculates the frequency of all the numbers.\n");
    printf("To terminate the feeding phase insert a zero.\n\n");
    //while(rply) {
        printf("Next number: ");
        scanf("%d",&rply);
        if(total == 0) { // Add the first element
            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = rply;
            new->cnt = 1;
            numbers[0] = new;
            // Add some extra elements to speed up development.
            // Remove these when ready.
            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 12;
            new->cnt = 1;
            numbers[1] = new;

            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 23;
            new->cnt = 1;
            numbers[2] = new;

            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 666;
            new->cnt = 6;
            numbers[3] = new;


            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 700;
            new->cnt = 2;
            numbers[4] = new;

            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 714;
            new->cnt = 1;
            numbers[5] = new;

            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = 854;
            new->cnt = 1;
            numbers[6] = new;
        } 
        //total++;
        total += 7;  // Remove this when ready
    //} // while(rply)
    printAll(numbers,total);
    printf("\n\nAsk frequencies of numbers. Terminate by entering a zero.\n\n");
    //while(rply) {
        printf("Next number: ");
        scanf("%d",&rply);
    return 0;
}
//------------------------------ printAll ------------------------------  
void printAll(NodeType** tbl, int elements) {
    int i;
    for(i=0;i<elements;i++) {
        printf("%d : %d\n",(*(tbl+i))->val,(*(tbl+i))->cnt);
    }
    return;
}

