// 2193. Minimum Number of Moves to Make Palindrome
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's' consisting of only lowercase ascii characters.
 * in one move you can select any two adjacent characters of 's'
 * and swap them. return the minimum number of moves needed to
 * make 's' a palindrome. note that the input will be generated
 * such that 's' can always be converted to a palindrome
 */

void helper(char *s, int now, int len, int *ans) {
  while (now < len) {
    while (s[len] == 'A')
      len--;
    if (s[now] == s[len])
      return;
    else {
      int copy = now + 1;
      if (s[copy] == 'A')
        *ans -= 1;
      while (s[len] != s[copy]) {
        copy++;
        if (s[copy] == 'A')
          *ans -= 1;
      }
      *ans += copy - now;
      s[copy] = 'A';
      len--;
    }
  }
}

void find_min(char *s, int now, int len, int *ans) {
  while (now < len) {
    while (s[now] == 'A')
      now++;
    while (s[len] == 'A')
      len--;
    if (s[now] == s[len]) {
      now++;
      len--;
    } else {
      int copy = len - 1, copy_a = *ans;
      if (s[copy] == 'A')
        *ans -= 1;
      while (s[now] != s[copy]) {
        copy--;
        if (s[copy] == 'A')
          *ans -= 1;
      }
      if (copy != now) {
        *ans += len - copy;
        s[copy] = 'A';
      } else {
        *ans = copy_a;
        helper(s, now, len, ans);
      }
      now++;
    }
  }
}

int minMovesToMakePalindrome(char *s) {
  int len = strlen(s), ans = 0;
  find_min(s, 0, len - 1, &ans);
  return ans;
}

int main() {
  char s1[] = {"aabb"}, s2[] = {"letelt"};
  printf("%d\n", minMovesToMakePalindrome(s1)); // expect: 2
  printf("%d\n", minMovesToMakePalindrome(s2)); // expect: 2
}
