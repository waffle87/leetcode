// 704. Binary Search
#include <stdio.h>

int search(int *nums, int nums_size, int target) {
  int low = 0, high = nums_size - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  int nums[] = {-1, 0, 3, 5, 9, 12};
  printf("%d\n", search(nums, 6, 9)); // expect: 4
  printf("%d\n", search(nums, 6, 2)); // expect: -1
}
