// 852. Peak Index in a Mountain Array
#include <stdio.h>

int peakIndexInMountainArray(int *arr, int arr_size) {
  int left = 1, right = arr_size - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] < arr[mid + 1])
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int main() {
  int a1[] = {0, 1, 0}, a2[] = {0, 2, 1, 0}, a3[] = {0, 10, 5, 2};
  printf("%d\n", peakIndexInMountainArray(a1, 3)); // expect: 1
  printf("%d\n", peakIndexInMountainArray(a2, 4)); // expect: 1
  printf("%d\n", peakIndexInMountainArray(a3, 4)); // expect: 1
}
