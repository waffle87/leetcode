// 2490. Circular Sentence
#include "leetcode.h"

/*
 * a sentence is a list of words that are separated by a single space with no
 * leading or trailing spaces. words consist of only uppercase and lowercase
 * english letters. uppercase and lowercase english letters are considered
 * different. a sentence is circular if the last character of a word is equal to
 * the first character of the next word, the last chracter of the last word is
 * equal to the first character of the first word. given a string 'sentence',
 * return 'true' if it is a circular sentence, and 'false' otherwise.
 */

bool isCircularSentence(char *sentence) {
  int n = strlen(sentence);
  if (sentence[0] != sentence[n - 1])
    return false;
  for (int i = 0; i < n; i++)
    if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
      return false;
  return true;
}

int main() {
  char *s1 = "leetcode exercises sound delightful", *s2 = "eetcode",
       *s3 = "Leetcode is cool";
  printf("%d\n", isCircularSentence(s1)); // expect: 1
  printf("%d\n", isCircularSentence(s2)); // expect: 1
  printf("%d\n", isCircularSentence(s3)); // expect: 0
}
