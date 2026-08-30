// 2091. Removing Minimum and Maximum From Array
#include "leetcode.h"

/*
 * you are given a 0-indexed array of distinct integers 'nums'. there is an
 * element in 'nums' that has the lowest value and an element that has the
 * highest value. we call them the minimum and maximum respectively. your goal
 * is to remove both of these. a deletion is defined as either removing an
 * element from the front of the array or removing an element from the back of
 * the array. return the minimum number of minimumDeletions it would take to
 * remove both the minimum and maximum element from the array.
 */

int minimumDeletions(int *nums, int numsSize) {
  int xi = 0, ni = 0, xmax = nums[0], xmin = nums[0];
  for (int i = 1; i < numsSize; i++) {
    int x = nums[i];
    bool greater = x > xmax, less = x < xmin;
    xi += (-greater) & (i - xi);
    xmax += (-greater) & (x - xmax);
    ni += (-less) & (i - ni);
    xmin += (-less) & (x - xmin);
  }
  int i = fmin(ni, xi), j = ni + xi - i;
  return fmin(i + 1 + numsSize - j, fmin(j + 1, numsSize - i));
}

int main() {
  int n1[] = {2, 10, 7, 5, 4, 1, 8, 6};
  int n2[] = {0, -4, 19, 1, 8, -2, -3, 5};
  int n3[] = {101};
  int r1 = minimumDeletions(n1, ARRAY_SIZE(n1));
  int r2 = minimumDeletions(n2, ARRAY_SIZE(n2));
  int r3 = minimumDeletions(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 1);
}
