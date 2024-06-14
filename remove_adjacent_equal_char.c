// 2957. Remove Adjacent Almost-Equal Characters
#include "leetcode.h"

/*
 * you are given a 0 indexed string 'word'. in one operation you can pick any
 * index 'i' of 'word' and change 'word[i]' to any lowercase english letter.
 * return the minimum number of operations needed to remove all adjacent almost
 * equal characters from 'word'. two characters 'a' and 'b' are almost equal if
 * 'a == b' or 'a' and 'b' are adjacent in the alphabet
 */

int removeAlmostEqualCharacters(char *word) {
  int n = strlen(word), ans = 0;
  if (n == 1)
    return 0;
  else if (n == 2)
    return abs(word[0] - word[1]) < 2 ? 1 : 0;
  for (int i = 0; i < n - 2; i++) {
    if (abs(word[i + 1] - word[i]) < 2) {
      if (abs(word[i + 1] - word[i + 2]) < 2) {
        ans++;
        word[i + 1] = ' ';
      } else {
        ans++;
        word[i] = ' ';
      }
    } else if (abs(word[i + 1] - word[i + 2]) < 2) {
      ans++;
      word[i + 2] = ' ';
    }
  }
  return ans;
}

int main() {
  char *w1 = "aaaaa", *w2 = "abddez", *w3 = "zyxyxyz";
  printf("%d\n", removeAlmostEqualCharacters(w1)); // expect: 2
  printf("%d\n", removeAlmostEqualCharacters(w2)); // expect: 2
  printf("%d\n", removeAlmostEqualCharacters(w3)); // expect: 3
}
