// 2064. Minimized Maximum of Products Distributed to Any Store
#include "leetcode.h"

/*
 * you are given an integer 'n' indicating that there are 'n' specialty retail
 * stores. there are 'm' product types of varying amounts, which are given as a
 * 0-indexed integer array 'quantities' owhere 'quantities[i]' represents the
 * number of products of the i'th product type. you need to distribute all the
 * products to the retail stores following these rules: a store can only be
 * given at most one product type but can be given any amount of it, and after
 * distribution, each store will have been given some number products. let 'x'
 * represent the maximum number of products given to any store. you want 'x' to
 * be as small as possible. return the minimum possible 'x'.
 */

int minimizedMaximum(int n, int *quantities, int quantitiesSize) {
  long long sum = 0;
  int right = 0;
  for (int i = 0; i < quantitiesSize; ++i) {
    sum += quantities[i];
    if (right < quantities[i])
      right = quantities[i];
  }
  if (sum < n)
    return 1;
  int left = (int)(sum / n), mid = 0, groups = 0;
  while (left <= right) {
    mid = left + (right - left) / 2;
    groups = 0;
    for (int i = 0; i < quantitiesSize; i++)
      groups += (quantities[i] + mid - 1) / mid;
    if (groups <= n)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return left;
}

int main() {
  int q1[] = {11, 6}, q2[] = {15, 10, 10}, q3[] = {100000};
  printf("%d\n", minimizedMaximum(6, q1, ARRAY_SIZE(q1))); // expect: 3
  printf("%d\n", minimizedMaximum(7, q2, ARRAY_SIZE(q2))); // expect: 5
  printf("%d\n", minimizedMaximum(1, q3, ARRAY_SIZE(q3))); // expect: 100000
}
