// 1177. Can Make Palindrome from Substring
#include "leetcode.h"

/*
 * you are given a string 's' and array 'queries' where 'queries[i] = [l_i,
 * r_i, k_i]'. we may rearrange the substring 's[l_i, ..., r_i]' for
 * each query and then choose up to 'k_i' f them to replace with any lowercase
 * english letter. if the substring is possible to be a palindrome string after
 * the operations above, the result of the query is 'true'. otherwise, the
 * result is 'false'. return a boolean array 'answer' where 'answer[i]' is the
 * result of the i'th query 'queries[i]'. note that each letter replacement is
 * counted individualy for replacement, so if, for example 's[l_i, ...,
 * r_i] = "aaa"', and 'k_i = 2', we can only replace two of the letters.
 * also note that no query modifies the initial string 's'.
 */

bool *canMakePaliQueries(char *s, int **queries, int queriesSize,
                         int *queriesColSize, int *returnSize) {
  int *dp = (int *)calloc(strlen(s), sizeof(int));
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  *returnSize = queriesSize;
  dp[0] = (1 << (s[0] - 'a'));
  for (int i = 1; i < strlen(s); i++)
    dp[i] = dp[i - 1] ^ (1 << (s[i] - 'a'));
  for (int i = 0; i < queriesSize; i++) {
    int l = queries[i][0], r = queries[i][1], k = queries[i][2], curr;
    curr = !l ? dp[r] : dp[r] ^ dp[l - 1];
    int one = __builtin_popcount(curr);
    ans[i] = one / 2 > k ? false : true;
  }
  free(dp);
  return ans;
}

int main() {
  char *s1 = "abcda", *s2 = "lyb";
  int q1i[5][3] = {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
  int q2i[2][3] = {{0, 1, 0}, {2, 2, 1}}, rs1, rs2;
  struct two_d_arr q1, q2;
  two_d_arr_init(&q1, 5, 3, q1i);
  two_d_arr_init(&q2, 2, 3, q2i);
  bool *cmpq1 = canMakePaliQueries(s1, q1.arr, q1.row_size, q1.col_size, &rs1);
  bool *cmpq2 = canMakePaliQueries(s2, q2.arr, q2.row_size, q2.col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cmpq1[i]); // expect: 1 0 0 1 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cmpq2[i]); // expect: 0 1
  printf("\n");
  free(cmpq1), free(cmpq2);
  two_d_arr_free(&q1), two_d_arr_free(&q2);
}
