// 763. Partition Labels
#include "leetcode.h"

/*
 * you are given a string 's'. we want to partition the string into as many
 * parts as possible so that each letter appears in at most one part. for
 * example, the string 'ababcc' can be partitioned into '["abab", "cc"]'. note
 * that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be 's'. return a list of integers
 * representing the size of these parts.
 */

int *partitionLabels(char *s, int *returnSize) {
  int n = strlen(s), start = 0, end = 0, curr = 0;
  int *ans = (int *)calloc(n, sizeof(int)), hash[26] = {0};
  for (int i = 0; i < n; i++)
    hash[s[i] - 'a'] = i;
  for (int i = 0; i < n; i++) {
    int prev = hash[s[i] - 'a'];
    end = end > prev ? end : prev;
    if (end == i) {
      ans[curr++] = end - start + 1;
      start = end + 1;
    }
  }
  *returnSize = curr;
  return ans;
}

int main() {
  char *s1 = "ababcbacadefegdehijhklij", *s2 = "eccbbbbdec";
  int rs1, *pl1 = partitionLabels(s1, &rs1);
  int rs2, *pl2 = partitionLabels(s2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pl1[i]); // expect: 9 7 8
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pl2[i]); // expect: 10
  printf("\n");
  free(pl1);
  free(pl2);
}
