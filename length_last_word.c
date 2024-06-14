// 58. Length of Last Word
#include "leetcode.h"

/*
 * given a string 's' consisting of words and spaces, return the length of the
 * last word in the string. a word is a maximal substring consisting of non
 * space characters only.
 */

int lengthOfLastWord(char *s) {
  int ans = 0, i = strlen(s) - 1;
  if (s[i] == ' ')
    while (i >= 0 && s[i] == ' ')
      i--;
  while (i >= 0) {
    if (s[i] == ' ')
      break;
    if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))
      ans++;
    i--;
  }
  return ans;
}

int main() {
  char *s1 = "Hello World", *s2 = "   fly me   to   the moon  ",
       *s3 = "luffy is still joyboy";
  printf("%d\n", lengthOfLastWord(s1)); // expect: 5
  printf("%d\n", lengthOfLastWord(s2)); // expect: 4
  printf("%d\n", lengthOfLastWord(s3)); // expect: 6
}
