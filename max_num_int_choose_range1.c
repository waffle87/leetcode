// 2554. Maximum Number of Integers to Choose From a Range I
#include "leetcode.h"

/*
 * you are given an integer array 'banned' and two integers 'n' and a 'maxSum'.
 * you are choosing some number of integers following the below rules: the
 * chosen integers have to be in the range '[1, n]', each integer can be chosen
 * at most once, the chosen integers should not be in the array 'banned', and
 * the sum of the chosen ntegers should not exceed 'maxSum'. return the maximum
 * number of integers you can choose following the mentioned rules.
 */

int maxCount(int *banned, int bannedSize, int n, int maxSum) {
  bool *valid = (bool *)malloc((n + 1) * sizeof(bool));
  memset(valid + 1, true, n * sizeof(bool));
  for (int i = 0; i < bannedSize; i++) {
    if (!(banned[i] >= 1 && banned[i] <= n))
      continue;
    valid[banned[i]] = false;
  }
  int cnt = 0, curr_sum = 0;
  for (int i = 1; i <= n; i++) {
    if (!valid[i])
      continue;
    if (!(curr_sum + i <= maxSum))
      break;
    cnt++, curr_sum += i;
  }
  free(valid);
  return cnt;
}

int main() {
  int b1[] = {1, 6, 5}, b2[] = {1, 2, 3, 4, 5, 6, 7}, b3[] = {11};
  printf("%d\n", maxCount(b1, ARRAY_SIZE(b1), 5, 6));  // expect: 2
  printf("%d\n", maxCount(b2, ARRAY_SIZE(b2), 8, 1));  // expect: 0
  printf("%d\n", maxCount(b3, ARRAY_SIZE(b3), 7, 50)); // expect: 7
}
