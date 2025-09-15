// 1935. Maximum Number of Words You Can Type
#include "leetcode.h"

/*
 * there is a malfunctioning keyboard where some letter keys do not work. all
 * other keys on the keyboard work properly. given a string of words 'text'
 * separated by a single space, and a string 'brokenLetters' of all distinct
 * letter keys that are broken, return the number of words in 'text' you can
 * fully type using this keyboard.
 */

int mask(char *s) {
  int n = strlen(s), res = 0;
  for (int i = 0; i < n; i++)
    res = res | (1 << (s[i] - 'a'));
  return res;
}

int canBeTypedWords(char *text, char *brokenLetters) {
  int broken = mask(brokenLetters);
  int n = strlen(text), ans = 0, curr = 0;
  for (int i = 0; i < n; i++) {
    if (text[i] == ' ') {
      if (!(curr & broken))
        ans++;
      curr = 0;
    } else
      curr = curr | (1 << (text[i] - 'a'));
  }
  if (!(curr & broken))
    ans++;
  return ans;
}

int main() {
  char *t1 = "hello world", *bl1 = "ad";
  char *t2 = "leet code", *bl2 = "lt";
  char *t3 = "leet code", *bl3 = "e";
  printf("%d\n", canBeTypedWords(t1, bl1)); // expect: 1
  printf("%d\n", canBeTypedWords(t2, bl2)); // expect: 1
  printf("%d\n", canBeTypedWords(t3, bl3)); // expect: 0
}
