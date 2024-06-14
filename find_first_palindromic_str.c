// 2108. Find First Palindromic String in the Array
#include "leetcode.h"

/*
 * given an array of strings 'words', return the first palindromic string in the
 * array. if there is no such string, return an empty string. a string is a
 * palindromic if it reads the same forward and backward.
 */

char *firstPalindrome(char **words, int wordsSize) {
  char *ans = "";
  for (int i = 0; i < wordsSize; i++) {
    int start = 0, end = strlen(words[i]) - 1;
    while (start < end) {
      if (words[i][start] != words[i][end])
        break;
      start++;
      end--;
    }
    if (start == end || end < start) {
      ans = words[i];
      break;
    }
  }
  return ans;
}

int main() {
  char **w1 = {"abc", "car", "ada", "racecar", "cool"};
  char **w2 = {"notapalindrome", "racecar"};
  char **w3 = {"def", "ghi"};
  printf("%s\n", firstPalindrome(w1, 5)); // expect: ada
  printf("%s\n", firstPalindrome(w2, 2)); // expect: racecar
  printf("%s\n", firstPalindrome(w3, 2)); // expect: null
}
