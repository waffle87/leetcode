// 1768. Merge Strings Alternately
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given two strings 'word1' and 'word2', merge the strings by adding letters in
 * alternating order, starting with 'word1'. if a string is longer than the
 * other, append the additional letters onto the end of the merged string.
 * return the merged string!!
 */

char *mergeAlternately(char *word1, char *word2) {
  char *ans = (char *)calloc(strlen(word1) + strlen(word2) + 1, sizeof(char));
  int i = 0, j = 0, k = 0;
  while (i < strlen(word1) || j < strlen(word2)) {
    if (i < strlen(word1))
      ans[k++] = word1[i++];
    if (j < strlen(word2))
      ans[k++] = word2[j++];
  }
  return ans;
}

int main() {
  char w1[] = {"abc"}, w2[] = {"pqr"}, *ma1 = mergeAlternately(w1, w2);
  char w3[] = {"ab"}, w4[] = {"pqrs"}, *ma2 = mergeAlternately(w3, w4);
  char w5[] = {"abcd"}, w6[] = {"pq"}, *ma3 = mergeAlternately(w5, w6);
  printf("%s\n", ma1); // expect: apbqcr
  printf("%s\n", ma2); // expect: apbqrs
  printf("%s\n", ma3); // expect: apbqcd
}
