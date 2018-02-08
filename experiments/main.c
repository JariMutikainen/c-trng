#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRHWDR_MAC_ADDR_SIZE 6


typedef unsigned char U_INT8;
typedef struct _koe {
    U_INT8 macAddr[TRHWDR_MAC_ADDR_SIZE];
} KoeType;


int main()
{

    KoeType dbEntry = { { 0 } };
    U_INT8 values[] = {1,2,3,4,5,6};
    U_INT8 newTbl[TRHWDR_MAC_ADDR_SIZE];
    U_INT8* pMacAddr = values;
    int i;

    for(i=0;i<TRHWDR_MAC_ADDR_SIZE;i++) {
        dbEntry.macAddr[i] = *(pMacAddr + i);
    }


    for(i=0;i<TRHWDR_MAC_ADDR_SIZE;i++) {
        printf("dbEntry.macAddr[%d] = %d\n",i,dbEntry.macAddr[i]);
    }



//    for(i=0;i<TRHWDR_MAC_ADDR_SIZE;i++) {
//        newTbl[i] = dbEntry.macAddr[i];
//    }

    memcpy(newTbl,dbEntry.macAddr,TRHWDR_MAC_ADDR_SIZE);



    
    for(i=0;i<TRHWDR_MAC_ADDR_SIZE;i++) {
        printf("newTbl[%d] = %d\n",i,newTbl[i]);
    }
    printf("Hello world!\n");
    return 0;
}
