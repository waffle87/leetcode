// 493. Reverse Pairs
#include "leetcode.h"

/*
 * given an integer array 'nums', return the number of reverse pairs in the
 * array. a reverse pair is a pair '(i, j)' where '0 <= i < j < nums.len' and
 * 'nums[i] > 2 * nums[j]'
 */

int merge_cnt(int *arr, int *tmp, int left, int mid, int right) {
  int i = left, j = mid + 1, k = left, cnt = 0;
  while (i <= mid && j <= right) {
    if ((long long)arr[i] > 2 * (long long)arr[j]) {
      cnt += (mid - i + 1);
      j++;
    } else
      i++;
  }
  i = left;
  j = mid + 1;
  while (i <= mid && j <= right)
    tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
  while (i <= mid)
    tmp[k++] = arr[i++];
  while (j <= right)
    tmp[k++] = arr[j++];
  for (int l = left; l <= right; l++)
    arr[l] = tmp[l];
  return cnt;
}

int sort_merge_cnt(int *arr, int *tmp, int left, int right) {
  int cnt = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;
    cnt += sort_merge_cnt(arr, tmp, left, mid);
    cnt += sort_merge_cnt(arr, tmp, mid + 1, right);
    cnt += merge_cnt(arr, tmp, left, mid, right);
  }
  return cnt;
}

int reversePairs(int *nums, int numsSize) {
  int *tmp = (int *)malloc(numsSize * sizeof(int));
  return sort_merge_cnt(nums, tmp, 0, numsSize - 1);
}

int main() {
  int n1[] = {1, 3, 2, 3, 1}, n2[] = {2, 4, 3, 5, 1};
  printf("%d\n", reversePairs(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", reversePairs(n2, ARRAY_SIZE(n2))); // expect: 3
}
