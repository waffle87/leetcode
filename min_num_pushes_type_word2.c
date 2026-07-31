// 3016. Minimum Number of Pushes to Type Word II
#include "leetcode.h"

/*
 * you are given a string 'word' containing lowercase english letters. telephone
 * keypads have keys mapped with distinct collections of lowercase english
 * letters, which can be used to form words by pushing them. for example, the
 * key 2 is mapped with [a, b, c], we need to push the key one time to type 'a',
 * two times to type 'b', and three times to type 'c'. it is allowed to remap
 * the keys numbered 2 to 9 to distinct collections of letters. the keys can be
 * remapped to any amount of letters, but each letter must be mapped to exactly
 * one key. you need to find the minimum number of times the keys will be pushed
 * to type the string 'word'. return the minimum number of pushes needed to type
 * 'word' after remapping the keys.
 */

int cmp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int minimumPushes(char *word) {
  int cnt[26] = {0}, ans = 0;
  for (int i = 0; word[i] != '\0'; i++)
    cnt[word[i] - 'a']++;
  qsort(cnt, 26, sizeof(int), cmp);
  for (int i = 0; i < 26; i++)
    ans += cnt[i] * (i / 8 + 1);
  return ans;
}

int main() {
  char *w1 = "abcde";
  char *w2 = "xyzxyzxyzxyz";
  char *w3 = "aabbccddeeffgghhiiiiii";
  int r1 = minimumPushes(w1);
  int r2 = minimumPushes(w2);
  int r3 = minimumPushes(w3);
  printf("%d\n", r1);
  assert(r1 == 5);
  printf("%d\n", r2);
  assert(r2 == 12);
  printf("%d\n", r3);
  assert(r3 == 24);
}
