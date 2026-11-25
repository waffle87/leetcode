// 3934. Smallest Unique Subarray
#include "leetcode.h"

struct entry {
  long long key;
  int state;
};

long long mod_pow(long long base, int exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1)
      res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return res;
}

int find_slow(struct entry *table, int cap, long long key) {
  uint64_t hash = (uint64_t)key;
  hash ^= hash >> 16;
  hash *= 0x9E3779B97f4A7C15ULL;
  hash ^= hash >> 32;
  int idx = hash & (cap - 1);
  while (table[idx].state != 0 && table[idx].key != key)
    idx = (idx + 1) & (cap - 1);
  return idx;
}

int smallestUniqueSubarray(int *nums, int numsSize) {
  int low = 0, high = numsSize + 1, ans = -1;
  const long long base = 100003, mod = 1000000007;
  int capacity = 1;
  while (capacity < 2 * numsSize)
    capacity <<= 1;
  while (low < high) {
    int mid = low + (high - low) / 2, unique = 0;
    struct entry *table =
        (struct entry *)calloc(capacity, sizeof(struct entry));
    long long subarr = 0, pow1 = mod_pow(base, mid - 1, mod);
    for (int i = 0; i + mid <= numsSize; i++) {
      if (!i) {
        for (int j = i; j < i + mid; j++)
          subarr = (subarr * base + nums[j]) % mod;
      } else {
        subarr = (subarr - nums[i - 1] * pow1 % mod + mod);
        subarr = (subarr * base + nums[i + mid - 1]) % mod;
      }
      int idx = find_slow(table, capacity, subarr);
      if (table[idx].state == 2)
        continue;
      else if (table[idx].state == 1) {
        table[idx].state = 2;
        unique--;
      } else {
        table[idx].key = subarr;
        table[idx].state = 1;
        unique++;
      }
    }
    free(table);
    if (unique > 0) {
      high = mid;
      ans = mid;
    } else
      low = mid + 1;
  }
  return ans;
}

int main() {
  int n1[] = {3, 3, 3};
  int n2[] = {2, 1, 2, 3, 3};
  int n3[] = {1, 1, 2, 2, 1};
  int r1 = smallestUniqueSubarray(n1, ARRAY_SIZE(n1));
  int r2 = smallestUniqueSubarray(n2, ARRAY_SIZE(n2));
  int r3 = smallestUniqueSubarray(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == 2);
}
