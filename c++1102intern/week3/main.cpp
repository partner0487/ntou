#include "card.h"
#include "solve.h"
#include "stdio.h"

void filldeck(card* wdeck, const char* wface[], const char* wsuit[]) {
	for (int i = 0; i <= 51; i++) {
		wdeck[i].faceid = i % 13;
		wdeck[i].suitid = i / 13;
		wdeck[i].face = wface[i % 13];
		wdeck[i].suit = wsuit[i / 13];
	}
}

int main() {
	card deck[52];

	const char* face[] = { "Ace", "Deuce", "Three",
							"Four", "Five",
							"Six", "Seven", "Eight",
							"Nine", "Ten",
							"Jack", "Queen", "King" };

	const char* suit[] = { "Spades", "Hearts", "Diamonds", "Clubs" };

	filldeck(deck, face, suit);
	output(deck);
	printf("\n");

	shuffle(deck);
	output(deck);
	printf("\n");

	bubble(deck, 52, sort1);
	output(deck);
	printf("\n");


	bubble(deck, 52, sort2);
	output(deck);
	printf("\n");

	for (int i = 0; i < 52; i += 13)
		bubble(deck, i + 13, sort1);
	output(deck);
	printf("\n");

	for (int i = 0; i < 52; i += 13)
		bubble(deck, i + 13, sort2);
	output(deck);
	printf("\n");
	//
}