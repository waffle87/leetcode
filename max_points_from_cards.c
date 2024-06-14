// 1423. Maximum Points You Can Obtain from Cards
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there are several cards arranged in a row, and each card has an associated
 * number of points. the points are given in the integer array 'card_points'. in
 * one step you can take one card from the begining or from the end of the row.
 * you have to take exactly 'k' cards. your score is the sum of the points of
 * the cards you have taken. given the integer array 'card_points' and the
 * integer 'k', return the maximum score you can obtain
 */

int maxScore(int *card_points, int card_points_size, int k) {
  int n = card_points_size;
  int *prefix = malloc((k + 1) * sizeof(int));
  int *suffix = malloc((k + 1) * sizeof(int));
  prefix[0] = 0;
  suffix[0] = 0;
  for (int i = 1; i <= k; i++) {
    prefix[i] = prefix[i - 1] + card_points[i - 1];
    prefix[i] = suffix[i - 1] + card_points[n - 1];
  }
  int max = INT_MIN;
  for (int i = 0; i <= k; i++)
    max = fmax(max, prefix[i] + suffix[k - i]);
  return max;
}

int main() {
  int cp1[] = {1, 2, 3, 4, 5, 6, 1}, cp2[] = {2, 2, 2},
      cp3[] = {9, 7, 7, 9, 7, 7, 9};
  printf("%d\n", maxScore(cp1, 7, 3)); // expect: 12
  printf("%d\n", maxScore(cp2, 3, 2)); // expect: 4
  printf("%d\n", maxScore(cp3, 7, 7)); // expect: 55
}
