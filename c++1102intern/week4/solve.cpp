#include "solve.h"
#include "stdlib.h"

void swap(card *element1Ptr, card *element2Ptr) {
	card temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}

void shuffle(card *wDeck) {
	card temp;
	int j;
	for (int i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void sort(card wdeck[], int size) {
	int pass, count;

	for (pass = 1; pass < size; pass++) {
		for (count = 0; count < size - 1; count++) {
			if (wdeck[count].faceid > wdeck[count + 1].faceid) {
				swap(&wdeck[count], &wdeck[count + 1]);
			}
		}
	}
}

int check1(card *wdeck, int start) {
	int pending = 0;
	sort(wdeck + start, 3);
	for (int i = start + 1; i < start + 3; i++) {
		if (wdeck[i].face == wdeck[i - 1].face) pending++;
	}
	return pending;
}

int check2(card *wdeck, int start) {
	int pending1 = 0, pending2 = 0, np = 1, state, p;
	sort(wdeck + start, 5);
	while (true) {
		switch (np) {
			case 1:
				for (int i = start; i < start + 5; i++) {
					if(wdeck[i].suitid == wdeck[i - 1].suitid) {
						if (wdeck[i].faceid == wdeck[i - 1].faceid + 1) {
							pending1++;
						}
					}
				}
				if (pending1 == 4) return 1;
				pending1 = 0; np++; break;
			case 2:
				for (int i = start; i < start + 5; i++) {
					if (wdeck[i].faceid == wdeck[i - 1].faceid) {
						pending1++;
					}
					else {
						if (pending1 == 3) return 2;
						pending1 = 0;  continue;
					}
				}
				pending1 = 0; np++; break;
			case 3:
				state = 1;
				for (int i = start; i < start + 5; i++) {
					if (state == 1) {
						if (wdeck[i].faceid == wdeck[i - 1].faceid) {
							pending1++;
						}
						else {
							if(pending1) state = 2;
						}
					}
					else {
						if (wdeck[i].faceid == wdeck[i - 1].faceid) {
							pending2++;
						}
					}
				}
				if ((pending1 == 2 && pending2 == 1) || (pending1 == 1 && pending2 == 2)) return 3;
				pending1 = pending2 = 0, np++; break;
			case 4:
				p = 1;
				for (int i = start; i < start + 5; i++) {
					if (wdeck[i].suit != wdeck[i - 1].suit) {
						p = 0;
						break;
					}
				}
				if(p) return 4;
				pending1 = 0, np++; break;
			case 5:
				for (int i = start; i < start + 5; i++) {
					if (wdeck[i].faceid == wdeck[i - 1].faceid + 1) {
						pending1++;
					}
				}
				if (pending1 == 4) return 5;
				pending1 = 0, np++; break;
			case 6:
				for (int i = start; i < start + 5; i++) {
					if (wdeck[i].face == wdeck[i - 1].face) {
						pending1++;
					}
					else {
						if (pending1 == 2) return 6;
						pending1 = 0;  continue;
					}
				}
				if (pending1 == 2) return 6;
				pending1 = 0, np++; break;
			case 7:
				state = 1;
				for (int i = start; i < start + 5; i++) {
					if (state == 1) {
						if (wdeck[i].face == wdeck[i - 1].face) {
							pending1++;
						}
						else {
							if (pending1) state = 2;
						}
					}
					else {
						if (wdeck[i].face == wdeck[i - 1].face) {
							pending2++;
						}
					}
				}
				if (pending1 == 1 && pending2 == 1) return 7;
				if ((pending1 == 1 && pending2 == 0) || (pending2 == 0 && pending1 == 1)) return 8;
				np++; break;
			case 8:
				return 0;
				break;
		}
	}
}