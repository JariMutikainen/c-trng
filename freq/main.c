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
    int binarySearch(NodeType** tbl, int key, int elements);
    void insertInPlace(NodeType** tbl, int key, int* elements);
    NodeType *numbers[MAX]; // An array of pointers.
    NodeType *new;
    int total = 0;          // Total number of entries in the numbers[]
    int rply = 2;
    int index;
    printf("This program asks for integers one at a time. \n");
    printf("It calculates the frequency of all the numbers.\n");
    printf("To terminate the feeding phase insert a zero.\n\n");
            // Add some extra elements to speed up development.
            // Remove these when ready.
            //


    while(rply) {
        printf("Next number: ");
        scanf("%d",&rply);
        if(total == 0) { // Add the first element
            new = (NodeType*) malloc(sizeof(NodeType));
            new->val = rply;
            new->cnt = 1;
            numbers[0] = new;
            total = 1;
        } else {
            index = binarySearch(numbers, rply, total);
            if(index < 0) {
                insertInPlace(numbers, rply, &total);
            } else {
                ((numbers[index])->cnt)++;  // Increment the # of the occurences.
            }
        }
        printAll(numbers,total);
    } // while(rply)
    printf("\n\n");
    printAll(numbers,total);
    printf("\n\nAsk frequencies of numbers. Terminate by entering a zero.\n\n");
    rply = 2; // Make non-zero to get going.
    while(rply) {
        printf("Next number: ");
        scanf("%d",&rply);
        index = binarySearch(numbers, rply, total);
        if(index < 0) {
            printf("%d has 0 occurences.\n",rply);
        } else {
            printf("%d has %d occurences.\n",rply,numbers[index]->cnt);
        }
    }
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
//------------------------------ binarySearch ------------------------------ 
int binarySearch(NodeType** tbl, int key, int elements) {
    /*This function searches for the key in the table. If it finds the key,
     * it returns the index of key in the array tbl otherwise it returns -1.*/
    int lo = 0;
    int hi = elements - 1;
    int mid;
    NodeType** curr;  // Pointer to the node to look at next
    while(lo <= hi) {
        mid = (hi + lo) / 2;
        curr = tbl + mid;    // Pointer arithmetics !
        if(key == (*curr)->val) return mid; // found
        if(key < (*curr)->val) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}
//------------------------------ insertInPlace ------------------------------ 
void insertInPlace(NodeType** tbl, int key, int* elements) {
    /* This function insert the new element 'key' into the existing array tbl
     * so that after the insertion the number of elements has been increased by
     * one and the elements are in the ascending order. */
    NodeType* newNode = (NodeType*) malloc(sizeof(NodeType));
   int k = *elements - 1; // k points at the last element of the tbl.
   while(k >= 0 && key < (*(tbl +k))->val) {
       tbl[k+1] = tbl[k];
       k--;
   }
   tbl[k+1] = newNode;
   (tbl[k+1])->val = key;
   (tbl[k+1])->cnt = 1;
   (*elements)++;
}
