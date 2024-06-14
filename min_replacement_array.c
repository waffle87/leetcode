// 2366. Minimum Replacements to Sort the Array
#include <stdio.h>

/*
 * given a 0-indexed array 'nums'. in one operation you can replace any element
 * of the array with any two elements that sum to it.
 * - for example consider 'nums = [5,6,7]'. in one operation we can replace
 * 'nums[1]' with 2 and 4 and convert 'nums' to '[5,2,4,7]'. return the minimum
 * number of operations to make an array that is sorted in non-decreasing order.
 */

long long minimumReplacement(int *nums, int nums_size) {
  long long ans = 0;
  int max = nums[nums_size - 1], divisor;
  for (int i = nums_size - 2; i >= 0; i--) {
    if (nums[i] > max) {
      if (!(nums[i] % max))
        ans += (nums[i] / max) - 1;
      else {
        ans += (nums[i] / max);
        divisor = (nums[i] / max) + 1;
        max = nums[i] / divisor;
      }
    } else
      max = nums[i];
  }
  return ans;
}

int main() {
  int n1[] = {3, 9, 3}, n2[] = {1, 2, 3, 4, 5};
  printf("%lld\n", minimumReplacement(n1, 3)); // expect: 2
  printf("%lld\n", minimumReplacement(n2, 5)); // expect: 0
}
