#include <stdio.h>
#include <stdlib.h>
#define ELEMENTS 8

typedef struct _queueType {
    int wa; // The next addr to be written to
    int ra; // The next addr to be read from
    double dTable[ELEMENTS];
} QueueType, *pQueueType;


int main()
    // This program implements a Queue of double precision decimal numbers.
    // The elements are stored in an array. 
{
    pQueueType initQueue(void);
    void enQueue(pQueueType p2Q,double dnum);
    void printQueue(QueueType Q);
    void deQueue(pQueueType p2Q);
    int j;

    pQueueType pQ = initQueue();
    printQueue(*pQ);
    enQueue(pQ,3.14);
    enQueue(pQ,2.73);
    enQueue(pQ,2.343);
    deQueue(pQ);
    deQueue(pQ);
    printQueue(*pQ);
    for(j=1;j<8;j++) {
        enQueue(pQ,(j/3.0));
    }
    printQueue(*pQ);
    for(j=1;j<10;j++) {
        deQueue(pQ);
        printQueue(*pQ);
    }


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
    if(Q.wa == Q.ra) {
        printf("The queue is empty.\n");
    }
    for(i=0;i<ELEMENTS;i++) {
        printf("Q[%d] = %3.2f ",i,Q.dTable[i]);
        if((Q.wa == Q.ra) && (Q.wa == i)) printf("<--- Head and Tail of an empty Q.");
        else {
            if(i == Q.wa) printf("<--- wa = Tail = The vacant addr for the next new element.");
            if(i == Q.ra) printf("<--- ra = Head = The element to be removed next.");
        }
        printf("\n");
    }
    return;
}

//------------------------------ enQueue ------------------------------  
void enQueue(pQueueType p2Q,double dnum) {
    // This function adds a new element dnum into the wa of the Queue.
    int fillLevel = (p2Q->wa >= p2Q->ra) ? 
                    (p2Q->wa - p2Q->ra) : 
                    (ELEMENTS + p2Q->wa - p2Q->ra);

    if(fillLevel < ELEMENTS - 1) { // A new element fits in
        p2Q->dTable[p2Q->wa] = dnum;
        printf("Added %3.2f to Q[%d].\n",dnum,p2Q->wa);
        (p2Q->wa) = ((p2Q->wa) + 1) % ELEMENTS;
    } else {
        printf("Unable to add %3.2f into the Q, because the Q is already full.\n",dnum);
    }    


    return;
}
//------------------------------ deQueue ------------------------------  

void deQueue(pQueueType p2Q) {
    // This function removes the head element of the Q unless the Q is already
    // empty.
    int fillLevel = (p2Q->wa >= p2Q->ra) ? 
                    (p2Q->wa - p2Q->ra) : 
                    (ELEMENTS + p2Q->wa - p2Q->ra);
    if(fillLevel) { // If not empty
        printf("Removed element %3.2f at Q[%d] from the queue.\n",p2Q->dTable[p2Q->ra],p2Q->ra);
        (p2Q->ra) = ((p2Q->ra) + 1) % ELEMENTS;
    } else {
        printf("Dequeueing failed. The Queue is already empty.\n");
    }
    return;
}

