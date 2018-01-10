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
    NodeType *numbers[MAX]; // An array of pointers.
    NodeType *new;
    int total = 0;          // Total number of entries in the numbers[]
    int rply = 2;
    printf("This program asks for integers one at a time. \n");
    printf("It calculates the median of all the numbers.\n");
    printf("To terminate the feeding phase insert a zero.\n\n");
    //while(rply) {
        printf("Next number: ");
        scanf("%d",&rply);
        if(total == 0) { // Add the first element
            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = rply;
            new->cnt = 1;
            numbers[0] = new;
        } 
        total++;
    //} // while(rply)
    printAll(numbers,total);
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

