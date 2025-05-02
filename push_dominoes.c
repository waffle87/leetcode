// 838. Push Dominoes
#include "leetcode.h"

/*
 * there are 'n' dominoes in a line, and we place each domino vertically
 * upright. in the beginning, we simultaneously push some of the dominoes either
 * to the left or to the right. after each second, each domino that is falling
 * to the left pushes the adjacent domino on the left. similarly, the dominoes
 * falling to the right push their adjacent dominoes standing on the right. when
 * a vertical domino has dominoes falling on it from both sides, it stays still
 * due to the balance of the forces. for the purpose of this question, we will
 * consider that a falling domino expends no additional force to a falling or
 * already fallen domino.
 */

char *pushDominoes(char *dominoes) {
  int n = strlen(dominoes), right = -1;
  for (int i = 0; i < n; ++i) {
    if (dominoes[i] == 'L') {
      if (right == -1) {
        for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j)
          dominoes[j] = 'L';
      } else {
        for (int j = right + 1, k = i - 1; j < k; ++j, --k) {
          dominoes[j] = 'R';
          dominoes[k] = 'L';
        }
        right = -1;
      }
    } else if (dominoes[i] == 'R') {
      if (right != -1)
        for (int j = right + 1; j < i; ++j)
          dominoes[j] = 'R';
      right = i;
    }
  }
  if (right != -1)
    for (int i = right + 1; i < n; ++i)
      dominoes[i] = 'R';
  return dominoes;
}

int main() {
  char *d1 = "RR.L", *d2 = ".L.R...LR..L..";
  printf("%s\n", pushDominoes(d1)); // expect: RR.L
  printf("%s\n", pushDominoes(d2)); // expect: .L.R...LR..L..
}
