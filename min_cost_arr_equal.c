// 2448. Minimum Cost to Make Array Equal
#include <stdio.h>
#include <stdlib.h>

/*
 * given two 0-indexed arrays 'nums' and 'cost' consisting each of 'n' positive
 * integers. you can do the following operation any number of times:
 * - increase or decrease any element of the array 'nums' by 1
 * the cost of doing one operation on the i'th element is 'cost[i]'. return the
 * minimum total cost such that all the elements of the array 'nums' become
 * equal
 */

long long helper(int *nums, int nums_size, int *cost, int mid) {
  long long sum = 0;
  for (int i = 0; i < nums_size; i++) {
    long long k = abs(nums[i] - mid);
    sum += k * cost[i];
  }
  return sum;
}

long long minCost(int *nums, int nums_size, int *cost, int cost_size) {
  long long low = 1, high = 1e6;
  while (low <= high) {
    int mid = (low + high) / 2;
    long long y1 = helper(nums, nums_size, cost, mid);
    if (low == high)
      return y1;
    long long y2 = helper(nums, nums_size, cost, mid + 1);
    long long y3 = helper(nums, nums_size, cost, mid - 1);
    if (y2 >= y1 && y1 <= y3)
      return y1;
    if (y2 < y1) {
      high = mid;
      continue;
    }
    if (y3 < y1) {
      low = mid;
      continue;
    }
  }
  return 0;
}

int main() {
  int n1[] = {1, 3, 5, 2}, c1[] = {2, 3, 1, 14};
  int n2[] = {2, 2, 2, 2, 2}, c2[] = {4, 2, 8, 1, 3};
  printf("%lld\n", minCost(n1, 4, c1, 4)); // expect: 8
  printf("%lld\n", minCost(n2, 5, c2, 5)); // expect: 0
}
