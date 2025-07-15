// 3136. Valid Word
#include "leetcode.h"

/*
 * a word is considered valid if it contains a minimum of three characters, it
 * contains only digits (0-9), and english letters (uppercase and lowercase), it
 * includes at least one vowel, and it includes one consonant. you are given a
 * string 'word'. return true if 'word' is valid, otherwise return false.
 */

bool isvowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool isValid(char *word) {
  bool vowel = false, consonant = false, invalid = false;
  for (int i = 0; word[i]; i++)
    if (isalnum(word[i])) {
      if (isalpha(word[i])) {
        if (isvowel(word[i]))
          vowel = true;
        else
          consonant = true;
      }
    } else {
      invalid = true;
      break;
    }
  return (strlen(word) > 2 && vowel && consonant && !invalid);
}

int main() {
  char *w1 = "234Adas", *w2 = "b3", *w3 = "a3$e";
  printf("%d\n", isValid(w1)); // expect: 1
  printf("%d\n", isValid(w2)); // expect: 0
  printf("%d\n", isValid(w3)); // expect: 0
}
