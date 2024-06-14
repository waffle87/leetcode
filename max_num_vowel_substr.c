// 1456. Maximum Number of Vowels in a Substring of Given Length
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's' and an integer 'k', return the maximum
 * number of vowel letters in any substring of 's' with length
 * 'k'. vowel letters in english are 'a e i o u'
 */

int maxVowels(char *s, int k) {
  int n = strlen(s), vowel = 0;
  for (int i = 0; i < k; i++)
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      vowel++;
  if (vowel == k)
    return k;
  int max = vowel;
  for (int i = k; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      vowel++;
    if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' ||
        s[i - k] == 'o' || s[i - k] == 'u')
      vowel--;
    max = fmax(max, vowel);
    if (max == k)
      return max;
  }
  return max;
}

int main() {
  char s1[] = {"abciiidef"}, s2[] = {"aeiou"}, s3[] = {"leetcode"};
  printf("%d\n", maxVowels(s1, 3)); // expect: 3
  printf("%d\n", maxVowels(s2, 2)); // expect: 2
  printf("%d\n", maxVowels(s3, 3)); // expect: 2
}
