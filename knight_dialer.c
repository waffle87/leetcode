// 935. Knight Dialer
#include "leetcode.h"

/*
 * the chess knight has a unique movement, it may move two squares vertically
 * and one square horizontally, or two squares horizontally andone square
 * vertically with both forming the shape of an L. the possible movements of
 * chess knights ares shown in below diagram. given an integer 'n', return how
 * many distinct phone number of length 'n' we can dial. you are allowed to
 * place the knight on any numeric cell initially and then you should perform 'n
 * - 1' jumps to dial a number of length 'n'. all jumps should be valid jumps.
 * as the answer may be very large, return answer modulo 10^9 + 7
 */

int knightDialer(int n) {
  long int new_jump[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  long int old_jump[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  long long int numbers = 0;
  int row0[] = {2, 4, 6};
  int row1[] = {2, 6, 8};
  int row2[] = {2, 7, 9};
  int row3[] = {2, 8, 4};
  int row4[] = {3, 3, 9, 0};
  int row5[] = {0};
  int row6[] = {3, 7, 0, 1};
  int row7[] = {2, 2, 6};
  int row8[] = {2, 1, 3};
  int row9[] = {2, 4, 2};
  int **dial = malloc(10 * sizeof(int *));
  dial[0] = row0;
  dial[1] = row1;
  dial[2] = row2;
  dial[3] = row3;
  dial[4] = row4;
  dial[5] = row5;
  dial[6] = row6;
  dial[7] = row7;
  dial[8] = row8;
  dial[9] = row9;
  if (n == 1)
    return 10;
  for (int i = 1; i < n; i++) {
    numbers = 0;
    for (int j = 0; j < 10; j++)
      for (int k = 1; k < dial[j][0] + 1; k++) {
        if (j == 5)
          continue;
        new_jump[dial[j][k]] += old_jump[j];
        new_jump[dial[j][k]] %= 1000000007LL;
      }
    memcpy(old_jump, new_jump, sizeof(long) * 10);
    for (int j = 0; j < 10; j++) {
      numbers += new_jump[j];
      new_jump[j] = 0;
    }
  }
  free(dial);
  return numbers % 1000000007LL;
}

int main() {
  printf("%d\n", knightDialer(1));    // expect: 10
  printf("%d\n", knightDialer(2));    // expect: 20
  printf("%d\n", knightDialer(3131)); // expect: 136006598
}
