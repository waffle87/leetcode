// 1726. Tuple with Same Product
#include "leetcode.h"

/*
 * given an array 'nums' of distinct positive integers return the number of
 * tuples '(a,b,c,d)' such that 'a * b = c * d' where 'a,b,c,d' are elements of
 * 'nums' and 'a != b != c != d'
 */

int tupleSameProduct(int *nums, int numsSize) {
  int ans = 0, *cnt = (int *)calloc(9999999, sizeof(int));
  for (int i = 0; i < numsSize; i++)
    for (int j = 0; j < i; j++) {
      const int product = nums[i] * nums[j];
      ans += cnt[product];
      cnt[product]++;
    }
  free(cnt);
  return ans * 8;
}

int main() {
  int n1[] = {2, 3, 4, 6}, n2[] = {1, 2, 4, 5, 10};
  printf("%d\n", tupleSameProduct(n1, ARRAY_SIZE(n1))); // expect: 8
  printf("%d\n", tupleSameProduct(n2, ARRAY_SIZE(n2))); // expect: 16
}
