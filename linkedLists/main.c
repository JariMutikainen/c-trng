#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} NodeType, *NodePtrType;

int main() {
    NodePtrType head = NULL;
    NodePtrType tail = NULL;
    void createLinkedList(int tbl[],int elements,NodePtrType* h,NodePtrType* t);
    void reverseLinkedList(NodePtrType* h, NodePtrType* t);
    void printLinkedList(NodePtrType top);
    int isAscendingList(NodePtrType t);
    //int numbers[] = {1,2,3,4,5,6,7};
    int numbers[] = {1,2,3,4,5,3,6,7};
    int elements = sizeof(numbers) / sizeof(int);
    createLinkedList(numbers,elements,&head,&tail);
    printLinkedList(head);
    if(isAscendingList(head)) {
        printf("This is an ascending list of integers.\n");
    } else {
        printf("This is not an ascending list of intergers.\n");
    }
    reverseLinkedList(&head,&tail);
    printLinkedList(head);
    printf("%d,first=%d,last=%d\n",elements,head->val,tail->val);
    return 0;
}
//------------------------------ createLinkedList ------------------------------  
void createLinkedList(int tbl[],int elements,NodePtrType* h,NodePtrType* t) {
    // This function creates a linked list of the array elements of tbl[].
    // It returns pointers to the head (h) and tail (t) of the generated list.
    NodePtrType np,new;
    int i;
    // Create the 1st node
    *h = np = (NodePtrType) malloc(sizeof(NodeType));
    np->val = tbl[0];
    np->next = NULL;
    // Create the rest of the elements
    for(i=1;i<elements;i++) {
        new = (NodePtrType) malloc(sizeof(NodeType));
        new->val = tbl[i];
        new->next = NULL;
        np->next = new;
        np = new;
        if(i==elements-1) *t = new;
    }
    return;
}
//------------------------------ printLinkedList ------------------------------  
void printLinkedList(NodePtrType top) {
    NodePtrType np = top;
    while(np->next != NULL) {
        printf("%d  ",np->val);
        np = np->next; // Move on.
    }
    printf("%d\n",np->val); // The last element.
    return;
}
void reverseLinkedList(NodePtrType* h, NodePtrType* t) {
    // This function reverses the order of the elements in the given linked 
    // list. It updates the head and tail pointers of the calling function
    // accordingly.

    NodePtrType prev = NULL;
    NodePtrType curr = NULL;
    NodePtrType apu = NULL; 
    NodePtrType newHead = NULL;
    NodePtrType newTail = NULL;
    curr = *h;
    while(curr != *t) {
        apu = curr->next; // Capture this to be used later for the jump to next
        if(curr == *h) {  // The 1st of the original list
            curr->next = NULL; // Becomes the last of the reversed list
            newTail = curr;
            prev = curr;
            curr = apu; // Jump now
        } else {
            curr->next = prev;
            prev = curr;
            curr = apu; // Jump now
        }
    }
    // curr is pointing to the tail of the original list now.
    curr->next = prev;
    newHead = curr;
    // Update the head and tail pointers of the calling function
    *h = newHead;
    *t = newTail;
    return;
}
//------------------------------ isAscendingList ------------------------------  
int isAscendingList(NodePtrType t) {
    // This function returns 1 if the elements of the linked list are in the
    // ascending order. Otherwise it returns a 0.
    
    NodePtrType prev = NULL,curr = t;
    while(curr->next != NULL) { // Traverse the linked list
        if(curr == t) {         // At the 1st node - i.e. 'top'
            prev = curr;
            curr = curr->next;  // Move on
        } else { // The middle nodes
            if(curr->val < prev->val) return 0;
            prev = curr;
            curr = curr->next;  // Move on
        }
    }
    // Now we are at the last node
    if(curr->val < prev->val) return 0;
    else return 1;
}    


