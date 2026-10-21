// 3863. Minimum Operations to Sort a String
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters. in one
 * operation, you can select any substring of 's' that is not the entire string
 * and sort it in non-descending alphabetical order. return the minimum number
 * of operations required to make 's' sorted in non-descending order. if it is
 * not possible, return -1.
 */

int minOperations(char *s) {
  int n = strlen(s);
  char max = 'a', min = 'z';
  bool sorted = true;
  for (int i = 0; i < n; i++) {
    max = fmax(max, s[i]);
    min = fmin(min, s[i]);
    if (i > 0 && s[i - 1] > s[i])
      sorted = false;
  }
  if (sorted)
    return 0;
  if (n == 2)
    return -1;
  if (s[0] == min && s[n - 1] == max)
    return 1;
  for (int i = 1; i < n - 1; i++)
    if (s[i] == min || s[i] == max)
      return 2;
  return 3;
}

int main() {
  char *s1 = "dog";
  char *s2 = "card";
  char *s3 = "gf";
  int r1 = minOperations(s1);
  int r2 = minOperations(s2);
  int r3 = minOperations(s3);
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == -1);
}
