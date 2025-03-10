// 1406. Stone Game III
#include <stdio.h>

/*
 * alice and bob continue their games with piles of stones. there are several
 * stones arranged in a row, and each stone has an associated value which is an
 * integer given in the array 'stone_value'. alice and bob take turns with alice
 * starting first. on each player's turn, that player can take 1,2, or 3 stones
 * from the first remaining stones in row. the score of each player is the sum
 * of the values of the stones taken the score of each player is initially zero.
 * the objective of the game is to end with the highest score, and the winner is
 * the player with the highest score and there could be a tie. the game
 * continues until all the stones have been taken. assume alice and bob play
 * optimally. return "Alice", "Bob", or "Tie" accordingly
 */

int min(int a, int b, int c) {
  if (a <= b && a <= c)
    return a;
  if (b <= a && b <= c)
    return b;
  return c;
}

char *stoneGameIII(int *stone_value, int stone_value_size) {
  int dp[50005] = {0}, sum = 0;
  for (int i = stone_value_size - 1; i >= 0; --i) {
    sum += stone_value[i];
    dp[i] = sum - min(dp[i + 1], dp[i + 2], dp[i + 3]);
  }
  if (dp[0] * 2 == sum)
    return "Tie";
  if (dp[0] * 2 > sum)
    return "Alice";
  else
    return "Bob";
}

int main() {
  int sv1[] = {1, 2, 3, 7};
  int sv2[] = {1, 2, 3, -9};
  int sv3[] = {1, 2, 3, 6};
  printf("%s\n", stoneGameIII(sv1, 4)); // expect: Bob
  printf("%s\n", stoneGameIII(sv2, 4)); // expect: Alice
  printf("%s\n", stoneGameIII(sv3, 4)); // expect: Tie
}
