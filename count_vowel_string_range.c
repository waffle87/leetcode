// 2559. Count Vowel Strings in Ranges
#include "leetcode.h"

/*
 * you are given a 0-indexed array of strings 'words' and a 2d array of integers
 * 'queries'. each query 'queries[i] = [l_i, r_i]' asks us to find the number of
 * strings present in the range 'l_i' to 'r_i' (both inclusive) of 'words' that
 * start and end with a vowel. return an array 'ans' of size 'queries.length'
 * where 'ans[i]' is the answer to the i'th query. note that the vowel letters
 * are a, e, i, o, and u
 */

int *vowelStrings(char **words, int wordsSize, int **queries, int queriesSize,
                  int *queriesColSize, int *returnSize) {
  int *dp = (int *)malloc((wordsSize + 1) * sizeof(int));
  dp[0] = 0;
  for (int i = 0; i < wordsSize; i++) {
    int tmp = 0, n = strlen(words[i]) - 1;
    if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' ||
        words[i][0] == 'o' || words[i][0] == 'u')
      if (words[i][n] == 'a' || words[i][n] == 'e' || words[i][n] == 'i' ||
          words[i][n] == 'o' || words[i][n] == 'u')
        tmp = 1;
    dp[i + 1] = dp[i] + tmp;
  }
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; i++) {
    int num = dp[queries[i][i] + 1] - dp[queries[i][0]];
    ans[i] = num;
  }
  *returnSize = queriesSize;
  free(dp);
  return ans;
}

int main() {
  char *w1[] = {"aba", "bcb", "ece", "aa", "e"}, *w2[] = {"a", "e", "i"};
  int q1i[3][2] = {{0, 2}, {1, 4}, {1, 1}}, rs1;
  int q2i[3][2] = {{0, 2}, {0, 1}, {2, 2}}, rs2;
  struct two_d_arr q1, q2;
  two_d_arr_init(&q1, 3, 2, q1i);
  two_d_arr_init(&q2, 3, 2, q2i);
  int *vs1 = vowelStrings((char **)w1, ARRAY_SIZE(w1), q1.arr, q1.row_size,
                          q1.col_size, &rs1);
  int *vs2 = vowelStrings((char **)w2, ARRAY_SIZE(w2), q2.arr, q2.row_size,
                          q2.col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", vs1[i]); // expect: 2 3 0
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", vs2[i]); // expect: 3 2 1
  printf("\n");
  free(vs1), free(vs2);
  two_d_arr_free(&q1), two_d_arr_free(&q2);
}
