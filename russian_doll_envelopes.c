// 354. Russian Doll Envelopes
#include "leetcode.h"

/*
 * you are given a 2d array of integers 'envelopes' where 'envelopes[i] = [w_i,
 * h_i]' represents the width and height of an envelope. one envelope can fit
 * into another if and only if both the width and height of one envelope are
 * greater than the other envelope's width and height. return the maximum number
 * of envelopes you can russian doll (ie. put one inside the other).
 */

int bin_search(int *dp, int start, int end, int target) {
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (dp[mid] == target)
      return mid;
    else if (dp[mid] > target)
      end = mid;
    else
      start = mid + 1;
  }
  return start;
}

int cmp(const void *a, const void *b) {
  if ((*(int **)a)[0] == (*(int **)b)[0])
    return (*(int **)b)[1] - (*(int **)a)[1];
  else
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int maxEnvelopes(int **envelopes, int envelopesSize, int *envelopesColSize) {
  qsort(envelopes, envelopesSize, sizeof(int **), cmp);
  int *dp = (int *)malloc(envelopesSize * sizeof(int)), ans = 0;
  dp[0] = envelopes[0][1];
  for (int i = 1; i < envelopesSize; i++) {
    if (envelopes[i][1] > dp[ans - 1])
      dp[ans++] = envelopes[i][1];
    else {
      int idx = bin_search(dp, 0, ans, envelopes[i][1]);
      dp[idx] = envelopes[i][1];
      if (idx == ans)
        ans++;
    }
  }
  free(dp);
  return ans;
}

int main() {
  int e1i[4][2] = {{5, 4}, {6, 4}, {6, 7}, {2, 3}},
      e2i[3][2] = {{1, 1}, {1, 1}, {1, 1}};
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  printf("%d\n",
         maxEnvelopes(e1->arr, e1->row_size, e1->col_size)); // expect: 3
  printf("%d\n",
         maxEnvelopes(e2->arr, e2->row_size, e2->col_size)); // expect: 1
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
