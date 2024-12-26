// 1014. Best Sightseeing Pair
#include "leetcode.h"

/*
 * you are given an integer array 'values' where 'values[i]' represents the
 * value of the i'th sightseeing spot. two sightseeing spots 'i' and 'j' have a
 * distance 'j - i' between them. the score of a pair ('i < j') of sightseeing
 * spots is 'values[i] + values[j] + i - j': the sum of the values of the
 * sightseeing spots. minus the distance between them. return the maximum score
 * of a pair of sightseeing spots.
 */

int maxScoreSightseeingPair(int *values, int valuesSize) {
  int ans = 0, curr = 0;
  for (int i = 0; i < valuesSize; i++) {
    ans = fmax(ans, curr + values[i]);
    curr = fmax(curr, values[i]) - 1;
  }
  return ans;
}

int main() {
  int v1[] = {8, 1, 5, 2, 6}, v2[] = {1, 2};
  printf("%d\n", maxScoreSightseeingPair(v1, ARRAY_SIZE(v1))); // expect: 11
  printf("%d\n", maxScoreSightseeingPair(v2, ARRAY_SIZE(v2))); // expect: 2
}
