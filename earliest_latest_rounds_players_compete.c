// 1900. The Earliest and Latest Rounds Where Players Compete
#include "leetcode.h"

/*
 * there is a tournament where 'n' players are participating. the players are
 * standing a single row and are numbered from 1 to 'n' based on their initial
 * standing position. the tournament consists of multiple rounds. in each round,
 * the i'th player from the front of the row competes against the i'th player
 * from the end of the row, and the winner advances to the next round. when the
 * number of players is odd for the current round, te player is in the middle
 * automatically advances to the next round. after each round is over, the
 * winners are lined back up in the row based on the original ordering assigned
 * to them initially. the players numbered 'firstPlayer' and 'secondPlayer' are
 * the best in the tournament. they can win agsainst any other player beofre
 * they compete against each other. if any two other players compete against
 * each other, either of them might win, and thus you may choose the outcome of
 * this round.
 */

int *earliestAndLatest(int n, int firstPlayer, int secondPlayer,
                       int *returnSize) {
  *returnSize = 2;
  int *ans = (int *)malloc(*returnSize * sizeof(int));
  int first = firstPlayer, second = secondPlayer;
  if (first + second == n + 1) {
    ans[0] = ans[1] = 1;
    return ans;
  }
  if (first + second > n + 1) {
    int tmp = first;
    first = n + 1 - second;
    second = n + 1 - tmp;
  }
  int pre = 1;
  int pos = (32 - __builtin_clz(n - 1) < n + 1 - second)
                ? 32 - __builtin_clz(n - 1)
                : n + 1 - second;
  if (first + second == n) {
    if (!(first % 2))
      pre = (first + 2 < second) ? 2 : 1 + __builtin_ctz(first);
  } else if (first + 1 == second) {
    pre = 32 - __builtin_clz((n - 1) / (first + second - 1));
    pre += __builtin_ctz((n - 1) >> pre);
  } else if (first + second <= (n + 1) / 2)
    pre = 32 - __builtin_clz((n - 1) / (first + second - 1));
  ans[0] = pre + 1;
  ans[1] = pos;
  return ans;
}

int main() {
  int rs1, *eal1 = earliestAndLatest(11, 2, 4, &rs1);
  int rs2, *eal2 = earliestAndLatest(5, 1, 5, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", eal1[i]); // expect: 3 4
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", eal2[i]); // expect: 1 1
  printf("\n");
  free(eal1), free(eal2);
}
