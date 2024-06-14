// 2593. Find Score of an Array After Marking All Elements
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'nums' consisting of positive integers. starting with 'score =
 * 0', apply the following algorithm
 * - choose the smallest integer of the array that is not marked. if there is a
 * tie, choose the one with the smallest index
 * - add the value of the chosen integer to 'score'
 * - mark the chosen element and its two adjacent elements if they exist
 * - repeat until all the array elements are marked
 * return the score you get after applying the above algorithm
 */

struct pair {
  int val;
  int idx;
};

int cmp(const void *a, const void *b) {
  const struct pair p_a = *(const struct pair *)a;
  const struct pair p_b = *(const struct pair *)b;
  if (p_a.val == p_b.val)
    return p_a.idx - p_b.idx;
  return p_a.val - p_b.val;
}

long long findScore(int *nums, int nums_size) {
  if (nums_size == 1)
    return (long long)nums[0];
  struct pair *arr = (struct pair *)calloc(nums_size, sizeof(struct pair));
  bool *is_marked = (bool *)calloc(nums_size, sizeof(bool));
  for (int i = 0; i < nums_size; i++) {
    arr[i].val = nums[i];
    arr[i].idx = i;
  }
  qsort(arr, nums_size, sizeof(struct pair), cmp);
  long long ans = 0;
  for (int i = 0; i < nums_size; i++)
    if (!is_marked[arr[i].idx]) {
      ans += arr[i].val;
      if (arr[i].idx + 1 < nums_size)
        is_marked[arr[i].idx + 1] = true;
      if (arr[i].idx - 1 >= 0)
        is_marked[arr[i].idx - 1] = true;
    }
  free(arr), free(is_marked);
  return ans;
}

int main() {
  int n1[] = {2, 1, 3, 4, 5, 2}, n2[] = {2, 3, 5, 1, 3, 2};
  printf("%lld\n", findScore(n1, 6)); // expect: 7
  printf("%lld\n", findScore(n2, 6)); // expect: 5
}
