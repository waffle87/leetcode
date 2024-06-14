// 2148. Count Elements With Strictly Smaller and Greater Elements
#include <stdio.h>
#include <stdlib.h>

/*
 * given integer array 'nums', return number of elements that have both a
 * strictly smaller and strictly greater element appear in 'nums'
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int countElements(int *nums, int numsSize) {
  if (numsSize == 1)
    return 0;
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0;
  for (int i = 1; i + 1 < numsSize; i++) {
    int front = i + 1, back = i - 1;
    if (nums[i] == nums[back])
      while (back > 0 && nums[i] == nums[back])
        back--;
    if (nums[i] == nums[front])
      while (front < numsSize - 1 && nums[i] == nums[front])
        front++;
    if (nums[i] < nums[front] && nums[i] > nums[back])
      ans++;
  }
  return ans;
}

int main() {
  int nums1[] = {11, 7, 2, 15}, nums2[] = {-3, 3, 3, 90};
  printf("%d\n", countElements(nums1, 4)); // expect: 2
  printf("%d\n", countElements(nums2, 4)); // expect: 2
}
