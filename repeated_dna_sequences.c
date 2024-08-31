// 187. Repeated DNA Sequences
#include "leetcode.h"

/*
 * the dna sequence is composed of a series of nucleotides abbreviated as A, C,
 * G, and T. when studying dna it is useful to identify repeated sequences
 * within the dna. given a string 's' that represents a dna sequence, return all
 * the 10 letter long sequences (substrings) that occur more than once in a dna
 * molecule. you may return the answer in any order
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int val(char c) {
  switch (c) {
  case 'A':
    return 0;
  case 'C':
    return 1;
  case 'G':
    return 2;
  case 'T':
    return 3;
  default:
    return -1;
  }
}

void decode(char *s, int val) {
  int i, rem;
  s[10] = '\0';
  for (i = 9; i >= 0; --i) {
    rem = val % 4;
    val /= 4;
    switch (rem) {
    case 0:
      s[i] = 'A';
      break;
    case 1:
      s[i] = 'C';
      break;
    case 2:
      s[i] = 'G';
      break;
    case 3:
      s[i] = 'T';
      break;
    }
  }
}

char **findRepeatedDnaSequences(char *s, int *returnSize) {
  int stk0[100000], sp0 = 0, stk1[100000], sp1 = 0, n = strlen(s), code = 0;
  if (n < 10) {
    *returnSize = 0;
    return NULL;
  }
  for (int i = 0; i < 10; ++i)
    code = 4 * code + val(s[i]);
  stk0[sp0++] = code;
  for (int i = 0; i < n - 10; ++i) {
    code = (code & 0x3FFFF) * 4 + val(s[i + 10]);
    stk0[sp0++] = code;
  }
  qsort(stk0, sp0, sizeof(int), cmp);
  for (int i = 0, j; i < sp0 - 1; ++i)
    if (stk0[i] == stk0[i + 1]) {
      stk1[sp1++] = stk0[i];
      for (j = i + 1; j < sp0 && stk0[i] == stk0[j]; ++j)
        ;
      i = j - 1;
    }
  char **ans = (char **)malloc(sp1 * sizeof(char *));
  for (int i = 0; i < sp1; ++i) {
    ans[i] = (char *)malloc(11 * sizeof(char));
    decode(ans[i], stk1[i]);
  }
  *returnSize = sp1;
  return ans;
}

int main() {
  char *s1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", *s2 = "AAAAAAAAAAAAA";
  int rs1, rs2;
  char **frds1 = findRepeatedDnaSequences(s1, &rs1);
  char **frds2 = findRepeatedDnaSequences(s2, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", frds1[i]); // expect: ["AAAAACCCCC","CCCCCAAAAA"]
    free(frds1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", frds2[i]); // expect: ["AAAAAAAAAA"]
    free(frds2[i]);
  }
  printf("\n");
  free(frds1), free(frds2);
}
