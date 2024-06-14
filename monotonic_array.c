// 896. Monotonic Array
#include <stdbool.h>
#include <stdio.h>

/*
 * an array is monotonic if it is either monotone increasing or monotone
 * decreasing. an array 'nums' is monotone increasing if for all 'i <= j,
 * nums[i] <= nums[j]'. an array 'nums' is monotone decreasing if for all 'i <=
 * j, nums[i] >= nums[j]'. given an integer array 'nums', return 'true' if the
 * given array is monotonic, or 'false' otherwise.
 */

bool isMonotonic(int *nums, int nums_size) {
  int idx = 1;
  while (idx + 1 < nums_size) {
    if (nums[idx - 1] < nums[idx]) {
      while (idx + 1 < nums_size && nums[idx] == nums[idx + 1])
        idx++;
      if (idx + 1 < nums_size && nums[idx] > nums[idx + 1])
        return false;
    }
    if (nums[idx - 1] > nums[idx]) {
      while (idx + 1 < nums_size && nums[idx] == nums[idx + 1])
        idx++;
      if (idx + 1 < nums_size && nums[idx] < nums[idx + 1])
        return false;
    }
    idx++;
  }
  return true;
}

int main() {
  int n1[] = {1, 2, 2, 3}, n2[] = {6, 5, 4, 4}, n3[] = {1, 3, 2};
  printf("%d\n", isMonotonic(n1, 4)); // expect: 1
  printf("%d\n", isMonotonic(n2, 4)); // expect: 1
  printf("%d\n", isMonotonic(n3, 3)); // expect: 0
}
