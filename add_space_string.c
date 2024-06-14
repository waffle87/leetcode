// 2109. Adding Spaces to a String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a 0-indexed string 's' and a 0-indexed integer array 'spaces' that
 * describes the indices in the original string where spaces will be added. each
 * space should be inserted before the character at the given index. return the
 * modified string after the spaces have been added
 */

char *addSpaces(char *s, int *spaces, int spaces_size) {
  int n = strlen(s), m = n + 1 + spaces_size;
  char *ans = malloc(m * sizeof(char));
  ans[m - 1] = '\0';
  int aidx = 0, bidx = 0;
  int *num = malloc(spaces_size * sizeof(int));
  num[0] = spaces[0];
  for (int i = 1; i < spaces_size; i++)
    num[i] = spaces[i] - spaces[i - 1];
  for (int i = 0; i < spaces_size; i++) {
    strncpy(&ans[aidx], &s[bidx], num[i]);
    aidx += num[i];
    bidx += num[i];
    ans[aidx] = ' ';
    aidx++;
  }
  strncpy(&ans[aidx], &s[bidx], m - aidx);
  free(num);
  return ans;
}

int main() {
  char s1[] = {"LeetcodeHelpsMeLearn"}, s2[] = {"icodeinpython"};
  int n1[] = {8, 13, 15}, n2[] = {1, 5, 7, 9};
  printf("%s\n", addSpaces(s1, n1, 3)); // expect: Leetcode Helps Me Learn
  printf("%s\n", addSpaces(s2, n2, 4)); // expect: i code in py thon
}
