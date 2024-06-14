// 2217. Find Palindrome With Fixed Length
#include "leetcode.h"

/*
 * given an integer array 'queries' and a positive integer 'intLength', return
 * an array 'ans' where 'ans[i]' is either the 'queries[i]'th smallest positive
 * palindreom of length 'intLength' or -1 if no such palindrome exists.
 */

long long reverse(int num, int n) {
  long long res = 0;
  if (n % 2)
    num /= 10;
  while (num) {
    res = res * 10 + num % 10;
    num /= 10;
  }
  return res;
}

long long *kthPalindrome(int *queries, int queriesSize, int intLength,
                         int *returnSize) {
  long long *ans = (long long *)malloc(queriesSize * sizeof(long long));
  *returnSize = queriesSize;
  int n = (intLength + 1) / 2, min = pow(10, n - 1), max = pow(10, n) - 1,
      mul = pow(10, n - intLength % 2);
  for (int i = 0; i < queriesSize; i++)
    ans[i] = min + queries[i] - 1 > max
                 ? -1
                 : (long long)(min + queries[i] - 1) * mul +
                       reverse(min + queries[i] - 1, intLength);
  return ans;
}

int main() {
  int q1[] = {1, 2, 3, 4, 5, 90}, q2[] = {2, 4, 6}, rs1, rs2;
  long long *kp1 = kthPalindrome(q1, ARRAY_SIZE(q1), 3, &rs1);
  long long *kp2 = kthPalindrome(q2, ARRAY_SIZE(q2), 4, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%lld ", kp1[i]); // expect: 101,111,121,131,141,999
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%lld ", kp2[i]); // expect: 1111,1331,1551
  printf("\n");
}
