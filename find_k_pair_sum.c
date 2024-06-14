// 373. Find K Pairs with Smallest Sums
#include <stdio.h>
#include <stdlib.h>

/*
 * given two integer arrays 'nums1 nums2' sorted in ascending order and an
 * integer k. define a pair '(u, v)' which consists of one element from the
 * first array and one element from the second array. return the 'k' pairs '(u1,
 * v1), (u2, v2), ..., (uk, vk)' with the smallest sums
 */

long long count_less_equal_items(int val, int *nums1, int n1, int *nums2,
                                 int n2) {
  long long res = 0;
  for (int i = 0; i < n1; i++) {
    int k = val - nums1[i];
    int l = 0, r = n2 - 1;
    if (nums2[0] > k)
      break;
    while (l < r) {
      int mid = r - (r - l) / 2;
      if (nums2[mid] > k)
        r = mid - 1;
      else
        l = mid;
    }
    res += (l + 1);
  }
  return res;
}

int **kSmallestPairs(int *nums1, int nums1_size, int *nums2, int nums2_size,
                     int k, int *return_size, int **return_col_size) {
  int n1 = nums1_size, n2 = nums2_size;
  int lower = nums1[0] + nums2[0];
  int upper = nums1[n1 - 1] + nums2[n2 - 1];
  while (lower < upper) {
    int mid = lower + (upper - lower) / 2;
    long long t = count_less_equal_items(mid, nums1, n1, nums2, n2);
    if (t >= k)
      upper = mid;
    else
      lower = mid + 1;
  }
  int **ans = malloc(k * sizeof(int *));
  for (int i = 0; i < k; i++)
    ans[i] = malloc(2 * sizeof(int));
  int **tmp = malloc(k * sizeof(int *));
  int a_idx = 0, t_idx = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      int sum = nums1[i] + nums2[j];
      if (sum < lower) {
        ans[a_idx][0] = nums1[i];
        ans[a_idx][1] = nums2[j];
        a_idx++;
      } else if (sum == lower) {
        if (t_idx == k)
          break;
        tmp[t_idx] = malloc(2 * sizeof(int));
        tmp[t_idx][0] = nums1[i];
        tmp[t_idx][1] = nums2[j];
        t_idx++;
      } else
        break;
    }
  }
  int a = 0;
  if (a_idx < k) {
    for (int i = a_idx; i < k; i++) {
      if (a == t_idx)
        break;
      ans[a_idx][0] = tmp[a][0];
      ans[a_idx][1] = tmp[a][1];
      a++;
      a_idx++;
    }
  }
  *return_size = a_idx;
  *return_col_size = malloc(a_idx * sizeof(int));
  for (int i = 0; i < a_idx; i++)
    return_col_size[0][i] = 2;
  for (int i = 0; i < t_idx; i++)
    free(tmp[i]);
  free(tmp);
  return ans;
}
