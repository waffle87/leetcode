// 2434. Using a Robot to Print the Lexicographically Smallest String
#include "leetcode.h"

/*
 * you are given a string 's' and a robot that currently holds an empty string
 * 't'. apply one of the followiing operations until 's' and 't' are both empty.
 * remove the first character of a string 's' and give it to the robot. the
 * robot will append this charcter to the string 't'. remove the last character
 * of a string 't' and give it to the robot. the robot will write this character
 * on paper.
 */

char *robotWithString(char *s) {
  int n = strlen(s), a_idx = 0, t_idx = 0, min_idx = 0, begin = 0;
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  ans[n] = '\0';
  char *t = (char *)malloc(n * sizeof(char)), low = 'a';
  while (begin < n) {
    char min = s[begin];
    min_idx = begin;
    for (int i = begin; i < n; i++) {
      if (s[i] == low) {
        min_idx = i;
        min = low;
        break;
      } else if (s[i] < min) {
        min = s[i];
        min_idx = i;
      }
    }
    low = s[min_idx];
    if (!t_idx) {
      ans[a_idx++] = low;
      for (int j = begin; j < min_idx; j++)
        t[t_idx++] = s[j];
    } else {
      while (t_idx >= 0) {
        if (t_idx > 0 && t[t_idx - 1] <= s[min_idx])
          ans[a_idx++] = t[t_idx-- - 1];
        else {
          ans[a_idx++] = s[min_idx];
          for (int j = begin; j < min_idx; j++)
            t[t_idx++] = s[j];
          break;
        }
      }
    }
    begin = min_idx + 1;
  }
  for (int i = t_idx - 1; i >= 0; i--)
    ans[a_idx++] = t[i];
  free(t);
  return ans;
}

int main() {
  char *s1 = "zza", *s2 = "bac", *s3 = "bdda";
  char *rws1 = robotWithString(s1);
  char *rws2 = robotWithString(s2);
  char *rws3 = robotWithString(s3);
  printf("%s\n", rws1); // expect: azz
  printf("%s\n", rws2); // expect: abc
  printf("%s\n", rws3); // expect: addb
  free(rws1);
  free(rws2);
  free(rws3);
}
