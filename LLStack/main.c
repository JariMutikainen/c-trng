#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct node_s {
    int val;
    struct node_s *p2NextNode;
} Node_t, *p2Node_t;

typedef struct stack_s {
    p2Node_t top;
    int elements;
} Stack_t, *p2Stack_t;

int main() {
    // This is a little exercise about implementing a stack of integers using
    // a linked list.
    
     p2Stack_t initStack();
     void pushToStack(p2Stack_t p2s, int num);
    void printStack(p2Stack_t p2s);
    int popStack(p2Stack_t p2s);
    int i;
     p2Stack_t s = initStack();
    for(i=1;i<MAX_SIZE + 3;i++) {
        pushToStack(s,2*i+1);
    }
    printStack(s);
    for(i=1;i<MAX_SIZE + 3;i++) {
        popStack(s);
    }
    printStack(s);



    return 0;
}

//------------------------------ initStack ------------------------------  
// This function initializes a stack and sets the top pointer to NULL,
// and elements to 0.
 p2Stack_t initStack() {
    p2Stack_t p2s = (p2Stack_t) malloc(sizeof(Stack_t));
    p2s->top = NULL;
    p2s->elements = 0;
    return p2s;
}
//------------------------------ pushToStack ------------------------------  
// This function pushes a new node into the top of the stack unless the stack
// is full already.
void pushToStack(p2Stack_t p2s, int num) {
    p2Node_t pN;
    if(p2s->elements < MAX_SIZE) {
        printf("Push %d\n",num);
        pN = (p2Node_t) malloc(sizeof(Node_t));
        pN->val = num;
        pN->p2NextNode = p2s->top;
        p2s->top = pN;
        (p2s->elements)++;
    } else {
        printf("Unable to push %d into the stack. The stack is full.\n",num);
    }
    return;
}
//------------------------------ printStack ------------------------------  
void printStack(p2Stack_t p2s) {
    p2Node_t pN = p2s->top;
    if(p2s->elements == 0) {
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack contains the following %d elements from the top to the bottom:\n\n",p2s->elements);
    while(pN->p2NextNode != NULL) {
        printf("%d ",pN->val);
        pN = pN->p2NextNode;
    }
    printf("%d \n",pN->val); // The last element with nextPtr = NULL
    return;
}
//------------------------------ popStack ------------------------------  
int popStack(p2Stack_t p2s) {
    // This function pops the top element off the stack unless the stack is
    // already empty.
    p2Node_t pApu = p2s->top;
    int poppedVal = -1;
    if(p2s->elements == 0) {
        printf("Can't pop. The stack is already empty.\n");
        return poppedVal;
    }
    poppedVal = p2s->top->val;
    printf("Popped %d.\n",poppedVal);
    p2s->top = p2s->top->p2NextNode;
    (p2s->elements)--;
    free(pApu);
    return poppedVal;
}
    

