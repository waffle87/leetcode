// 3420. Count Non-Decreasing Subarrays After K Operations
#include "leetcode.h"

/*
 * you are given an array 'nums' of 'n' integers and an integer 'k'. for each
 * sbuarray of 'nums', you can apply up to 'k' operations on it. in each
 * operation, you incremenet any element of the subarray by 1. note that each
 * subarray is considered independently, meaning changes made to one subarray do
 * not persist to another. return the number of subarrays that you can make
 * non-decreasing after performing at most 'k' operations. an array is said to
 * be non decreasing if each element is greater than or equal to its previous
 * element
 */

long long countNonDecreasingSubarrays(int *nums, int numsSize, int k) {
  for (int i = 0; i < numsSize / 2; i++) {
    int tmp = nums[i];
    nums[i] = nums[numsSize - 1 - i];
    nums[numsSize - 1 - i] = tmp;
  }
  long long ans = 0;
  int left = 0, front = 0, back = 0;
  int *stack = (int *)malloc(numsSize * sizeof(int));
  for (int right = 0; right < numsSize; right++) {
    int val = nums[right];
    while (back > front && nums[stack[back - 1]] < val) {
      int r = stack[--back];
      int l = (back == front) ? left - 1 : stack[back - 1];
      k -= (long long)(r - l) * (val - nums[r]);
    }
    stack[back++] = right;
    while (k < 0) {
      k += nums[stack[front]] - nums[left];
      if (stack[front] == left)
        front++;
      left++;
    }
    ans += right - left + 1;
  }
  free(stack);
  return ans;
}

int main() {
  int n1[] = {6, 3, 1, 2, 4, 4};
  int n2[] = {6, 3, 1, 3, 6};
  long long r1 = countNonDecreasingSubarrays(n1, ARRAY_SIZE(n1), 7);
  long long r2 = countNonDecreasingSubarrays(n2, ARRAY_SIZE(n2), 4);
  printf("%lld\n", r1);
  assert(r1 == 17);
  printf("%lld\n", r2);
  assert(r2 == 12);
}
