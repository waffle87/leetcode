// 1813. Sentence Similarity III
#include "leetcode.h"

/*
 * a sentence is a list of words that are separated by a single space with no
 * leading or trailing spaces. for example, "hello world", "hello", and
 * "hellohello world world" are all sentences. words consist of only uppercase
 * and lowercase english letters. two sentences 's1' and 's2' are similar if it
 * is possible to insert an arbitrary sentence possibly empty inside one of
 * these sentences such that the two sentences become equal. given two sentences
 * 's1' and 's2', return true if 's1' and 's2' are similar, otherwise return
 * false.
 */

bool cmp_str(char *s1, char *s2) {
  int i, n1 = strlen(s1), n2 = strlen(s2);
  for (i = 0; i < n1; i++)
    if (s1[i] != s2[i])
      break;
  if (i == n1 && s2[i] == ' ')
    return true;
  i--;
  while (i >= 0 && s2[i] != ' ')
    i--;
  i = fmax(0, i);
  int d = 1;
  for (int j = n1 - 1; j >= i; j--) {
    if (s1[j] != s2[n2 - d])
      return false;
    if (j == i) {
      if (!i) {
        if (s2[n2 - d - 1] != ' ')
          return false;
      } else {
        if (s2[n2 - d] != ' ')
          return false;
      }
    }
    d++;
  }
  return true;
}

bool areSentencesSimilar(char *s1, char *s2) {
  int n1 = strlen(s1), n2 = strlen(s2);
  if (n1 == n2) {
    for (int i = 0; i < n1; i++)
      if (s1[i] != s2[i])
        return false;
    return true;
  }
  return n1 < n2 ? cmp_str(s1, s2) : cmp_str(s2, s1);
}

int main() {
  char *s11 = "My name is Haley", *s21 = "My Haley";
  char *s12 = "of", *s22 = "A lot of words";
  char *s13 = "Eating right now", *s23 = "Eating";
  printf("%d\n", areSentencesSimilar(s11, s21)); // expect: 1
  printf("%d\n", areSentencesSimilar(s12, s22)); // expect: 0
  printf("%d\n", areSentencesSimilar(s13, s23)); // expect: 1
}
