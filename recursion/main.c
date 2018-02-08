#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largest(int t[],int start,int elems);
    int tbl[] = {34,2,6,7,54,2,4,0,19};
    int elements = sizeof(tbl) / sizeof(int);
    int i;
    printf("In the table: ");
    for(i=0;i<elements;i++) {
        printf("%d ",tbl[i]);
    }
    int max = largest(tbl,0,elements);
    printf("\nThe largest value is: %d \n",max);
    return 0;
}
//------------------------------ largest ------------------------------  
// This is a recursive function, which determines the largest value in the
// table t[] between the indicies start...(elems-1).
int largest(int t[],int start,int elems) {
    int rV;
    static int iteration;
    printf("Iteration %d: start = %d t[start] = %d\n",iteration++,start,t[start]);
    if(start == elems-1) {
        rV = t[start];
    } else if (t[start] > largest(t,start+1,elems)) {
        rV = t[start];
    } else {
        rV = largest(t,start+1,elems);
    }
    return rV;
}
