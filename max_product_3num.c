// 628. Maximum Product of Three Numbers
#include <limits.h>
#include <math.h>
#include <stdio.h>

/*
 * given an integer array 'nums', find three numbers whose product is maximum
 * and return the maximum product
 */

int maximumProduct(int *nums, int nums_size) {
  int min1, min2, max1, max2, max3, num;
  min1 = min2 = INT_MAX;
  max1 = max2 = max3 = INT_MIN;
  for (int i = 0; i < nums_size; i++) {
    num = nums[i];
    if (min1 >= num) {
      min2 = min1;
      min1 = num;
    } else if (min2 >= num) {
      min2 = num;
    }
    if (max1 <= num) {
      max3 = max2;
      max2 = max1;
      max1 = num;
    } else if (max2 <= num) {
      max3 = max2;
      max2 = num;
    } else if (max3 <= num) {
      max3 = num;
    }
  }
  return fmax(min1 * min2 * max1, max1 * max2 * max3);
}

int main() {
  int n1[] = {1, 2, 3}, n2[] = {1, 2, 3, 4}, n3[] = {-1, -2, -3};
  printf("%d\n", maximumProduct(n1, 3)); // expect: 6
  printf("%d\n", maximumProduct(n2, 4)); // expect: 24
  printf("%d\n", maximumProduct(n3, 3)); // expect: -6
}
