#include <stdio.h>
#include <limits.h>

void displayBits(unsigned int value);

int main (void)
{
        unsigned int x;

        printf("%s", "Enter nonnegative int: ");
        scanf("%u", &x);

        displayBits(x);

}

void displayBits(unsigned int value)
{
        int unsignedIntBits = CHAR_BIT  * sizeof(unsigned int); // char is 1 byte 
                                                                // CHAR_BIT is the number of bits in a char (in 1 byte)
                                                                // sizeof returns num of bytes
                                                     
        unsigned int displayMask = 1 << (unsignedIntBits - 1); // 10000000 00000000 00000000 00000000
                                            // creates a shifts the 1 bit 31 places from the low-order
                                            // bit position to the high order bit position
                                            // and fills 0 bits from the right 

        printf("%10u = ", value);

        // loop through bits
        for (unsigned int c = 1; c <= unsignedIntBits; ++c)
        {
                putchar(value & displayMask ? '1' : '0');
                value <<= 1; // shift value left by 1

                if (c % 8 == 0)  // output space after 8 bits
                {
                        putchar(' ');
                }
        }

        putchar('\n');
}
