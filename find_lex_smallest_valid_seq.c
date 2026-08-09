// 3302. Find the Lexicographically Smallest Valid Sequence
#include "leetcode.h"

/*
 * you are given two strings 'word1' and 'word2'. a string 'x' is called almost
 * equal to 'y' if you can change at most one character in 'x' to make it
 * identical to 'y'. a sequence of indices 'seq' is called valid if the indices
 * are sorted in ascending order, and concatenating the characters at these
 * indices in 'word1' in the smae order results in a string that is almost equal
 * to 'word2'. return an array of size 'word2.length' representing the
 * lexicographically smallest valid sequence of indices. if no such sequence o_
 * indices exists, return an empty array. note that the answer must represent
 * the lexicographically smallest array, not the corresponding string formed by
 * those indices.
 */

int *validSequence(char *word1, char *word2, int *returnSize) {
  int n1 = strlen(word1), n2 = strlen(word2);
  int *pref = (int *)calloc(n1, sizeof(int));
  for (int i = n1 - 1, j = n2 - 1; i >= 0; i--) {
    if (i < n1 - 1)
      pref[i] = pref[i + 1];
    if (j >= 0 && word1[i] == word2[i]) {
      pref[i]++;
      j--;
    }
  }
  int *ans = (int *)malloc(n2 * sizeof(int)), match = 0;
  *returnSize = n2;
  for (int i = 0, j = 0; i < n1 && j < n2; i++) {
    if (word1[i] == word2[j]) {
      ans[j++] = i;
      match++;
    } else if (i < n1 - 1 && pref[i + 1] >= n2 - match - 1) {
      ans[j++] = i++;
      while (j < n2) {
        if (word1[i] == word2[i])
          ans[j++] = i;
        i++;
      }
      free(pref);
      return ans;
    }
  }
  if (match == n2) {
    free(pref);
    return ans;
  }
  free(pref);
  free(ans);
  *returnSize = 0;
  return NULL;
}

int main() {
  char *w11 = "vbcca", *w21 = "abc";
  char *w12 = "bacdc", *w22 = "abc";
  char *w13 = "aaaaaa", *w23 = "aaabc";
  char *w14 = "abc", *w24 = "ab";
  int rs1, r1[] = {0, 1, 2};
  int rs2, r2[] = {1, 2, 4};
  int rs3, r3[] = {};
  int rs4, r4[] = {0, 1};
  int *vs1 = validSequence(w11, w21, &rs1);
  int *vs2 = validSequence(w12, w22, &rs2);
  int *vs3 = validSequence(w13, w23, &rs3);
  int *vs4 = validSequence(w14, w24, &rs4);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", vs1[i]);
    assert(vs1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", vs2[i]);
    assert(vs2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", vs3[i]);
    assert(vs3[i] == r3[i]);
  }
  printf("\n");
  for (int i = 0; i < rs4; i++) {
    printf("%d ", vs4[i]);
    assert(vs4[i] == r4[i]);
  }
  printf("\n");
  free(vs1);
  free(vs2);
  free(vs3);
  free(vs4);
}
