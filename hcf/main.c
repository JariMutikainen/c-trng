#include <stdio.h>
#include <stdlib.h>

int main()
    /* This program find the Highest Common Factor (HCF) of two integers. */
{
    int hcf(int a, int b);
    int A = 7 * 3;
    int B = 7 * 13;
    int C = hcf(A,B);
    printf("A = %d, B = %d, Highest Common Factor is C = %d\n",A,B,C);
    return 0;
}
//------------------------------ hcf ------------------------------  
int hcf(int a, int b) {
   int k = (a<b) ? a : b; // 'k' is the smaller of the two.
   while(k > 1) {
        if((b % k == 0)  && (a % k == 0)) return k;
        else k--;
   }
   return 1;
}
