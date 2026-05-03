// 796. Rotate String
#include "leetcode.h"

/*
 * given two strings 's' and 'goal', return 'true' if and only if 's' can become
 * 'goal' after some number of shifts on 's'. a shift on 's' consists of moving
 * the leftmost character of 's' to the rightmost position. for example, if 's =
 * "abcde"', then it will be "bcdea" after one shift.
 */

static inline uint64_t ror1(uint64_t val) {
  return (val >> 1) | ((val & 1ULL) << 63);
}

static inline uint64_t ror2(uint64_t val, int shift) {
  shift &= 63;
  if (!shift)
    return val;
  return (val >> shift) | (val << (64 - shift));
}

static uint64_t rolling_sum(const char *s) {
  uint64_t ret = 0;
  while (*s) {
    ret = ror1(ret) ^ (unsigned char)(*s);
    ++s;
  }
  return ret;
}

static bool rot_equal(const char *s1, const char *s2, int rotation, int n) {
  if (memcmp(s1 + rotation, s2, n - rotation))
    return false;
  if (memcmp(s1, s2 + (n - rotation), rotation))
    return false;
  return true;
}

bool rotateString(char *s, char *goal) {
  int n = strlen(s);
  if (n != (int)strlen(goal))
    return false;
  uint64_t rot_sum = rolling_sum(s);
  uint64_t rot_goal = rolling_sum(goal);
  for (int i = 0; i < n; ++i) {
    if (rot_sum == rot_goal && rot_equal(s, goal, i, n))
      return true;
    rot_sum =
        ror1(rot_sum) ^ (unsigned char)s[i] ^ ror2((unsigned char)s[i], n);
  }
  return false;
}

int main() {
  char *s1 = "abcde", *g1 = "cdeab";
  char *s2 = "abcde", *g2 = "abced";
  int r1 = rotateString(s1, g1);
  int r2 = rotateString(s2, g2);
  printf("%d\n", r1); // expect: 1
  assert(r1 == 1);
  printf("%d\n", r2); // expect: 0
  assert(r2 == 0);
}
