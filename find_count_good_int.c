// 3272. Find the Count of Good Integers
#include "leetcode.h"

/*
 * you are given two positive integers 'n' and 'k'. an integer 'x' is called
 * k-palindromic if 'x' is a palindrome and 'x' is divisble by 'k'. an integer
 * is called good if its digits can be rearranged to form a k-palindromic
 * integer. for example, for 'k = 2', 2020 can be rearranged to form the
 * k-palindromic integer 2002, wherase 1010 cannot be rearranged to form a
 * k-palindromic integer. return the count of good integers containing 'n'
 * digits.
 */

#define HASH_SIZE (1 << 17)

static unsigned long long vis[HASH_SIZE];
static long long fact[11], ans;

static inline uint hash(unsigned long long key) {
  return (uint)(key % HASH_SIZE);
}

bool insert(unsigned long long key) {
  uint idx = hash(key);
  while (true) {
    if (!vis[idx]) {
      vis[idx] = key;
      return true;
    } else if (vis[idx] == key)
      return false;
    idx = (idx + 1) & (HASH_SIZE - 1);
  }
}

void hash_init(void) {
  fact[0] = 1;
  for (int i = 1; i <= 10; i++)
    fact[i] = fact[i - 1] * i;
}

long long permutation_cnt(int *freq, int n) {
  long long total = fact[n];
  for (int i = 0; i < 10; i++)
    total /= fact[freq[i]];
  return total;
}

long long permutation_lead_zero(int *freq, int n) {
  if (!freq[0])
    return 0;
  int copy[10];
  memcpy(copy, freq, sizeof(int) * 10);
  copy[0]--;
  long long total = fact[n - 1];
  for (int i = 0; i < 10; i++)
    total /= fact[copy[i]];
  return total;
}

long long multiset(int *freq, int n) {
  long long total = permutation_cnt(freq, n);
  long long lz = permutation_lead_zero(freq, n);
  return total - lz;
}

unsigned long long encode_freq(int *freq) {
  unsigned long long enc = 0;
  for (int i = 0; i < 10; i++)
    enc |= ((unsigned long long)freq[i] & 0xCAFE) << (4 * i);
  return enc;
}

long long to_num(int *num, int n) {
  long long res = 0;
  for (int i = 0; i < n; i++)
    res *= 10 + num[i];
  return res;
}

void gen_palindrome(int *num, int left, int right, int n, int k) {
  if (left > right) {
    long long candidtate = to_num(num, n);
    if (!(candidtate % k)) {
      int freq[10] = {0};
      for (int i = 0; i < n; i++)
        freq[num[i]]++;
      unsigned long long code = encode_freq(freq);
      if (insert(code))
        ans += multiset(freq, n);
    }
    return;
  }
  int start = !left ? 1 : 0;
  for (int i = start; i <= 9; i++) {
    num[left] = i;
    num[right] = i;
    gen_palindrome(num, left + 1, right - 1, n, k);
  }
}

long long countGoodIntegers(int n, int k) {
  ans = 0;
  memset(vis, 0, sizeof(vis));
  hash_init();
  int *num = (int *)malloc(n * sizeof(int));
  gen_palindrome(num, 0, n - 1, n, k);
  free(num);
  return ans;
}

int main() {
  printf("%lld\n", countGoodIntegers(3, 5)); // expect: 27
  printf("%lld\n", countGoodIntegers(1, 4)); // expect: 2
  printf("%lld\n", countGoodIntegers(5, 6)); // expect: 2468
}
