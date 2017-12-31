#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    // Asks for max 10 integers followed by a zero. Then sorts the integers
    // into the ascending order.
    void selectionSort(int *tbl, int elems, int *comps, int *assigns);
    int numbers[MAX];
    int i = 0,num = 0;
    int elements = 0;
    int comparisons = 0,assignments = 0;
    printf("Enter max %d integers followed by a zero: ",MAX);
    scanf("%d",&num);
    while(num != 0) {
      numbers[i++] = num;
      scanf("%d",&num);
    }
    elements = i; //  The number of the elements in numbers[] array.
    selectionSort(numbers,elements,&comparisons,&assignments);
    for(i=0;i<elements;i++) {
      printf("%d ",numbers[i]);
    }
    printf("\n");
    printf("%d comps, %d assigns\n",comparisons,assignments);
    return 0;
}

//-----------------selectionSort-------------------------------------------
void selectionSort(int *tbl, int elems, int *comps, int *assigns) {
    int pickSmallest(int *tb, int start, int stop, int *comps, int *assigns);
    void swap(int* t, int index1, int index2, int *assigns);

    int smallest;
    int k;
    smallest = pickSmallest(tbl,0,(elems-1),comps,assigns);
    swap(tbl,0,smallest,assigns);
    for(k=1;k<(elems-1);k++) {
      smallest = pickSmallest(tbl,k,(elems-1),comps,assigns);
      swap(tbl,k,smallest,assigns);
    }
    return;
}


//-----------------pickSmallest-------------------------------------------
int pickSmallest(int *tb, int start, int stop, int *comps, int *assigns) {
    // This function returns the index of the smallest element between
    // the indicies start and top.
    int min;
    int i;
    for(i=start,min=start;i<=stop;i++) {
       (*comps)++;
       if(*(tb + i) < *(tb + min)) {
           min = i; // capture the index of the new minimum.
	   (*assigns)++;
       }

    }

    return min;
}

//-----------------swap-------------------------------------------
void swap(int* t, int index1, int index2, int *assigns) {
    // This function swaps the two elements of the table.
    int temp;
    temp = *(t + index1);
    *(t + index1) = *(t + index2);
    *(t + index2) = temp;
    (*assigns) += 3;
    return;
}
