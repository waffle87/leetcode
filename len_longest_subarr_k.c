// 2958. Length of Longest Subarray With at Most K Frequency
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k'. the frequency of an element
 * x is the number of times it occurs in an array. an array is called good if
 * the frequency of each element in this array is less than or equal to 'k'.
 * return the length of the longest good subarray of 'nums' a subarray is a
 * contiguous non empty sequence of elements within an array
 */

typedef struct {
  UT_hash_handle hh;
  int num;
  int cnt;
} h_elem;

int maxSubarrayLength(int *nums, int numsSize, int k) {
  h_elem *freq = NULL, *t, *s;
  int left = 0, more = 0;
  for (int right = 0; right < numsSize; right++) {
    HASH_FIND_INT(freq, &nums[right], t);
    if (t) {
      t->cnt++;
    } else {
      t = calloc(sizeof(h_elem), 1);
      t->num = nums[right];
      t->cnt = 1;
      HASH_ADD_INT(freq, num, t);
    }
    if (t->cnt == k + 1)
      more++;
    if (more) {
      HASH_FIND_INT(freq, &nums[left], s);
      s->cnt--;
      if (s->cnt == k)
        more--;
      left++;
    }
  }
  return numsSize - left;
}

int main() {
  int n1[] = {1, 2, 3, 1, 2, 3, 1, 2};
  int n2[] = {1, 2, 1, 2, 1, 2, 1, 2};
  int n3[] = {5, 5, 5, 5, 5, 5, 5};
  int r1 = maxSubarrayLength(n1, ARRAY_SIZE(n1), 2);
  int r2 = maxSubarrayLength(n2, ARRAY_SIZE(n2), 1);
  int r3 = maxSubarrayLength(n3, ARRAY_SIZE(n3), 4);
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 4);
}
