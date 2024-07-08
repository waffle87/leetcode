// 1823. Find the Winner of the Circular Game
#include "leetcode.h"

/*
 * there are 'n' friends that are playing a game. the friends are sitting in a
 * circule and are numbered from 1 to 'n' in clockwise order. more formally,
 * moving clockwise from the i'th friend brings you to the '(i + 1)'th friend
 * for '1 <= i < n', and moving clockwise from the n'th friend brings you to the
 * 1st friend. given the number of friends, 'n' and an integer 'k', return the
 * winner of the game.
 */

int findTheWinner(int n, int k) {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + k) % i;
  return ans + 1;
}

int main() {
  printf("%d\n", findTheWinner(5, 2)); // expect: 3
  printf("%d\n", findTheWinner(6, 5)); // expect: 1
}
