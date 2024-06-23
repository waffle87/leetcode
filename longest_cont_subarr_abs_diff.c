// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
// Limit
#include "leetcode.h"

/*
 * given an array of integers 'nums' and an integer 'limit', return the size of
 * the longest non empty subarray such that the absolute difference between any
 * two elements of this subarrays is less than equal or equal to 'limit'
 */

int longestSubarray(int *nums, int numsSize, int limit) {
  int n = numsSize, r = 0, l = 0, ans = 0, m_front = 0, m_end = 0, _m_front = 0,
      _m_end = 0;
  int *m_queue = (int *)malloc(n * sizeof(int));
  int *_m_queue = (int *)malloc(n * sizeof(int));
  for (r = 0; r < n; r++) {
    while (_m_end > _m_front && nums[r] < _m_queue[_m_end - 1])
      _m_end--;
    while (m_end > m_front && nums[r] > m_queue[m_end - 1])
      m_end--;
    _m_queue[_m_end++] = nums[r];
    m_queue[m_end++] = nums[r];
    while ((m_queue[m_front] - _m_queue[_m_front]) > limit) {
      if (m_queue[m_front] == nums[l])
        m_front++;
      if (_m_queue[_m_front] == nums[l])
        _m_front++;
      l++;
    }
    ans = fmax(ans, r - l + 1);
  }
  free(m_queue), free(_m_queue);
  return ans;
}

int main() {
  int n1[] = {8, 2, 4, 7}, n2[] = {10, 1, 2, 4, 7, 2},
      n3[] = {4, 2, 2, 2, 4, 4, 2, 2};
  printf("%d\n", longestSubarray(n1, ARRAY_SIZE(n1), 4)); // expect: 2
  printf("%d\n", longestSubarray(n2, ARRAY_SIZE(n2), 5)); // expect: 4
  printf("%d\n", longestSubarray(n3, ARRAY_SIZE(n3), 0)); // expect: 3
}
