// 2405. Optimal Partition of String
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's', partition the string into one or more substrings such
 * that the characters in each substring are unique. that is, no letter appears
 * in a single substring more than once. return the minimum number of substrings
 * in such a partition note that each character should belong to exactly one
 * substring in a partition
 */

int partitionString(char *s) {
  int n = strlen(s), ans = 0;
  int *post = malloc(26 * sizeof(int));
  for (int i = 0; i < 26; i++)
    post[i] = -1;
  int start = 0, last = 0;
  for (int i = 0; i < n; i++) {
    if (post[s[i] - 'a'] == -1 || post[s[i] - 'a'] < start)
      last++;
    else {
      ans++;
      start = i;
      last = i;
    }
    post[s[i] - 'a'] = i;
  }
  return ans + 1;
}

int main() {
  char s1[] = {"abacaba"}, s2[] = {"ssssss"};
  printf("%d\n", partitionString(s1)); // expect: 4
  printf("%d\n", partitionString(s2)); // expect: 6
}
