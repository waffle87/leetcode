// 2601. Prime Subtraction Operation
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums' of length 'n'. you can perform the
 * following operation as many times as you want: pick an index 'i' that you
 * have not picked before, and pick a prime 'p' strictly less than 'nums[i]'
 * then subtract 'p' from 'nums[i]'. return true if you can make 'nums' a
 * strictly increasing array using the above operation, and false otherwise. a
 * strictly increasing array is an array whose each element is strictly greater
 * than its precedingelement
 */

bool prime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

bool primeSubOperation(int *nums, int numsSize) {
  for (int i = numsSize - 2; i >= 0; i--) {
    if (nums[i] >= nums[i + 1]) {
      int diff = nums[i] - nums[i + 1];
      diff++;
      while (1) {
        if (prime(diff))
          break;
        diff++;
      }
      if (diff >= nums[i])
        return false;
      nums[i] -= diff;
    }
  }
  return true;
}

int main() {
  int n1[] = {4, 9, 6, 10}, n2[] = {6, 8, 11, 12}, n3[] = {5, 8, 3};
  printf("%d\n", primeSubOperation(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", primeSubOperation(n2, ARRAY_SIZE(n2))); // expect: 1
  printf("%d\n", primeSubOperation(n3, ARRAY_SIZE(n3))); // expect: 0
}
