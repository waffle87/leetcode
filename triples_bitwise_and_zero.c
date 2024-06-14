// 982. Triples with Bitwise AND Equal To Zero
#include "leetcode.h"

/*
 * given an integer array nums, return the number of AND triplets. an AND triple
 * is a triple of indices '(i, j, k)' such that '0 <= i < nums.length', '0 <= j
 * < nums.length', '0 <= k < nums.length', 'nums[i] & nums[j] & nums[k] == 0'
 * where '&' represents the bitwise AND operator
 */

int countTriplets(int *nums, int nums_size) {
  int ans = 0, n = nums_size;
  int *filled = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    filled[nums[i]]++;
    int cnt = 0;
    for (int j = 0; j <= i; j++)
      cnt += filled[j];
    if (cnt == i + 1)
      ans++;
  }
  free(filled);
  return ans;
}

int main() {
  int n1[] = {2, 1, 3}, n2[] = {0, 0, 0};
  printf("%d\n", countTriplets(n1, ARRAY_SIZE(n1))); // expect: 12
  printf("%d\n", countTriplets(n2, ARRAY_SIZE(n2))); // expect: 27
}
