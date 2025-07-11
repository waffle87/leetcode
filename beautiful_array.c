// 932. Beautiful Array
#include "leetcode.h"

/*
 * an array 'nums' of length 'n' is beautiful if 'nums' is a permutation of the
 * integers in the range '[1, n]', and for every '0 <= i < j < n', there is no
 * index 'k' with 'i < k < j' where '2 * nums[k] == nums[i] + nums[j]'. given
 * the integer 'n', return any beautiful array 'nums' of length 'n'. there will
 * be at least one valid answer for the given 'n'.
 */

int *build_arr(int n, int **ans) {
  if (ans[n])
    return ans[n];
  int *res = (int *)malloc(n * sizeof(int));
  if (n == 1)
    res[0] = 1;
  else {
    int j = 0;
    int *odds = build_arr((n + 1) / 2, ans);
    for (int k = 0; k < (n + 1) / 2; k++)
      res[k] = 2 * odds[k] - 1;
    int *evens = build_arr(n / 2, ans);
    for (int k = 0; k < n / 2; k++)
      res[((n + 1) / 2) + k] = 2 * evens[k];
  }
  ans[n] = res;
  return res;
}

int *beautifulArray(int n, int *returnSize) {
  int *ans = (int *)malloc(n * sizeof(int));
  *returnSize = n;
  if (n == 1) {
    ans[0] = 1;
    return ans;
  }
  if (n == 2) {
    ans[0] = 1;
    ans[1] = 2;
    return ans;
  }
  int **res = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i < n + 1; i++)
    res[i] = NULL;
  ans = build_arr(n, res);
  *returnSize = n;
  for (int i = 0; i < n; i++)
    free(res[i]);
  free(res);
  return ans;
}

int main() {
  int rs1, *ba1 = beautifulArray(4, &rs1);
  int rs2, *ba2 = beautifulArray(5, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ba1[i]); // expect: 2 1 4 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ba2[i]); // expect: 3 1 2 5 4
  printf("\n");
  free(ba1), free(ba2);
}
