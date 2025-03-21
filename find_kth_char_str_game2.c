// 3307. Find the K-th Character in String Game II
#include "leetcode.h"

/*
 * alice and bob are playing a game. initially, alice has a string 'word = "a"'.
 * you are given a positive integer 'k'. you are also given an integer array
 * 'operations' where 'operations[i]' represents the type of i'th operation. now
 * bob will ask alice to perform all operations in sequence: if 'operations[i]
 * == 0', append a copy of 'word' to itself. if 'operations[i] == 1', generate a
 * new string by changing each character in 'word' to its next character in the
 * english alphabet, and append it to the origin 'word'. return the value of the
 * k'th character in 'word' after performing all the operations.
 */

char kthCharacter(long long k, int *operations, int operationsSize) {
  int ans = 0;
  k--;
  for (int i = 0; i < operationsSize && i < 60; ++i)
    if ((k >> i) % 2)
      ans += operations[i];
  return (char)('a' + ans % 26);
}

int main() {
  int o1[] = {0, 0, 0}, o2[] = {0, 1, 0, 1};
  printf("%c\n", kthCharacter(5, o1, ARRAY_SIZE(o1)));  // expect: a
  printf("%c\n", kthCharacter(10, o2, ARRAY_SIZE(o2))); // expect: b
}
