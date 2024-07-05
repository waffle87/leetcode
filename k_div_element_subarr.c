// 2261. K Divisible Elements Subarrays
#include "leetcode.h"

/*
 * given an integer array 'nums' and two integers 'k' and 'p', return the number
 * of distinct subarrays which have at most 'k' elements that are divisible by
 * 'p'. two arrays 'nums1' and 'nums2' ae said to be distinct if they are of
 * different lengths of there exists at least one index 'i' where 'nums1[i] !=
 * nums2[i]'. a subarray is defined as a non empty contiguous sequence of
 * elements in an array
 */

uint rs_hash(int *arr, int n) {
  uint a = 6368973, b = 378551, res = 0;
  for (int i = 0; i < n; i++) {
    res = res * a + arr[i];
    a *= b;
  }
  return res & 0x7FFFFFFF;
}

int countDistinct(int *nums, int numsSize, int k, int p) {
  int n = numsSize, n2 = n * n, l = 0, r = 0, items = 0, ans = 0;
  int **hash = (int **)calloc(n2, sizeof(int *));
  int *cnt = (int *)calloc(201, sizeof(int));
  for (r = 0; r < n; r++) {
    cnt[nums[r]]++;
    if (!(nums[r] % p))
      items++;
    while (items > k) {
      cnt[nums[l]]--;
      if (!(nums[l] % p))
        items--;
      l++;
    }
    for (int i = 0; i <= r; i++) {
      uint val = rs_hash(&nums[i], r - i + 1);
      int d = val;
      while (1) {
        if (!(hash[d % n2])) {
          hash[d % n2] = malloc(2 * sizeof(int));
          hash[d % n2][0] = val;
          hash[d % n2][1] = 1;
          ans++;
          break;
        } else {
          if (hash[d % n2][0] == val) {
            hash[d % n2][1]++;
            break;
          } else {
            d++;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  int n1[] = {2, 3, 3, 2, 2}, n2[] = {1, 2, 3, 4};
  printf("%d\n", countDistinct(n1, ARRAY_SIZE(n1), 2, 2)); // expect: 11
  printf("%d\n", countDistinct(n2, ARRAY_SIZE(n2), 4, 1)); // expect: 10
}
