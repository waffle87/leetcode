// 3186. Maximum Total Damage With Spell Casting
#include "leetcode.h"

/*
 * a magician has various spells. you are given an array 'power', where each
 * element represents the damage of a spell. multiple spells can have the same
 * damage value. it is a known fact that if a magician decides to cast a spell
 * with a damage of 'power[i]', they cannot cast any spell with a damage of
 * 'power[i] - 2', 'power[i] - 1', 'power[i] + 1', or 'power[i] + 2'. each spell
 * can only be cast once. return the maximum possible total damage that a
 * magician can cast.
 */

long long maximumTotalDamage(int *power, int powerSize) {
  long long freq[100001] = {0}, dp[100001] = {0};
  for (int i = 0; i < powerSize; i++)
    freq[power[i]]++;
  int keys[100001], n = 0;
  for (int i = 0; i <= 100000; i++)
    if (freq[i])
      keys[n++] = i;
  dp[0] = freq[keys[0]] * keys[0];
  for (int i = 1; i < n; i++) {
    long long take = freq[keys[i]] * keys[i];
    int prev = -1;
    for (int j = i - 1; j >= 0; j--)
      if (keys[j] <= keys[i] - 3) {
        prev = j;
        break;
      }
    if (prev >= 0)
      take += dp[prev];
    dp[i] = dp[i - 1] > take ? dp[i - 1] : take;
  }
  return dp[n - 1];
}

int main() {
  int p1[] = {1, 1, 3, 4}, p2[] = {7, 1, 6, 6};
  printf("%lld\n", maximumTotalDamage(p1, ARRAY_SIZE(p1))); // expect: 6
  printf("%lld\n", maximumTotalDamage(p2, ARRAY_SIZE(p2))); // expect: 13
}
