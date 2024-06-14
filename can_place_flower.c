// 605. Can Place Flowers
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you have long flowerbed in which some of the plots are
 * planted, and some are not. however, flowers cannot be planted
 * in adjacent plots. given an integer array 'flowerbed'
 * containing 0's and 1's, where 0 means empty and 1 means not empty
 * and an integer 'n', return if 'n' new flowers can be planted
 * in the 'flowerbed' without violating the no-adjacent rule
 */

bool canPlaceFlowers(int *flowerbed, int flowerbed_size, int n) {
  int i = 0, prev = 0;
  for (; i < flowerbed_size - 1; i++) {
    if (flowerbed[i] == 0 && prev == 0 && flowerbed[i + 1] == 0) {
      prev = 1;
      n--;
    } else
      prev = flowerbed[i];
  }
  if (flowerbed[i] == 0 && prev == 0)
    n--;
  return n <= 0;
}

int main() {
  int flowerbed[] = {1, 0, 0, 0, 1};
  printf("%d\n", canPlaceFlowers(flowerbed, 5, 1)); // expect: 1
  printf("%d\n", canPlaceFlowers(flowerbed, 5, 2)); // expect: 0
}
