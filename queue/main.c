#include <stdio.h>
#include <stdlib.h>
#define ELEMENTS 8

typedef struct _queueType {
    int wa; 
    int ra;
    double dTable[ELEMENTS];
} QueueType, *pQueueType;


int main()
{
    pQueueType initQueue(void);
    void enQueue(pQueueType p2Q,double dnum);
    void printQueue(QueueType Q);

    pQueueType pQ = initQueue();
    printQueue(*pQ);



    printf("Hello world!\n");
    return 0;
}

//------------------------------ initQueue ------------------------------  
pQueueType initQueue(void) {
    // This function initializes a queue by setting wa = ra = 0 and
    // setting all the element of the queue to 0.0. The return value is a 
    // pointer to the newly created Queue.
    int i;

    pQueueType pQ = (pQueueType) malloc(sizeof(QueueType));
    pQ->wa = pQ->ra = 0; // The Q is empty when wa == ra. 
    for(i=0;i<ELEMENTS;i++) {
        pQ->dTable[i] = 0.0;
    }
    return pQ;
}

//------------------------------ printQueue ------------------------------  
void printQueue(QueueType Q) {
    //This function prints the current values of the Queue elements and the
    // current wa and ra pointers.
    int i;
    if(Q->wa == Q->ra) {
        printf("The queue is empty.\n");
    }
    for(i=0;i<ELEMENTS;i++) {
        printf("Q[%d] = %3.2f ",i,Q.dTable[i]);
        if(Q->wa == Q->ra) printf("<--- Head, Tail\n");
        else if(i == Q.wa) printf("<--- Head\n");
        else if(i == Q.ra) printf("<--- Tail\n");
        else printf("\n");
    }
    return;
}

//------------------------------ enQueue ------------------------------  
void enQueue(pQueueType p2Q,double dnum) {
    // This function adds a new element dnum into the ra of the Queue.
    int fillLevel = (p2Q->wa - p2Q->ra < 0) ? 
                    (ELEMENTS + p2Q->wa - p2Q->ra) :
                    (p2Q->wa - p2Q->ra));                     
    


    return;
}

