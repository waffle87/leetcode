// 2516. Take K of Each Character From Left and Right
#include "leetcode.h"

/*
 * you are given a string 's' consisting of the characters 'a', 'b', and 'c' and
 * a non-negative integer 'k'. each minute you may take either the leftmost
 * character of 's' or the rightmost character of 's'. return the minimum number
 * of minutes needed for you to take at least 'k' of each character, or return
 * -1 if it is not possible t to take 'k' of each character.
 */

bool check(int *arr, int *curr, int k) {
  if (curr[0] > arr[0] - k || curr[1] > arr[1] - k || curr[2] > arr[2] - k)
    return true;
  return false;
}

int takeCharacters(char *s, int k) {
  int n = strlen(s), arr[3] = {0};
  for (int i = 0; i < n; i++)
    arr[s[i] - 'a']++;
  if (arr[0] < k || arr[1] < k || arr[2] < k)
    return -1;
  int ans = n, window[3] = {0}, i = 0, j = 0;
  while (j < n) {
    window[s[j] - 'a']++;
    j++;
    while (check(arr, window, k)) {
      window[s[i] - 'a']--;
      i++;
    }
    ans = fmin(ans, n - (j - i));
  }
  return ans;
}

int main() {
  char *s1 = "aabaaaacaabc", *s2 = "a";
  printf("%d\n", takeCharacters(s1, 2)); // expect: 8
  printf("%d\n", takeCharacters(s2, 1)); // expect: -1
}
