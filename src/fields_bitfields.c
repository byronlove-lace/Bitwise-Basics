#include<stdio.h>

#define CARDS 52

typedef struct bitCard
{
        unsigned int face : 4; // : [FIELD_LEN]
        unsigned int suit: 2;
        unsigned int color : 1;
} Card;

void fillDeck(Card * const wDeck);
void deal(const Card * const wDeck);

int main (void)
{
        Card deck[CARDS];

        fillDeck(deck);

        puts("Card values 0-12 correspond to Ace through King");
        puts("Suit values 0-3 correspond Hearts, Diamonds, Clubs, Spades");
        puts("Color vlaues 0-1 correspond to red and black\n");
        deal(deck);
}

void fillDeck(Card * const wDeck)
{
        for (size_t i = 0; i < CARDS; ++i)
        {
                wDeck[i].face = i % (CARDS / 4);
                wDeck[i].suit = i / (CARDS / 4);
                wDeck[i].color = i / (CARDS / 2);
        }
}

void deal(const Card * const wDeck)
{
        printf("%-6s%-6s%-15s%-6s%-6s%s\n", 
                        "Card", "Suit", "Color", "Card", "Suit", "Color");

        for (size_t k1 = 0, k2 = k1 + 26; k1 < CARDS / 2; ++k1, ++k2)
        {
                printf("Card:%3d Suit: %2d Color: %2d ",
                                wDeck[k1].face, wDeck[k1].suit, wDeck[k1].color);

                printf("Card:%3d Suit: %2d Color: %2d \n",
                                wDeck[k2].face, wDeck[k2].suit, wDeck[k2].color);
        }
}
