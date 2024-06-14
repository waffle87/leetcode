// 1239. Maximum Length of a Concatenated String with Unique Characters
#include "leetcode.h"

/*
 * given an array of strings 'arr'. a string 's' is formed by the concatenation
 * of subsequence of 'arr', that has unique characters. return the maximum
 * possible length of 's'. a subsequence is an array that can be derived from
 * another array by deleting some or no elements without changing the order of
 * the remaining elements.
 */

typedef unsigned char uint8_t;

void dfs(uint8_t **data, uint8_t *len, uint8_t *curr, int pos, int n, int *res,
         int size) {
  if (pos == n) {
    *res = fmax(*res, size);
    return;
  }
  dfs(data, len, curr, pos + 1, n, res, size);
  bool pass = true;
  for (int i = 0; i < 26; i++) {
    curr[i] += data[pos][i];
    if (curr[i] > 1)
      pass = false;
  }
  if (pass)
    dfs(data, len, curr, pos + 1, n, res, size + len[pos]);
  for (int i = 0; i < 26; i++)
    curr[i] -= data[pos][i];
}

int maxLength(char **arr, int arr_size) {
  uint8_t **data = malloc(arr_size * sizeof(uint8_t *));
  uint8_t *len = malloc(arr_size * sizeof(uint8_t));
  uint8_t cnt = 0, ans = 0;
  for (uint8_t i = 0; i < arr_size; i++)
    data[i] = calloc(26, sizeof(uint8_t));
  data[cnt] = calloc(26, sizeof(uint8_t));
  for (int i = 0; i < arr_size; i++) {
    uint8_t l = strlen(arr[i]);
    for (int j = 0; j < l; j++) {
      data[cnt][arr[i][j] - 'a']++;
      if (data[cnt][arr[i][j] - 'a'] > 1) {
        memset(data[cnt], 0, 26 * sizeof(uint8_t));
        break;
      }
      if (j == l - 1) {
        ans = fmax(ans, l);
        len[cnt] = l;
        cnt++;
      }
    }
  }
  uint8_t *curr = calloc(26, sizeof(uint8_t));
  if (cnt > 1)
    dfs(data, len, curr, 0, cnt, &ans, 0);
  free(curr), free(len);
  return ans;
}

int main() {
  char a1[3][2] = {"un", "iq", "ue"};
  char a2[4][3] = {"cha", "r", "act", "ers"};
  char a3[1][26] = {"abcdefghijklmnopqrstuvwxyz"};
  printf("%d\n", maxLength(a1, 3));
  printf("%d\n", maxLength(a2, 4));
  printf("%d\n", maxLength(a3, 1));
}
