// 650. 2 Keys Keyboard
#include "leetcode.h"

/*
 * there is only one character 'A' on the screen of a notepad. you can perform
 * one of two operations on this notepad for each step. copy all characters
 * present on the screen (a partial copy is not allowed). paste the characters
 * which are copied last time. given an integer 'n', return the minimum number
 * of operations to get the character 'A' exactly 'n' times on the screen.
 */

int minSteps(int n) {
  const int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  if (n <= 5)
    return n == 1 ? 0 : n;
  for (int i = 0; i < 11; i++)
    if (!(n % primes[i]))
      return primes[i] + minSteps(n / primes[i]);
  return n;
}

int main() {
  printf("%d\n", minSteps(3)); // expect: 3
  printf("%d\n", minSteps(1)); // expect: 0
}
