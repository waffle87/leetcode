// 1927. Sum Game
#include "leetcode.h"

/*
 * alice and bob take turns playing a game, with alice starting first. you are
 * given a string 'num' of even length consisting of digits and '?' characters.
 * on each turn, a player will do the following if there is still at least one
 * '?' in 'num': choose an index 'i' where 'num[i] == ?', replace 'num[i]' with
 * any digit between 0 and 9. the game ends when there are no more '?'
 * characters in 'num'. for bob to win, the sum of the digits in the first half
 * of 'num' must be equal to the sum of the digits in the second half. for alice
 * to win, the sums must not be equal. assuming both play optimally, return true
 * if alice will and false if bob will win.
 */

bool sumGame(char *num) {
  int sum[2] = {0}, q[2] = {0};
  int n = strlen(num);
  for (int i = 0; i < n; i++) {
    int j = i / (n >> 1);
    if (num[i] == '?')
      q[j]++;
    else
      sum[j] += num[i] - '0';
  }
  return ((q[0] + q[1]) & 1) || ((sum[0] - sum[1]) << 1) != (q[1] - q[0]) * 9;
}

int main() {
  char *n1 = "5023";
  char *n2 = "25??";
  char *n3 = "?3295???";
  bool r1 = sumGame(n1);
  bool r2 = sumGame(n2);
  bool r3 = sumGame(n3);
  printf("%d\n", r1);
  assert(r1 == false);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == false);
}
