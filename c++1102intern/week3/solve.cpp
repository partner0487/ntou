#include "card.h"
#include "solve.h"
#include "stdlib.h"
#include "stdio.h"

void swap(card *element1Ptr, card *element2Ptr) {
	card temp;
	temp = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = temp;
}

int sort1(card a, card b) {
	if (a.suitid == b.suitid) return a.faceid < b.faceid;
	return a.suitid > b.suitid;
}

int sort2(card a, card b) {
	if (a.faceid == b.faceid) return a.suitid > b.suitid;
	return a.faceid < b.faceid;
}

void shuffle(card *wDeck){
	card temp;
	int j;
	for (int i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

void output(card *wDeck){
	for (int i = 0; i <= 51; i++)
		printf("%d \t %5s of %-8s%c", i + 1, wDeck[i].face, wDeck[i].suit, '\n');
}

void bubble(card wdeck[], int size, int(*compare)(card, card)){
	int pass, count;

	for (pass = 1; pass < size; pass++) {
		for (count = 0; count < size - 1; count++){
			if ((*compare)(wdeck[count], wdeck[count + 1])){
				swap(&wdeck[count], &wdeck[count + 1]);
			}	
		}
	}
}


