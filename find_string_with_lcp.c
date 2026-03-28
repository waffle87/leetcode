// 2573. Find the String with LCP
#include "leetcode.h"

/*
 * we define the 'lcp' matrix of any 0-indexed string 'word' of 'n' lowercase
 * english letters as an 'n x n' grid such that 'lcp[i][j]' is equal to the
 * length of the longest common prefix between the substring 'word[i, n - 1]'
 * and 'word[j, n - 1]'. given an 'n x n' matrix 'lcp', return the
 * alphabetically smallest string 'word' that corresponds to 'lcp'. if there is
 * no such string, return an empty string.
 */

char *findTheString(int **lcp, int lcpSize, int *lcpColSize) {
  int n = lcpSize;
  char *word = (char *)calloc(n + 1, sizeof(int)), curr = 'a';
  for (int i = 0; i < n; i++)
    if (word[i] == '\0') {
      if (curr > 'z') {
        word[0] = '\0';
        return word;
      }
      word[i] = curr;
      for (int j = i + 1; j < n; j++)
        if (lcp[i][j] > 0)
          word[j] = word[i];
      curr++;
    }
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--) {
      if (word[i] != word[j]) {
        if (lcp[i][j] != 0) {
          word[0] = '\0';
          return word;
        }
      } else {
        if (i == n - 1 || j == n - 1) {
          if (lcp[i][j] != 1) {
            word[0] = '\0';
            return word;
          }
        } else {
          if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
            word[0] = '\0';
            return word;
          }
        }
      }
    }
  return word;
}

int main() {
  int lcp1i[4][4] = {{4, 0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}};
  int lcp2i[4][4] = {{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 1}};
  int lcp3i[4][4] = {{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1, 1, 1, 3}};
  struct two_d_arr *lcp1 =
      two_d_arr_init(ARRAY_SIZE(lcp1i), ARRAY_SIZE(lcp1i[0]), lcp1i);
  struct two_d_arr *lcp2 =
      two_d_arr_init(ARRAY_SIZE(lcp2i), ARRAY_SIZE(lcp2i[0]), lcp2i);
  struct two_d_arr *lcp3 =
      two_d_arr_init(ARRAY_SIZE(lcp3i), ARRAY_SIZE(lcp3i[0]), lcp3i);
  char *r1 = "abab", *r2 = "aaaa", *r3 = "";
  char *fts1 = findTheString(lcp1->arr, lcp1->row_size, lcp1->col_size);
  char *fts2 = findTheString(lcp2->arr, lcp2->row_size, lcp2->col_size);
  char *fts3 = findTheString(lcp3->arr, lcp3->row_size, lcp3->col_size);
  printf("%s\n", fts1);
  assert(!strcmp(fts1, r1));
  printf("%s\n", fts2);
  assert(!strcmp(fts2, r2));
  printf("%s\n", fts3);
  assert(!strcmp(fts3, r3));
  free(fts1);
  free(fts2);
  free(fts3);
  two_d_arr_free(lcp1);
  two_d_arr_free(lcp2);
  two_d_arr_free(lcp3);
}
