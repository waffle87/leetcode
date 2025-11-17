// 1437. Check If All 1's Are at Least Length K Places Away
#include "leetcode.h"

/*
 * given a binary array 'nums' and an integer 'k', return true if all 1s are at
 * least 'k' places away from eachother, otherwise return false.
 */

bool kLengthApart(int *nums, int numsSize, int k) {
  int prev = -1;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 1) {
      if (prev != -1 && (i - prev - 1) < k)
        return false;
      prev = i;
    }
  }
  return true;
}

int main() {
  int n1[] = {1, 0, 0, 0, 1, 0, 0, 1}, n2[] = {1, 0, 0, 1, 0, 1};
  printf("%d\n", kLengthApart(n1, ARRAY_SIZE(n1), 2)); // expect: 1
  printf("%d\n", kLengthApart(n2, ARRAY_SIZE(n2), 2)); // expect: 0
}
