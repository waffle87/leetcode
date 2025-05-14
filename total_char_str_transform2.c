// 3337. Total Characters in String After Transformations II
#include "leetcode.h"

/*
 * you are given a string 's' consisting of lowercase english letters, an
 * integer 't' representing the number of transformations to perform, and an
 * array 'nums' of size 26. in one transformation, every character in 's' is
 * replaced according to the following rules: replace 's[i]' with the next
 * 'nums[s[i] - 'a']' consecutive characters in the alphabet. the transformation
 * wraps around the alphabet if it exceeds 'z'. return the length of the
 * resulting string after exactly 't' tranformations.
 */

const int mod = 1e9 + 7;
typedef long long matrix[26][26];

void multiply(const matrix a, const matrix b, matrix res) {
  matrix tmp = {{0}};
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) {
      if (!a[i][j])
        continue;
      for (int k = 0; k < 26; k++)
        tmp[i][k] = (tmp[i][k] + a[i][j] * b[j][k]) % mod;
    }
  memcpy(res, tmp, sizeof(tmp));
}

void power(const matrix base, int power, matrix res) {
  matrix curr, ident = {{0}};
  memcpy(curr, base, sizeof(curr));
  for (int i = 0; i < 26; i++)
    ident[i][i] = 1;
  while (power > 0) {
    if (power & 1) {
      matrix tmp;
      multiply(ident, curr, tmp);
      memcpy(ident, tmp, sizeof(tmp));
    }
    matrix sqr;
    multiply(curr, curr, sqr);
    memcpy(curr, sqr, sizeof(sqr));
    power >>= 1;
  }
  memcpy(res, ident, sizeof(ident));
}

int lengthAfterTransformations(char *s, int t, int *nums, int numsSize) {
  (void)numsSize;
  long long cnt[26] = {0};
  for (char *i = s; *i; i++)
    cnt[*i - 'a']++;
  matrix transform = {{0}};
  for (int i = 0; i < 26; i++)
    for (int j = 1; j <= nums[i]; j++)
      transform[i][(i + j) % 26]++;
  matrix pow;
  power(transform, t, pow);
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (!cnt[i])
      continue;
    for (int j = 0; j < 26; j++)
      ans = (ans + cnt[i] * pow[i][j]) % mod;
  }
  return ans;
}

int main() {
  char *s1 = "abcyy", *s2 = "azbk";
  int n1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};
  int n2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
              2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  printf("%d\n",
         lengthAfterTransformations(s1, 2, n1, ARRAY_SIZE(n1))); // expect: 7
  printf("%d\n",
         lengthAfterTransformations(s2, 1, n2, ARRAY_SIZE(n2))); // expect: 8
}
