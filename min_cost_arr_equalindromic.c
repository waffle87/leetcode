// 2967. Minimum Cost to Make Array Equalindromic
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums' having length 'n'. you are
 * allowed to perform a special move any number of times on 'nums'. in one
 * special move, you perform the following steps in order: choose an index 'i'
 * in the range '[0, n - 1]' and a positive integer 'x', add '|nums[i] - x|' to
 * the total cost, and change the value of 'nums[i]' to 'x'. a palindromic
 * number is a positive integer that remains the same when its digits are
 * reversed. an array is considered equalindromic if all the elements in the
 * array are equal to an integer 'y', where 'y' is a palindromic number less
 * than 10^9. return an integer denoting the minimum possible total cost to make
 * 'nums' equalindromic by performing any number of special moves
 */

bool is_palindrome(int num) {
  if (num < 0)
    return false;
  int reverse = 0, original = num;
  while (num) {
    int digit = num % 10;
    if (reverse > (INT_MAX - digit) / 10)
      return false;
    reverse = reverse * 10 + digit;
    num /= 10;
  }
  return reverse == original;
}

long long calculate_cost(int *nums, int numsSize, int target) {
  long long cost = 0;
  for (int i = 0; i < numsSize; i++)
    cost += abs(nums[i] - target);
  return cost;
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long minimumCost(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int median = nums[numsSize / 2];
  int lower = median - 100000, upper = median + 100000;
  if (lower < 1)
    lower = 1;
  if (upper > 1000000000)
    upper = 1000000000;
  long long min_cost = LLONG_MAX;
  for (int i = 0; i <= upper; i++)
    if (is_palindrome(i)) {
      long long curr_cost = calculate_cost(nums, numsSize, i);
      if (curr_cost < min_cost)
        min_cost = curr_cost;
    }
  return min_cost;
}

int main() {
  int n1[] = {1, 2, 3, 4, 5}, n2[] = {10, 12, 13, 14, 15},
      n3[] = {22, 33, 22, 33, 22};
  printf("%lld\n", minimumCost(n1, ARRAY_SIZE(n1))); // expect: 6
  printf("%lld\n", minimumCost(n2, ARRAY_SIZE(n2))); // expect: 11
  printf("%lld\n", minimumCost(n3, ARRAY_SIZE(n3))); // expect: 22
}
