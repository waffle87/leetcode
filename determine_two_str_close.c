// 1657. Determine if Two Strings Are Close
#include "leetcode.h"

/*
 * two strings are considered close if you can attain one from the other using
 * the following operations. operation 1:swap any two existing characters.
 * operation 2: transform every occurence of one exiting character into another
 * existing character, and do the same with the other character. you can use the
 * operations on either string as many times as necessary.given two strings 'w1'
 * and 'w2', return true if 'w1' and 'w2' are close and false otherwise.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool closeStrings(char *w1, char *w2) {
  int n1 = strlen(w1), n2 = strlen(w2);
  if (n1 != n2)
    return false;
  int *a1 = calloc(26, sizeof(int)), *a2 = calloc(26, sizeof(int));
  for (int i = 0; i < n1; i++) {
    a1[w1[i] - 'a']++;
    a2[w2[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a1[i] == 0 && a2[i] != 0)
      return false;
    if (a2[i] == 0 && a1[i] != 0)
      return false;
  }
  qsort(a1, 26, sizeof(int), cmp);
  qsort(a2, 26, sizeof(int), cmp);
  for (int i = 0; i < 26; i++)
    if (a1[i] != a2[i])
      return false;
  return true;
}

int main() {
  char *w11 = "abc", *w21 = "bca";
  char *w12 = "a", *w22 = "aa";
  char *w13 = "cabbba", *w23 = "abbccc";
  printf("%d\n", closeStrings(w11, w21)); // expect: 1
  printf("%d\n", closeStrings(w12, w22)); // expect: 0
  printf("%d\n", closeStrings(w13, w23)); // expect: 1
}
