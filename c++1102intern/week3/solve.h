#pragma once
#ifndef solve_h
#define solve_h

#include "card.h"

void shuffle(card *wDeck);
void output(card *wdeck);
void bubble(card wdeck[], int size, int(*compare)(card, card));
int sort1(card a, card b);
int sort2(card a, card b);

#endif