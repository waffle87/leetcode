// 912. Sort an Array
#include <stdio.h>
#include <stdlib.h>

void quickSort(int *nums, int start, int end) {
  if (start >= end)
    return;
  int tmp = nums[start];
  int i = start, k = end;
  while (i < k) {
    for (k; nums[k] >= tmp && k > i; k--)
      ;
    nums[i] = nums[k];
    nums[k] = tmp;
    for (i; nums[i] <= tmp && i < k; i++)
      ;
    nums[k] = nums[i];
    nums[i] = tmp;
  }
  quickSort(nums, start, i - 1);
  quickSort(nums, k + 1, end);
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
  quickSort(nums, 0, numsSize - 1);
  *returnSize = numsSize;
  return nums;
}

int main() {
  int n1[] = {5, 2, 3, 1}, ns1 = 4, rs1[] = {4};
  int n2[] = {5, 1, 1, 2, 0, 0}, ns2 = 6, rs2[] = {6};
  printf("%p\n", sortArray(n1, ns1, rs1));
  printf("%p\n", sortArray(n2, ns2, rs2));
}
