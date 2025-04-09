// 667. Beautiful Arrangement II
#include "leetcode.h"

/*
 * given two integers 'n' and 'k', construct a list 'answer' that contains 'n'
 * different positive integers ranging from 1 to 'n' and obeys the following
 * requirement: suppose this list is 'answer = [a1, a2, a3, ..., an]', the the
 * list '[a1 - a2, a2 - a3, ..., an-1 - an]' has exactly 'k' distinct integers.
 * return the list 'answer'. if there are multiple valid answers, return any of
 * them.
 */

int *constructArray(int n, int k, int *returnSize) {
  *returnSize = n;
  int *ans = (int *)malloc(n * sizeof(int));
  int left = 1, right = n;
  for (int i = 0; i < n; i++) {
    if (k > 1) {
      ans[i] = (k & 1) ? left++ : right--;
      k--;
    } else
      ans[i] = left++;
  }
  return ans;
}

int main() {
  int rs1, *ca1 = constructArray(3, 1, &rs1);
  int rs2, *ca2 = constructArray(3, 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ca1[i]); // expect: 1 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", ca2[i]); // expect: 1 3 2
  printf("\n");
  free(ca1);
  free(ca2);
}
