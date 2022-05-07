#pragma once
#include "iostream"
#include "algorithm"
using namespace std;

template<typename type> type Max(type *arr, int size) {
	type MAX = -2147483647;
	for (int i = 0; i < size; i++) MAX = max(arr[i], MAX);
	return MAX;
}
