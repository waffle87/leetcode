// 1713. Minimum Operations to Make a Subsequence
#include "leetcode.h"

/*
 * given an array 'target' that consists of distinct integers and another
 * integer array 'arr' that can have duplicates. in one operatioin, you can
 * insert any integer at any position in 'arr'. note that you can inser the
 * integer at the very beginning or end of the array. return the minimum number
 * of operations needed to make 'target' a subsequence of 'arr'. a subsequence
 * of anarray is a new array generated from the original array by deleting some
 * elements (possibly none) without changing the remaining elements.
 */

int cmp(const void *a, const void *b) {
  int *a1 = *(int **)a;
  int *b1 = *(int **)b;
  return a1[1] - b1[1];
}

int binary_search(int *nums, int n, int val) {
  int left = 0, right = n - 1, mid;
  if (val <= nums[0])
    return 0;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (nums[mid] == val)
      return mid;
    if (nums[mid] > val)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int bfs(int **nums, int n, int val) {
  int left = 0, right = n - 1, mid;
  if (val < nums[0][1] || val > nums[n - 1][1])
    return -1;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (nums[mid][1] == val)
      return nums[mid][0];
    if (nums[mid][1] > val)
      right = mid - 1;
    else
      left = mid + 1;
  }
  if (nums[left][1] == val)
    return nums[left][0];
  return -1;
}

int minOperations(int *target, int targetSize, int *arr, int arrSize) {
  int t = targetSize, a = arrSize, idx = 0;
  int **copy_target = (int **)malloc(t * sizeof(int *));
  for (int i = 0; i < t; i++) {
    copy_target[i] = malloc(2 * sizeof(int));
    copy_target[i][0] = i;
    copy_target[i][1] = target[i];
  }
  qsort(copy_target, t, sizeof(int *), cmp);
  for (int i = 0; i < a; i++) {
    int pos = bfs(copy_target, t, arr[i]);
    if (pos != -1) {
      arr[idx] = pos;
      idx++;
    }
  }
  if (!idx)
    return t;
  int *stack = (int *)malloc(idx * sizeof(int));
  stack[0] = arr[0];
  int s_idx = 1;
  for (int i = 1; i < idx; i++)
    if (arr[i] > stack[s_idx - 1]) {
      stack[s_idx] = arr[i];
      s_idx++;
    } else {
      int x = binary_search(stack, s_idx, arr[i]);
      stack[x] = arr[i];
    }
  free(copy_target), free(stack);
  return t - s_idx;
}

int main() {
  int t1[] = {5, 1, 3}, t2[] = {6, 4, 8, 1, 3, 2}, a1[] = {9, 4, 2, 3, 4},
      a2[] = {4, 7, 6, 2, 3, 8, 6, 1};
  printf("%d\n",
         minOperations(t1, ARRAY_SIZE(t1), a1, ARRAY_SIZE(a1))); // expect: 2
  printf("%d\n",
         minOperations(t2, ARRAY_SIZE(t2), a2, ARRAY_SIZE(a2))); // expect: 3
}
