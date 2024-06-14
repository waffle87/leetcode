// 1011. Capacity To Ship Packages Within D Days
#include <limits.h>
#include <stdio.h>

/*
 * a conveyor belt has packages that must be shipped from one port to another
 * within 'days' days. the i'th package on the conveyor belt has a weight of
 * 'weights[i]'. each day, the ship is loaded with packages on the conveyor belt
 * (in order given by 'weights'). we may not load more weight than the maximum
 * capacity of the ship. resurn the least weight capacity of the ship that will
 * result in all the packages on the conveyor belt being shipped within 'days'
 * days.
 */

int countDays(int *nums, int numsSize, int capacity) {
  int res = 1, k = capacity;
  for (int i = 0; i < numsSize; i++) {
    k -= nums[i];
    if (k < 0) {
      res++;
      k = capacity - nums[i];
    }
  }
  return res;
}

int max(int *nums, int numsSize) {
  int max = INT_MIN;
  for (int i = 0; i < numsSize; i++)
    if (nums[i] > max)
      max = nums[i];
  return max;
}

int shipWithinDays(int *weights, int weightsSize, int days) {
  int left = max(weights, weightsSize);
  int right = INT_MAX - left;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (countDays(weights, weightsSize, mid) <= days)
      right = mid;
    else
      left = mid + 1;
  }
  mid = (left + right) / 2;
  return mid;
}

int main() {
  int weights1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, days1 = 5, ws1 = 10;
  int weights2[] = {3, 2, 2, 4, 1, 4}, days2 = 3, ws2 = 6;
  int weights3[] = {1, 2, 3, 1, 1}, days3 = 4, ws3 = 5;
  printf("%d\n", shipWithinDays(weights1, ws1, days1)); // expect: 15
  printf("%d\n", shipWithinDays(weights2, ws2, days2)); // expect: 6
  printf("%d\n", shipWithinDays(weights3, ws3, days3)); // expect: 3
}
