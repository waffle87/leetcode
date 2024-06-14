// 1262. Greatest Sum Divisible by Three
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'nums', return the maximum possible sum of elements of
 * the array such that it is divisible by three
 */

int maxSumDivThree(int *nums, int nums_size) {
  int sum = 0, oneone = INT_MAX, onetwo = INT_MAX, twoone = INT_MAX,
      twotwo = INT_MAX, rem = 0;
  for (int i = 0; i < nums_size; i++) {
    sum += nums[i];
    rem += nums[i] % 3;
    if (nums[i] % 3 == 1) {
      if (nums[i] <= oneone) {
        onetwo = oneone;
        oneone = nums[i];
      } else if (nums[i] < onetwo)
        onetwo = nums[i];
    } else if (nums[i] % 3 == 2) {
      if (nums[i] <= twoone) {
        twotwo = twoone;
        twoone = nums[i];
      } else if (nums[i] < twotwo)
        twotwo = nums[i];
    }
  }
  rem %= 3;
  if (rem == 1) {
    if (oneone != INT_MAX && twoone != INT_MAX && twotwo != INT_MAX)
      return sum - fmin(oneone, twoone + twotwo);
    else if (oneone != INT_MAX)
      return sum - oneone;
    else
      return 0;
  } else if (rem == 2) {
    if (oneone != INT_MAX && onetwo != INT_MAX && twoone != INT_MAX)
      return sum - fmin(oneone + onetwo, twoone);
    else if (twoone != INT_MAX)
      return sum - twoone;
    else if (oneone != INT_MAX && onetwo != INT_MAX)
      return sum - oneone - onetwo;
    else
      return 0;
  } else
    return sum;
}

int main() {
  int n1[] = {3, 6, 5, 1, 8}, n2[] = {4}, n3[] = {1, 2, 3, 4, 4};
  printf("%d\n", maxSumDivThree(n1, 5)); // expect: 18
  printf("%d\n", maxSumDivThree(n2, 1)); // expect: 0
  printf("%d\n", maxSumDivThree(n3, 5)); // expect: 12
}
