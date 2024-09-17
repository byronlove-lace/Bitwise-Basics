#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value);

int main (void)
{
        unsigned int num1 = 65535;
        unsigned int mask = 1;

        puts("Combining");
        displayBits(num1);
        displayBits(mask);
        puts("using & is"); 
        displayBits(num1 & mask);

        unsigned int num2 = 15;
        unsigned int setBits = 248;

        puts("\nThe result of combing the following");
        displayBits(num2);
        displayBits(setBits);
        puts("using | ");
        displayBits(num2 | setBits);

        unsigned int num3 = 139;
        unsigned int num4 = 248;
        puts("\nThe result of combing the following");
        displayBits(num3);
        displayBits(num4);
        puts("using ^ ");
        displayBits(num3 ^ num4);

        unsigned int num5 = 21845;
        puts("\nThe one's compliment of");
        displayBits(num5);
        puts("is");
        displayBits(~num5);
}


void displayBits(unsigned int value)
{
        int unsignedIntBits = CHAR_BIT  * sizeof(unsigned int); 
                                                     
        unsigned int displayMask = 1 << (unsignedIntBits - 1); 

        printf("%10u = ", value);

        for (unsigned int c = 1; c <= unsignedIntBits; ++c)
        {
                putchar(value & displayMask ? '1' : '0');
                value <<= 1; 

                if (c % 8 == 0)  
                {
                        putchar(' ');
                }
        }

        putchar('\n');
}
