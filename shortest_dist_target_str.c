// 2515. Shortest Distance to Target String in a Circular Array
#include "leetcode.h"

/*
 * you are given a 0-indexed circular string array 'words' and a string
 * 'target'. a circular array means that the array's end connects to the array's
 * beginning. starting from 'startIndex', you can move to either the next word
 * or the previous word with 1 step at a time. return the shortest distance
 * needed to reach the string 'target'. if the string 'target' does not exist in
 * 'words', return -1.
 */

int closestTarget(char **words, int wordsSize, char *target, int startIndex) {
  int ans = wordsSize, n = wordsSize;
  for (int i = 0; i < wordsSize; i++)
    if (!strcmp(words[i], target)) {
      int dist = abs(i - startIndex);
      ans = fmin(ans, fmin(dist, n - dist));
    }
  return ans < n ? ans : -1;
}

int main() {
  char *w1[] = {"hello", "i", "am", "leetcode", "hello"}, *t1 = "hello";
  char *w2[] = {"a", "b", "leetcode"}, *t2 = "leetcode";
  char *w3[] = {"i", "eat", "leetcode"}, *t3 = "ate";
  int r1 = closestTarget(w1, ARRAY_SIZE(w1), t1, 1);
  int r2 = closestTarget(w2, ARRAY_SIZE(w2), t2, 0);
  int r3 = closestTarget(w3, ARRAY_SIZE(w3), t3, 0);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == -1);
}
