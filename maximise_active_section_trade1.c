// 3499. Maximize Active Section with Trade I
#include "leetcode.h"

/*
 * you are given a binary string 's' of length 'n', where '1' represents an
 * active seciton, and '0' represents an inactive section. you can perform at
 * most one trade to maximise the number of active sections in 's'. in a trade,
 * you can convert a contiguous block of '1's that is surrounded by '0's to all
 * '0's. afterward, convert a contiguous block of '0's that is surrounded by
 * '1's to all '1's. return the maximum number of active sections in 's' after
 * making the optimal trade.
 */

int maxActiveSectionsAfterTrade(char *s) {
  int n = strlen(s), ones = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      ones++;
  int *zero_runs = (int *)malloc((n + 1) * sizeof(int));
  int run_cnt = 0, len = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      len++;
    else if (len > 0) {
      zero_runs[run_cnt++] = len;
      len = 0;
    }
  }
  if (len > 0)
    zero_runs[run_cnt++] = len;
  if (run_cnt < 2) {
    free(zero_runs);
    return ones;
  }
  int best = 0;
  for (int i = 0; i + 1 < run_cnt; i++) {
    int curr = zero_runs[i] + zero_runs[i + 1];
    best = fmax(best, curr);
  }
  free(zero_runs);
  return best;
}

int main() {
  char *s1 = "01", *s2 = "0100", *s3 = "1000100";
  int r1 = maxActiveSectionsAfterTrade(s1);
  int r2 = maxActiveSectionsAfterTrade(s2);
  int r3 = maxActiveSectionsAfterTrade(s3);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 3);
  printf("%d\n", r3);
  assert(r3 == 5);
}
