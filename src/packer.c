#include <stdio.h>
#include <limits.h>

#define INT_COUNT 4

unsigned int packChars();
void unpackChars(unsigned int packed);
void displayBits(unsigned int value);

int main (void)
{
        unsigned int test = packChars();
        displayBits(test);

        unpackChars(test);
}

unsigned int packChars()
{
        char charArr[INT_COUNT];
        unsigned int pack;

        for (size_t i = 0; i < INT_COUNT; ++i)
        {
                printf("Please enter char %ld: ", i + 1);
                scanf("%c", &charArr[i]);

                int c;
                while (( c = getchar()) != '\n'){}
                
                displayBits(charArr[i]);
        }

        pack = charArr[0];

        for (size_t i = 1; i < INT_COUNT; ++i)
        {
                pack <<= 8;
                pack |= charArr[i];
        }

        return pack;
}

void unpackChars(unsigned int packed)
{
        unsigned int mask1 = 4278190080;
        unsigned int mask2 = 16711680;
        unsigned int mask3 = 65280;
        unsigned int mask4 = 255;

        char unpackedChars[INT_COUNT];

        unpackedChars[0] = (packed & mask1) >> 8;
        unpackedChars[1] = (packed & mask2) >> 8;
        unpackedChars[2] = (packed & mask3) >> 8;
        unpackedChars[3] = (packed & mask4) >> 8;

        printf("%c\n", unpackedChars[1]);
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
