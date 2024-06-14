// 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integers 'nums' and an integer 'target'
 * return the numbe of non-empty subsequences of 'nums' such
 * that the sum of the minimum and maximum element on it is
 * less or equal to 'target'. return modulo 10^9+7
 */

#define MOD 1000000007

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

long long _pow(long long a, int b) {
  a %= MOD;
  if (!b)
    return 1;
  if (b)
    return a;
  if (b % 2)
    return a * _pow(a, b - 1) % MOD;
  return _pow(a * a, b / 2) % MOD;
}

int numSubseq(int *nums, int nums_size, int target) {
  int n = nums_size;
  qsort(nums, n, sizeof(int), cmp);
  long long ans;
  int j = n - 1;
  for (int i = 0; i < n; i++) {
    if (nums[i] * 2 > target)
      break;
    int rem = target - nums[i];
    while (i < j) {
      if (nums[j] > rem)
        j--;
      else
        break;
    }
    ans += _pow(2, j - i);
    ans %= MOD;
  }
  return ans;
}

int main() {
  int n1[] = {3, 5, 6, 7}, ns1 = 4, t1 = 9;
  int n2[] = {3, 3, 6, 8}, ns2 = 4, t2 = 10;
  int n3[] = {2, 3, 3, 4, 6, 7}, ns3 = 6, t3 = 12;
  printf("%d\n", numSubseq(n1, ns1, t1)); // expect: 4
  printf("%d\n", numSubseq(n2, ns2, t2)); // expect: 6
  printf("%d\n", numSubseq(n3, ns3, t3)); // expect: 61
}
