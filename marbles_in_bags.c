// 2551. Put Marbles in Bags
#include <stdio.h>
#include <stdlib.h>

/*
 * you have 'k' bags. you are given a 0-indexed integer array 'weights' where
 * 'weights[i]' is the weight of the i'th marble. you are also given the integer
 * 'k'. divide the marbles into the 'k' bags according to the following rules
 * - no bag is empty
 * - if the i'th marble and the j'th marble are in a bag, then all the marbles
 * with an index between the i'th and j'th indices should also be in that same
 * bag.
 * - if a bag onsists of all the marbles with an index from 'i' to 'j'
 * inclusively, then the cost of the bag is 'weights[i] + weights[j]' the score
 * after distributing the marbles is the sum of the costs of all the 'k' bags.
 * return the difference between the maximum and minimum scores among marble
 * distributions
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long putMarbles(int *weights, int weights_size, int k) {
  int n = weights_size;
  if (n == k || k == 1)
    return 0;
  int *data = malloc((n - 1) * sizeof(int));
  for (int i = 0; i < n - 1; i++)
    data[i] = weights[i] + weights[i + 1];
  qsort(data, n - 1, sizeof(int), cmp);
  long long min = weights[0] + weights[n - 1];
  long long max = weights[0] + weights[n - 1];
  for (int i = 0; i < k - 1; i++) {
    min += data[i];
    max += data[n - 2 - i];
  }
  return max - min;
}

int main() {
  int w1[] = {1, 3, 5, 1}, w2[] = {1, 3};
  printf("%lld\n", putMarbles(w1, 4, 2)); // expect: 4
  printf("%lld\n", putMarbles(w2, 2, 2)); // expect: 0
}
