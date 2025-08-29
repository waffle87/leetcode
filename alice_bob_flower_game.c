// 3021. Alice and Bob Playing Flower Game
#include "leetcode.h"

/*
 * alice and bob are playing a turn-based game on a field with two lanes of
 * flowers bet=een them. there are 'x' flowers in the first lane between alice
 * and bob, and 'y' flowers in the second lane between them. return the number
 * of possible pairs '(x, y)' that satisyf the conditions mentioned in the
 * statement.
 */

long long flowerGame(int n, int m) { return 1LL * n * m / 2; }

int main() {
  printf("%lld\n", flowerGame(3, 2)); // expect: 3
  printf("%lld\n", flowerGame(1, 1)); // expect: 0
}
