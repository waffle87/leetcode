// 205. Isomorphic Strings
#include "leetcode.h"

/*
 * given two strings 's' and 't', determine if they are isomorphic. two strings
 * 's' and 't' are isomorphic if the characters in 's' can be replaced to get
 * 't'. all occurences of a character must be replaced with another character
 * while presevering the order of characters. no two characters may map to the
 * same character, but a character may map to itself.
 */

bool isIsomorphic(char *s, char *t) {
  int s1[256] = {0}, t1[256] = {0}, n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s1[(int)s[i]] != t1[(int)t[i]])
      return 0;
    s1[(int)s[i]] = i + 1;
    t1[(int)t[i]] = i + 1;
  }
  return 1;
}

int main() {
  char *s1 = "egg", *t1 = "add", *s2 = "foo", *t2 = "bar", *s3 = "paper",
       *t3 = "title";
  printf("%d\n", isIsomorphic(s1, t1)); // expect: 1
  printf("%d\n", isIsomorphic(s2, t2)); // expect: 0
  printf("%d\n", isIsomorphic(s3, t3)); // expect: 1
}
