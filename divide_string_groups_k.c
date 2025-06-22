// 2138. Divide a String Into Groups of Size k
#include "leetcode.h"

/*
 * a string 's' can be partitioned into groups of size 'k' using the following
 * procedure: the first group consists of the first 'k' characters of the
 * string, the second group consists of the next 'k' characters of the string,
 * ans so on. each element can be a part of exactly one group. for the last
 * group, if the string does not have 'k' characters remaining, a character
 * 'fill' is used to complete the group. note that the partition is done so that
 * after removing the 'fill' character from the last group, and concatenating
 * all the groups in oder, the resultant string should be 's'. given a string
 * 's', the size of each group 'k', and the character 'fill', return a string
 * array denoting the composition of every group 's' has been divided into.
 */

char **divideString(char *s, int k, char fill, int *returnSize) {
  int n = strlen(s), groups = (n + k - 1) / k;
  char **ans = (char **)malloc(groups * sizeof(char *));
  *returnSize = groups;
  for (int i = 0; i < groups; i++) {
    ans[i] = (char *)malloc((k + 1) * sizeof(char));
    for (int j = 0; j < k; j++) {
      int idx = i * k + j;
      ans[i][j] = idx < n ? s[idx] : fill;
    }
    ans[i][k] = '\0';
  }
  return ans;
}

int main() {
  char *s1 = "abcdefghi", *s2 = "abcdefghij";
  int rs1, rs2;
  char **ds1 = divideString(s1, 3, 'x', &rs1);
  char **ds2 = divideString(s2, 3, 'x', &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", ds1[i]); // expect: ["abc","def","ghi"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", ds2[i]); // expect: ["abc","def","ghi","jxx"]
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(ds1[i]);
  for (int i = 0; i < rs2; i++)
    free(ds2[i]);
}
