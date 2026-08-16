// 2029. Stone Game IX
#include "leetcode.h"

/*
 * alice and bob continue their games with stones. there is a row of 'n' stones,
 * and each stone has an associated value. you are given an integer array
 * 'stones', where 'stones[i]' is the value of the i'th stone. alice and bob
 * take turns, with alice starting first. on each turn, the player may remove
 * any stone from 'stones'. the player who removes a stone loses if the sum of
 * the values of all removed stones is divisble by 3. bob will win automatically
 * if there are no  remaining stones (even if it is alice's turn). assuming both
 * players play optimally, return true if alice wins and false if bob wins.
 */

bool stoneGameIX(int *stones, int stonesSize) {
  int freq[3] = {0};
  for (int i = 0; i < stonesSize; i++)
    freq[stones[i] % 3]++;
  if (~freq[0] & 1)
    return fmin(freq[1], freq[2]) >= 1;
  return abs(freq[1] - freq[2]) >= 3;
}

int main() {
  int s1[] = {2, 1}, s2[] = {2}, s3[] = {5, 1, 2, 4, 3};
  bool r1 = stoneGameIX(s1, ARRAY_SIZE(s1));
  bool r2 = stoneGameIX(s2, ARRAY_SIZE(s2));
  bool r3 = stoneGameIX(s3, ARRAY_SIZE(s3));
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
  printf("%d\n", r3);
  assert(r3 == false);
}
