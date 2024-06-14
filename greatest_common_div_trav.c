// 2709. Greatest Common Divisor Traversal
#include "leetcode.h"

/*
 * given a 0-indexed integer array 'nums' and you are allowed to traverse
 * between its indices, you can traverse between index 'i' and index 'j', 'i !=
 * j' if and only if 'gcd(nums[i], nums[j]) > 1' where 'gcd' is the greatest
 * common divisor. your task is to determine if for every pair of indices 'i'
 * and 'j' in 'nums' where 'i < j', there exists a sequence of traversals that
 * can take use from 'i' to 'j'. return true if it is possible to traverse
 * between all such pairs of indices or false otherwise.
 */

bool canTraverseAllPairs(int *nums, int numsSize) {}

int main() {
  int n1[] = {2, 3, 6}, n2[] = {3, 9, 5}, n3[] = {4, 3, 12, 8};
  printf("%d\n", canTraverseAllPairs(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", canTraverseAllPairs(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", canTraverseAllPairs(n3, ARRAY_SIZE(n3))); // expect: 1
}
