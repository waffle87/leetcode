// 3518. Smallest Palindromic Rearrangement II
#include "leetcode.h"

/*
 * you are given a palindromic string 's' and an integer 'k'. return the k-th
 * lexicographically smallest palindromic permutation of 's'. if there are fewer
 * than 'k' distinct palindromic permutations, return an empty string.
 */

long long comb(long long n, long long m, long long k) {
  long long res = 1;
  if (n - m < m)
    m = n - m;
  for (long long i = 1; i <= m; i++) {
    res = res * (n - i + 1) / i;
    if (res > k)
      return k + 1;
  }
  return res;
}

long long permutations(int rem, int *bucket, long long k) {
  long long ways = 0;
  for (int i = 0; i < 26; i++) {
    if (!bucket[i])
      continue;
    ways *= comb(rem, bucket[i], k);
    if (ways > k)
      break;
    rem -= bucket[i];
  }
  return ways;
}

char *smallestPalindrome(char *s, int k) {
  int n = strlen(s), partition = n / 2, bucket[26] = {0};
  for (int i = 0; i < partition; i++)
    bucket[s[i] - 'a']++;
  char *left = (char *)malloc((partition + 1) * sizeof(char));
  int left_idx = 0;
  long long start_idx = 1;
  for (int pos = 0; pos < partition; pos++) {
    for (int i = 0; i < 26; i++) {
      if (!bucket[i])
        continue;
      bucket[i]--;
      long long ways = permutations(partition - pos - 1, bucket, k);
      if (start_idx + ways > k) {
        left[left_idx++] = i + 'a';
        break;
      }
      bucket[i]++;
      start_idx += ways;
    }
  }
  left[left_idx] = '\0';
  if (left_idx < partition) {
    char *empty = (char *)malloc(1 * sizeof(char));
    empty[0] = '\0';
    free(left);
    return empty;
  }
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  int ans_idx = 0;
  for (int i = 0; i < partition; i++)
    ans[ans_idx++] = left[i];
  if (n % 2)
    ans[ans_idx++] = s[partition];
  for (int i = partition - 1; i >= 0; i--)
    ans[ans_idx++] = left[i];
  ans[ans_idx] = '\0';
  free(left);
  return ans;
}

int main() {
  char *s1 = "abba", *r1 = "baab";
  char *s2 = "aa", *r2 = "";
  char *s3 = "bacab", *r3 = "abcba";
  char *sp1 = smallestPalindrome(s1, 2);
  char *sp2 = smallestPalindrome(s2, 2);
  char *sp3 = smallestPalindrome(s3, 1);
  printf("%s\n", sp1);
  assert(!strcmp(sp1, r1));
  printf("%s\n", sp2);
  assert(!strcmp(sp2, r2));
  printf("%s\n", sp3);
  assert(!strcmp(sp3, r3));
  free(sp1);
  free(sp2);
  free(sp3);
}
