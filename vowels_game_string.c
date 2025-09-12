// 3227. Vowels Game in a String
#include "leetcode.h"

/*
 * alice and bob are playing a game on a string. you are given a string 's',
 * alice and bob will take turns playing the following game where alice starts
 * first. on alice's turn, she has to remove any non-empty substring from 's'
 * that contains an odd number of vowels. on bob's turn, he has to remove any
 * non-empty substring from 's' that contains an even number of vowels. the
 * first player who cannot make a move on their turn loses the game. we assume
 * that both bob and alice play optimally. return true if alice wins, and false
 * otherwise.
 */

bool doesAliceWin(char *s) {
  for (; *s; ++s) {
    char curr = *s;
    if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
      return true;
  }
  return false;
}

int main() {
  char *s1 = "leetcoder", *s2 = "bbcd";
  printf("%d\n", doesAliceWin(s1)); // expect: 1
  printf("%d\n", doesAliceWin(s2)); // expect: 0
}
