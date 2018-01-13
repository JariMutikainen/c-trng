#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m;
    int cm;
} LenType;

int main()
{
    void printLen(LenType x);
    void addLen(LenType* x, LenType* y, LenType* z);
    void subLen(LenType* x, LenType* y, LenType* z);
    LenType a,b,c,d,e;
    a.m = 1;
    a.cm = 25;
    b.m = 3;
    b.cm = 14;

    printLen(a);
    printLen(b);
    addLen(&a,&b,&c);
    printf("%dm %dcm  +  %dm %dcm  = %dm %dcm\n",
            a.m,a.cm,b.m,b.cm,c.m,c.cm);

    subLen(&a,&b,&d);
    printf("%dm %dcm  -  %dm %dcm  = %dm %dcm\n",
            a.m,a.cm,b.m,b.cm,d.m,d.cm);

    printf("Hello world!\n");
    return 0;
}
//---------------------------- printLen -------------------------------- 
void printLen(LenType x) {
    printf("%dm %dcm\n",x.m,x.cm);
    return;
}
//---------------------------- addLen -------------------------------- 
void addLen(LenType* x, LenType* y, LenType* z) {
    int xTot = x->m * 100 + (*x).cm;
    int yTot = y->m * 100 + y->cm;
    int zTot = xTot + yTot;
    z->m = zTot / 100;
    z->cm = zTot - 100 * z->m;
    printf("%d %d %d\n",xTot,yTot,zTot);

    return;
}
//---------------------------- subLen -------------------------------- 
void subLen(LenType* x, LenType* y, LenType* z) {
    int xTot = x->m * 100 + x->cm;
    int yTot = y->m * 100 + y->cm;
    int zTot = xTot - yTot;
    z->m = zTot / 100;
    z->cm = zTot - 100 * z->m;
    printf("%d %d %d\n",xTot,yTot,zTot);

    return;
}
