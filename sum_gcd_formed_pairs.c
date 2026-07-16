// 3867. Sum of GCD of Formed Pairs
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. construct an array
 * 'prefixGcd' where for each index 'i', let 'mx_i = max(nums[0], nums[1], ...,
 * nums[i])', and 'prefixGcd[i] = gcd(nums[i], mx_i)'. after constructing
 * 'prefixGcd', sort 'prefixGcd' in non-decreasing order, form pairs by taking
 * the smallest unpaired element and the largest unpaired element, repeat this
 * process until no more pairs can be formed. for each formed pair, compuute the
 * 'gcd' of the two elemets. if 'n' is odd, the middle element in the
 * 'prefixGcd' array remains unpaired and should be ignored. return an integer
 * denoting the sum of the gcd values of all formed pairs. the term 'gcd(a, b)'
 * denotes the greatest common divisor of 'a' and 'b'.
 */

int gcd(int a, int b) {
  while (b) {
    int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int cmp(const void *a, const void *b) {
  int aa = *(const int *)a;
  int bb = *(const int *)b;
  return (aa > bb) - (aa < bb);
}

long long gcdSum(int *nums, int numsSize) {
  int *prefix = (int *)malloc(numsSize * sizeof(int));
  int max_val = INT_MIN;
  for (int i = 0; i < numsSize; i++) {
    max_val = fmax(max_val, nums[i]);
    prefix[i] = gcd(max_val, nums[i]);
  }
  qsort(prefix, numsSize, sizeof(int), cmp);
  int left = 0, right = numsSize - 1;
  long long ans = 0;
  while (left < right) {
    ans += gcd(prefix[left], prefix[right]);
    left++;
    right--;
  }
  free(prefix);
  return ans;
}

int main() {
  int n1[] = {2, 6, 4}, n2[] = {3, 6, 2, 8};
  long long r1 = gcdSum(n1, ARRAY_SIZE(n1));
  long long r2 = gcdSum(n2, ARRAY_SIZE(n2));
  printf("%lld\n", r1);
  assert(r1 == 2);
  printf("%lld\n", r2);
  assert(r2 == 5);
}
