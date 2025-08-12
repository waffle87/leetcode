// 3017. Count the Number of Houses at a Certain Distance II
#include "leetcode.h"

/*
 * you are given three positive integers 'n', 'x', and 'y'. in a city, there
 * exists houses numbered 1 to 'n' connected by 'n' streets. there is a street
 * cnnecting the house numbered 'i' with the house numbered 'i + 1' for all '1
 * <= i <= n - 1'. an additional street connects the house numbered 'x' with the
 * house numbered 'y'. for each 'k' such that '1 <= k <= n', you need to find
 * the number of pairs of houses '(house_i, house_j)' such that the minimum
 * number of streets that need to be traveled to reach 'house_i' from 'house_j'
 * is 'k'. return a 1-indexed array of length 'n' where 'ans[k]' represents the
 * total number of pairs of houses such that the minimum streets required to
 * reach one house from the other is 'k'.
 */

long long *countOfPairs(int n, int x, int y, int *returnSize) {
  *returnSize = n;
  long long *ans = (long long *)calloc(n, sizeof(int));
  x--, y--;
  if (x > y) {
    int tmp = x;
    x = y;
    y = tmp;
  }
  for (int i = 0; i < n; i++) {
    ans[0] += 2;
    int idx1 = fmin(abs(i - x), abs(i - y) + 1);
    if (idx1 < n)
      ans[idx1]++;
    int idx2 = fmin(abs(i - y), abs(i - x) + 1);
    if (idx2 < n)
      ans[idx2]++;
    int idx3 = fmin(abs(i - 0), abs(i - y) + 1 + abs(x - 0));
    if (idx3 < n)
      ans[idx3]--;
    int idx4 = fmin(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)));
    if (idx4 < n)
      ans[idx4]--;
    int idx5 = fmax(x - i, 0) + fmax(i - y, 0) + ((y - x) + 0) / 2;
    if (idx5 < n)
      ans[idx5]--;
    int idx6 = fmax(x - i, 0) + fmax(i - y, 0) + ((y - x) + 1) / 2;
    if (idx6 < n)
      ans[idx6]--;
  }
  for (int i = 1; i < n; i++)
    ans[i] += ans[i - 1];
  return ans;
}

int main() {
  int rs1, rs2, rs3;
  long long *cop1 = countOfPairs(3, 1, 3, &rs1);
  long long *cop2 = countOfPairs(5, 2, 4, &rs2);
  long long *cop3 = countOfPairs(4, 1, 1, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%lld ", cop1[i]); // expect: 6 0 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%lld ", cop2[i]); // expect: 10 8 2 0 0
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%lld ", cop3[i]); // expect: 6 4 2 0
  printf("\n");
  free(cop1);
  free(cop2);
  free(cop3);
}
