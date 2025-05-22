// 3211. Generate Binary Strings Without Adjacent Zeros
#include "leetcode.h"

/*
 * you are given a positive integer 'n'. a binary string 'x' is valid if all
 * substrings of 'x' of length 2 contain at least one 1. return all valid
 * strings with length 'n' in any order.
 */

void dfs(char **ans, int *returnSize, char *tmp, int *tmp_idx, int n,
         bool prev) {
  if ((*tmp_idx) == n) {
    ans[(*returnSize)] = (char *)calloc(n + 1, sizeof(char));
    memcpy(ans[(*returnSize)++], tmp, (*tmp_idx) * sizeof(char));
    return;
  }
  if (prev) {
    tmp[(*tmp_idx)++] = '1';
    dfs(ans, returnSize, tmp, tmp_idx, n, !prev);
    (*tmp_idx)--;
  } else {
    for (int i = 0; i < 2; i++) {
      tmp[(*tmp_idx)++] = i + '0';
      dfs(ans, returnSize, tmp, tmp_idx, n, !i);
      (*tmp_idx)--;
    }
  }
}

char **validStrings(int n, int *returnSize) {
  *returnSize = 0;
  char **ans = (char **)malloc(pow(2, n) * sizeof(char *));
  char *tmp = (char *)calloc(n + 1, sizeof(char));
  for (int i = 0; i < 2; i++) {
    int tmp_idx = 0;
    tmp[tmp_idx++] = i + '0';
    dfs(ans, returnSize, tmp, &tmp_idx, n, !i);
  }
  free(tmp);
  return ans;
}

int main() {
  int rs1, rs2;
  char **vs1 = validStrings(3, &rs1);
  char **vs2 = validStrings(1, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", vs1[i]); // expect: ["010","011","101","110","111"]
  printf("\n");
  for (int i = 0; i < rs1; i++)
    printf("%s ", vs2[i]); // expect: ["0","1"]
  printf("\n");
  free(vs1);
  free(vs2);
}
