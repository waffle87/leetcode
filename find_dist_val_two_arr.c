// 1385. Find the Distance Value Between Two Arrays
#include "leetcode.h"

/*
 * given two integer arrays 'arr1' and 'arr2', and the integer 'd', return the
 * distance value between two arrays. the distance value is defined as the
 * number of elements 'arr1[i]' such that there is not any element 'arr2[j]'
 * where 'arr1[i] - arr2[j] <= d'.
 */

int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size,
                         int d) {
  int ans = 0;
  for (int i = 0; i < arr1Size; i++) {
    bool valid = false;
    for (int j = 0; j < arr2Size; j++) {
      if (abs(arr1[i] - arr2[j]) <= d) {
        valid = true;
        break;
      }
    }
    if (!valid)
      ans++;
  }
  return ans;
}

int main() {
  int a11[] = {4, 5, 8}, a21[] = {10, 9, 1, 8};
  int a12[] = {1, 4, 2, 3}, a22[] = {-4, -3, 6, 10, 20, 30};
  int a13[] = {2, 1, 100, 3}, a23[] = {-5, -2, 10, -3, 7};
  int r1 = findTheDistanceValue(a11, ARRAY_SIZE(a11), a21, ARRAY_SIZE(a21), 2);
  int r2 = findTheDistanceValue(a12, ARRAY_SIZE(a12), a22, ARRAY_SIZE(a22), 3);
  int r3 = findTheDistanceValue(a13, ARRAY_SIZE(a13), a23, ARRAY_SIZE(a23), 6);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 1);
}
