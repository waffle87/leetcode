// 2000. Reverse Prefix of Word
#include "leetcode.h"

/*
 * given a 0-indexed string 'word' and a character 'ch', reverse the segment of
 * 'word' that starts at index 0 and ends at the index of the first occurence of
 * 'ch' (inclusively). if the character 'ch' does not exist in 'word', do
 * nothing. return the resulting string.
 */

char *reversePrefix(char *word, char ch) {
  int n = strlen(word), loc = -1;
  for (int i = 0; i < n; i++)
    if (word[i] == ch) {
      loc = i;
      break;
    }
  if (loc == -1)
    return word;
  for (int i = 0; i <= loc / 2; i++) {
    char tmp = word[i];
    word[i] = word[loc - i];
    word[loc - i] = tmp;
  }
  return word;
}

int main() {
  char *w1 = "abcdefd", *w2 = "xyxzxe", *w3 = "abcd";
  printf("%s\n", reversePrefix(w1, 'd')); // expect: dcbaefd
  printf("%s\n", reversePrefix(w2, 'z')); // expect: zxyxxe
  printf("%s\n", reversePrefix(w3, 'z')); // expect: abcd
}
