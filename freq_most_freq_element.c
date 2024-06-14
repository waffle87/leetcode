// 1838. Frequency of the Most Frequent Element
#include "leetcode.h"

/*
 * the frequency of an element is the number of times it occurs in an array. you
 * are given an integer array 'nums' and an integer 'k'. in one operation, you
 * can shoose an index of 'nums' and increment the element at the index by 1.
 * return the maximum possible frequency of an element after performing at most
 * 'k' operations
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maxFrequency(int *nums, int nums_size, int k) {
  int left = 0, right = 0;
  qsort(nums, nums_size, sizeof(int), cmp);
  long long *dp = malloc((nums_size + 1) * sizeof(long long));
  dp[0] = 0;
  for (int i = 1; i < nums_size; i++)
    dp[i] = nums[i - 1] + dp[i - 1];
  long long opt = 0;
  while (right < nums_size - 1) {
    right++;
    opt = (long long)nums[right] * (right - left + 1) -
          (dp[right + 1] - dp[left]);
    if (opt > k)
      left++;
  }
  free(dp);
  return right - left + 1;
}

int main() {
  int n1[] = {1, 2, 4}, n2[] = {1, 4, 8, 13}, n3[] = {3, 9, 6};
  printf("%d\n", maxFrequency(n1, ARRAY_SIZE(n1), 5)); // expect: 3
  printf("%d\n", maxFrequency(n2, ARRAY_SIZE(n2), 5)); // expect: 2
  printf("%d\n", maxFrequency(n3, ARRAY_SIZE(n3), 2)); // expect: 1
}
