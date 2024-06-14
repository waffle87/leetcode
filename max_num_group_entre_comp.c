// 2358. Maximum Number of Groups Entering a Competition
#include "leetcode.h"
/*
 * given a positive integer array 'grades' which represents the grades of
 * students in a university. you would like to entre all these students into a
 * competition in orderd non empty groups such that the ordering meets the
 * following requirements. the sum of the grades of students in the i'th group
 * is less than the sum of the grades of students in the '(i +1)'th group for
 * all groups except last. the total number of students in the i'th group is
 * less than the total number of students in the i'th group is less than the
 * gtotal numboer of students in the '(i + 1)'th group, for all groups. return
 * the maximum numberof groups that can be formed.
 */

int maximumGroups(int *grades, int gradesSize) {
  int left = 1, right = gradesSize / 2 + 1, mid, sum;
  while (left < right) {
    mid = right - (right - left) / 2;
    sum = (1 + mid) * mid / 2;
    if (sum == gradesSize)
      return mid;
    if (sum > gradesSize)
      right = mid - 1;
    else
      left = mid;
    ;
  }
  return left;
}

int main() {
  int g1[] = {10, 6, 12, 7, 3, 5}, g2[] = {8, 8};
  printf("%d\n", maximumGroups(g1, ARRAY_SIZE(g1))); // expect: 3
  printf("%d\n", maximumGroups(g2, ARRAY_SIZE(g2))); // expect: 1
}
