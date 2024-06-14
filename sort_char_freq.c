// 451. Sort Characters By Frequency
#include "leetcode.h"

/*
 * given a string 's', sort it in decreasing order based on the frequency of the
 * characters. the frequenc of a character is the number of times itappears in
 * the string. return the sorted string. if there are multiple answers, return
 * any of them
 */

int times[265];

int cmp(const void *a, const void *b) {
  return times[*(char *)b] - times[*(char *)a];
}

char *frequencySort(char *s) {
  char letters[256];
  int i, j, k, l_num;
  memset(times, 0, sizeof(times));
  for (i = l_num = 0; s[i] != '\0'; i++)
    if (!times[s[i]]++)
      letters[l_num++] = s[i];
  qsort(letters, l_num, sizeof(char), cmp);
  char *ans = malloc(sizeof(char) * (i + 1));
  for (j = k = 0; j < l_num; j++)
    for (i = 0; i < times[letters[j]]; i++)
      ans[k++] = letters[j];
  ans[k] = '\0';
  return ans;
}

int main() {
  char *s1 = "tree", *s2 = "cccaaa", *s3 = "Aabb";
  printf("%s\n", frequencySort(s1)); // expect: eert
  printf("%s\n", frequencySort(s2)); // expect: aaaccc
  printf("%s\n", frequencySort(s3)); // expect: bbAa
}
