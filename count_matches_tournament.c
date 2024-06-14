// 1688. Count of Matches in Tournament
#include "leetcode.h"
#include <stdio.h>

/*
 * given an integer 'n', the number of teams in a tournament that has strange
 * rules: if the current number of teams is even, each team get paired with
 * another team. a total of 'n / 2' matches are played, and 'n / 2' teams
 * advance to the next round. if the current number of teams is odd, one team
 * randomly advances in the tournament and the rest gets paired. a total of '(n
 * - 1) / 2' matches are played, and '(n - 1) / 2 + 1' teams advance to the next
 * round. return the number of matches played in the tournament until a winner
 * is decided
 */

int numberOfMatches(int n) {
  int ans = 0;
  while (n > 1) {
    int tmp = !(n % 2) ? n / 2 : (n - 1) / 2;
    ans += tmp;
    n -= tmp;
  }
  return ans;
}

int main() {
  printf("%d\n", numberOfMatches(7));  // expect: 6
  printf("%d\n", numberOfMatches(14)); // expect: 13
  printf("%d\n", numberOfMatches(28)); // expect: 27
}
