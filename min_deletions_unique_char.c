// 1647. Minimum Deletions to Make Character Frequencies Unique
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * a string 's' is called good if there are no two different characters in 's'
 * that have the same frequency. given a string 's', return the minimum number
 * of characters you need to delete to make 's' good. the frequency of a
 * character in a string is the number of times it appears in the string. for
 * example, in the string "aab", the frequency of 'a' is 2, while the frequency
 * of 'b' is 1.
 */

int cmp(const int *a, const int *b) { return (*b - *a); }

int minDeletions(char *s) {
  int n = strlen(s), ans[26] = {}, cnt = 0;
  for (int i = 0; s[i] != '\0'; i++)
    ans[s[i] - 'a']++;
  qsort(ans, 26, sizeof(int), cmp);
  for (int i = 1; i < 26; i++) {
    if (!ans[i])
      continue;
    while (ans[i] >= ans[i - 1]) {
      cnt++;
      ans[i]--;
      if (!ans[i])
        break;
    }
    return cnt;
  }
}

int main() {
  char s1[] = {"aab"}, s2[] = {"aaabbbcc"}, s3[] = {"ceabaacb"};
  printf("%d\n", minDeletions(s1)); // expect: 0
  printf("%d\n", minDeletions(s2)); // expect: 2
  printf("%d\n", minDeletions(s3)); // expect: 2
}
