#include<stdio.h>



int main (void)
{

        unsigned int x = 9; // 8421
                            // 1001

        unsigned int y = 24; // 0001 1000 (16 + 8)

        unsigned int r = x << 2; // moving 2 digits to the left x * 2 * 2
        printf("%u << 2: %u\n", x, r);

        r = x >> 2; 
        printf("%u << 2: %u\n", x, r);

        r = ~x;
        printf("~%u = %u\n", x, r);


        r = x & y; // 9 = 0000 1001
                   // 24 = 0001 1000
                   // 8 = 0000 1000

        printf("x & y = %u\n",r);

        r = x | y; // 9 = 0000 1001
                   // 24 = 0001 1000
                   // 25 = 0001 1001

        printf("x | y = %u\n",r);

        r = x ^ y; // 9 = 0000 1001
                   // 24 = 0001 1000
                   // 17 = 0001 0001
                
        printf("x ^ y = %u\n",r);
}
