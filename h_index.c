// 274. H-Index
#include "leetcode.h"

/*
 * given an array of integers 'citations' where 'citations[i]' is the number of
 * citations a researcher received for their i'th paper, return the researchers
 * h-index. according to the definition of h-index on wikipedia: the h-index is
 * given as the maximum value of 'h' such that the given researcher published at
 * least 'h' papers that have each been cited 'h' times.
 */

int hIndex(int *citations, int citations_size) {
  int dp[citations_size + 1];
  for (int i = 0; i < citations_size + 1; i++)
    dp[i] = 0;
  for (int i = 0; i < citations_size; i++) {
    if (citations[i] < citations_size)
      dp[citations[i]]++;
    else
      dp[citations_size]++;
  }
  for (int i = citations_size, acc = 0; i >= 0; i--) {
    acc += dp[i];
    if (acc >= i)
      return i;
  }
  return 0;
}

int main() {
  int c1[] = {3, 0, 6, 1, 5}, c2[] = {1, 3, 1};
  printf("%d\n", hIndex(c1, ARRAY_SIZE(c1))); // expect: 3
  printf("%d\n", hIndex(c2, ARRAY_SIZE(c2))); // expect: 1
}
