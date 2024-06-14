// 2063. Vowels of All Substrings
#include <stdio.h>
#include <string.h>

/*
 * given a string 'word, return thesum of the number of vowels (a, e, i, o, u)
 * in every substring of 'word'. a substringis a contiguous (non-empty) sequence
 * of characters within a string. note, due to the large constraints, the answer
 * may not fit in a signed 32-bit integer. please be careful during
 * calculates...
 */

long long countVowels(char *word) {
  long long ans = 0;
  int n = strlen(word);
  for (int i = 0; i < n; i++)
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' ||
        word[i] == 'u')
      ans += (long long)(i + 1) * (n - i);
  return ans;
}

int main() {
  char w1[] = {"aba"}, w2[] = {"abc"}, w3[] = {"ltcd"};
  printf("%lld\n", countVowels(w1)); // expect: 6
  printf("%lld\n", countVowels(w2)); // expect: 3
  printf("%lld\n", countVowels(w3)); // expect: 0
}
