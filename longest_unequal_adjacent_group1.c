// 2900. Longest Unequal Adjacent Groups Subsequence I
#include "leetcode.h"

/*
 * you are given a string array 'words' and a binary array 'groups' both of
 * length 'n' where 'words[i]' is associated with 'groups[i]'. your task is to
 * select the longest alternating subsequence from 'words'. a subsequence of
 * 'words' is alternating if for any two consecutive strings in the sequence,
 * their corresponding elements in the binary array 'groups' differ.
 * essentially, you are to choose strings such that adjacent elements have
 * non-matching corresponding bits in the 'groups' array. return the selected
 * subsequence. if there are multiple, return any of them. note: the elements in
 * 'words' are distinct.
 */

char **getLongestSubsequence(char **words, int wordsSize, int *groups,
                             int groupsSize, int *returnSize) {
  int j = 1;
  for (int i = 1; i < groupsSize; i++)
    if (groups[i] != groups[i - 1])
      words[j++] = strdup(words[i]);
  *returnSize = j;
  return words;
}

int main() {
  char *w1[] = {"e", "a", "b"}, *w2[] = {"a", "b", "c", "d"};
  int g1[] = {0, 0, 1}, g2[] = {1, 0, 1, 1}, rs1, rs2;
  char **gls1 = getLongestSubsequence((char **)w1, ARRAY_SIZE(w1), g1,
                                      ARRAY_SIZE(g1), &rs1);
  char **gls2 = getLongestSubsequence((char **)w2, ARRAY_SIZE(w2), g2,
                                      ARRAY_SIZE(g2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", gls1[i]); // expect: e b
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", gls2[i]); // expect: a b c
  printf("\n");
}
