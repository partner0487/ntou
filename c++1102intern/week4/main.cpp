#include "iostream"
#include "stdio.h"
#include "solve.h"
#include "card.h"

void filldeck(card *wdeck, const char * wface[], const char * wsuit[]) {
	for (int i = 0; i <= 51; i++) {
		wdeck[i].faceid = i % 13;
		wdeck[i].suitid = i / 13;
		wdeck[i].face = wface[i % 13];
		wdeck[i].suit = wsuit[i / 13];
	}
}

void check(card *wdeck, int start, int size) {
	for (int i = start; i < start + size; i++) {
		printf("%d %d\n", wdeck[i].suitid, wdeck[i].faceid);
	}
}

int main() {
	card deck[52];

	const char *face[] = { "Ace", "Deuce", "Three",
							"Four", "Five",
							"Six", "Seven", "Eight",
							"Nine", "Ten",
							"Jack", "Queen", "King" };

	const char *suit[] = { "Spades", "Hearts", "Diamonds", "Clubs" };

	filldeck(deck, face, suit);

	int n, ans;
	while (scanf_s("%d", &n) && n != 4) {
		if (n == 1) shuffle(deck);
		else if (n == 2) {
			for (int i = 0; i < 49; i += 3) {
				ans = check1(deck, i);
				check(deck, i, 3);
				if (!ans) printf("High card\n");
				else if (ans == 1) printf("One Pair\n");
				else printf("Three of a kind\n");
			}
		}
		else if (n == 3) {
			for (int i = 0; i < 47; i += 5) {
				ans = check2(deck, i);
				check(deck, i, 5);
				switch (ans) {
					case 0:
						printf("High card\n");
						break;
					case 1:
						printf("Straight Flush\n");
						break;
					case 2:
						printf("Four of a Kind\n");
						break;
					case 3:
						printf("Full house\n");
						break;
					case 4:
						printf("Flush\n");
						break;
					case 5:
						printf("Straight\n");
						break;
					case 6:
						printf("Three of a kind\n");
						break;
					case 7:
						printf("Two Pairs\n");
						break;
					case 8:
						printf("One Pair\n");
						break;
				}
			}
		}
	}
}