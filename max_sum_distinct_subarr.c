// 2461. Maximum Sum of Distinct Subarrays With Length K
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and an integer 'k'. find the maximum
 * subarray sum of all the subarrays of 'nums' that meet the following
 * conditions. the length of the subarray is 'k' and all the elements of the
 * subarray are distinct. return the maximum subarray of all the subarrays that
 * meet the conditions. if no subarray meets the conditions, return 0. a
 * subarray is a contiguous non empty sequence of elements within an array
 */

typedef struct {
  UT_hash_handle hh;
  int num;
  int cnt;
} hElem;

long long maximumSubarraySum(int *nums, int numsSize, int k) {
  hElem *map = NULL, *s, *t;
  long long ans = 0, curr = 0;
  int i = 0;
  while (i < k && i < numsSize) {
    HASH_FIND_INT(map, &nums[i], t);
    if (!t) {
      t = calloc(sizeof(hElem), 1);
      t->num = nums[i];
      HASH_ADD_INT(map, num, t);
    }
    t->cnt++;
    curr += nums[i];
    i++;
  }
  if (HASH_COUNT(map) == k)
    ans = curr;
  while (i < numsSize) {
    HASH_FIND_INT(map, &nums[i], t);
    if (!t) {
      t = calloc(sizeof(hElem), 1);
      t->num = nums[i];
      HASH_ADD_INT(map, num, t);
    }
    t->cnt++;
    int diff = nums[i - k];
    HASH_FIND_INT(map, &diff, s);
    if (s) {
      s->cnt--;
      if (!s->cnt) {
        HASH_DEL(map, s);
        free(s);
      }
    }
    curr += nums[i];
    curr -= nums[i - k];
    if (HASH_COUNT(map) == k)
      ans = fmax(ans, curr);
    i++;
  }
  return ans;
}

int main() {
  int n1[] = {1, 5, 4, 2, 9, 9, 9}, n2[] = {4, 4, 4};
  printf("%lld\n", maximumSubarraySum(n1, ARRAY_SIZE(n1), 3)); // expect: 15
  printf("%lld\n", maximumSubarraySum(n2, ARRAY_SIZE(n2), 3)); // expect: 0
}
