// 3577. Count the Number of Computer Unlocking Permutations
#include "leetcode.h"

/*
 * you are given an array 'complexity' of length 'n'. there are 'n' computers
 * locked in a room with labels from 0 to 'n - 1', each with its own unique
 * password. the password of the computer 'i' has a complexity 'complexity[i]'.
 * the password for the computer labeled 0 is already decrypted and serves as
 * the root. all other computers must be unlocked using it or another previously
 * unlocked computer. you can decrypt the password for the computer 'i' using
 * the password for computer 'j' where 'j' is any integer less than 'i' with a
 * lower complexity. to decrypt the password for computer 'i', you must already
 * unlocked computer 'j'. find the number of permutations that represent a valid
 * order in which the computers can be unlocked.
 */

int countPermutations(int *complexity, int complexitySize) {
  static int mod = 1e9 + 7;
  long ans = 1;
  for (int i = 1; i < complexitySize; i++) {
    if (complexity[i] <= complexity[0])
      return 0;
    else
      ans = (ans * i) % mod;
  }
  return ans;
}

int main() {
  int c1[] = {1, 2, 3}, c2[] = {3, 3, 3, 4, 4, 4};
  printf("%d\n", countPermutations(c1, ARRAY_SIZE(c1))); // expect: 2
  printf("%d\n", countPermutations(c2, ARRAY_SIZE(c2))); // expect: 0
}
