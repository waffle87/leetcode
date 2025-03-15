// 2560. House Robber IV
#include "leetcode.h"

/*
 * there are several consecutive houses along a street, each of which has some
 * money inside. there is also a robber, who wants to steal money from the
 * homes, but he refuses to steal from adjacent homes. the capability of the
 * robber is the maximum amount of money he steals from one house of all the
 * houses he robbed. you are given an integer array 'nums' representing how much
 * money is stahsed in each house. more formally, the i'th house from the left
 * has 'nums[i]' dollars. you are also given an integer 'k', representing the
 * minimum number of houses the robber will steal from. it is always possible to
 * steal at least 'k' houses. return the minimum possible capability of the
 * robber out of all the possible ways to steal at least 'k' houses.
 */

int minCapability(int *nums, int numsSize, int k) {
  int left = 1, right = 1e9;
  while (left < right) {
    int mid = (left + right) / 2, take = 0;
    for (int i = 0; i < numsSize; i++)
      if (nums[i] <= mid)
        take++, i++;
    if (take >= k)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main() {
  int n1[] = {2, 3, 5, 9}, n2[] = {2, 7, 9, 3, 1};
  printf("%d\n", minCapability(n1, ARRAY_SIZE(n1), 2)); // expect: 5
  printf("%d\n", minCapability(n2, ARRAY_SIZE(n2), 2)); // expect: 2
}
