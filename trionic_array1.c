// 3637. Trionic Array I
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. an array is trionic if
 * there exist indices '0 < p < q < n - 1' such that 'nums[0 ... p]' is strictly
 * increasing, 'nums[p ... q]' is strictly decreasing, and  'nums[q ... n - 1]'
 * is strictly increasing. return true if 'nums' is trionic, otherwise return
 * false.
 */

bool isTrionic(int *nums, int numsSize) {
  if (numsSize < 4)
    return false;
  int trans[4][2] = {{1, 4}, {1, 2}, {3, 2}, {3, 4}};
  int state = 0;
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1])
      return false;
    int input = (nums[i] > nums[i - 1]) ? 0 : 1;
    state = (state < 4) ? trans[state][input] : 4;
    if (state == 4)
      return false;
  }
  return state == 3;
}

int main() {
  int n1[] = {1, 3, 5, 4, 2, 6}, n2[] = {2, 1, 3};
  bool r1 = isTrionic(n1, ARRAY_SIZE(n1));
  bool r2 = isTrionic(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1); // expect: 1
  assert(r1 == true);
  printf("%d\n", r2); // expect: 0
  assert(r2 == false);
}
