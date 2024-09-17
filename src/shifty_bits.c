#include<stdio.h>
#include <limits.h> 
#include <math.h>

void displayBits(int value);
unsigned int power2(unsigned int num, unsigned int powTo);

int main (void)
{
        int x = 55;

        displayBits(x);
        x >>= 4;
        displayBits(x);

        unsigned int pow2 = power2(5, 2);
        printf("%u\n", pow2);
        displayBits(pow2);
}

unsigned int power2(unsigned int num, unsigned int powTo)
{

        unsigned int result = pow(num << 1, powTo);

        return result;
}

void displayBits(int value)
{
        int unsignedIntBits = CHAR_BIT * sizeof(unsigned int);

        int mask = 1 << (unsignedIntBits - 1);

        for (int i = 1; i <= unsignedIntBits; ++i)
        {
                putchar(mask & value ? '1' : '0'); // ? TRUE : FALSE
                value <<= 1;

                if (i % 8 == 0)
                        putchar(' ');
        }
        putchar('\n');
}
