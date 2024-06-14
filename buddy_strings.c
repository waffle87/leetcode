// 859. Buddy Strings
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 's' and 'goal', return 'true' if you can swap two letters
 * in 's' so the result is equal to 'goal', otherwise, return 'false'. swapping
 * letters is defined as taking two indices 'i' and 'j' 0-indexed such that 'i
 * != j' and swapping the characters at 's[i]' and 's[j]'. for example, swapping
 * indices at '0' and '2' in "abcd" results in "cbad"
 */

bool buddyStrings(char *s, char *goal) {
  int n1 = strlen(s), n2 = strlen(goal);
  if (n1 != n2)
    return false;
  int data[2], idx = 0;
  bool flag = false;
  int *alpha = calloc(26, sizeof(int));
  for (int i = 0; i < n1; i++) {
    alpha[s[i] - 'a']++;
    if (alpha[s[i] - 'a'] == 2)
      flag = true;
    if (s[i] != goal[i]) {
      if (idx == 2)
        return false;
      data[idx] = i;
      idx++;
    }
  }
  if (idx == 1)
    return false;
  if (!idx && flag)
    return true;
  if (idx == 2 && s[data[0]] == goal[data[1]] && s[data[1]] == goal[data[0]])
    return true;
  return false;
}

int main() {
  char s1[] = {"ab"}, g1[] = {"ba"};
  char s2[] = {"ab"}, g2[] = {"ab"};
  char s3[] = {"aa"}, g3[] = {"aa"};
  printf("%d\n", buddyStrings(s1, g1)); // expect: 1
  printf("%d\n", buddyStrings(s2, g2)); // expect: 0
  printf("%d\n", buddyStrings(s3, g3)); // expect: 1
}
