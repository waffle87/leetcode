// 401. Binary Watch
#include "leetcode.h"

/*
 * a binary watch has 4 leds on the top to represent the hours (0 - 11) and 6
 * leds on the bottom to represent the minutes (0 - 59). each led represents a 0
 * or one, with the least siginificant bit on the right. given an integer
 * 'turnedOn' which represents the number of leds that are currently on, return
 * all possible times the watch could represent. you may return the answer in
 * any order.
 */

char **readBinaryWatch(int turnedOn, int *returnSize) {
  char **ans = (char **)malloc(190 * sizeof(char *));
  *returnSize = 0;
  for (int h = 0; h < 12; h++)
    for (int m = 0; m < 60; m++) {
      int total = __builtin_popcount(h) + __builtin_popcount(m);
      if (total == turnedOn) {
        ans[*returnSize] = (char *)malloc(8 * sizeof(char));
        snprintf(ans[*returnSize], 8, "%d:%02d", h, m);
        (*returnSize)++;
      }
    }
  return ans;
}

int main() {
  int rs1, rs2;
  char **rbw1 = readBinaryWatch(1, &rs1);
  char **rbw2 = readBinaryWatch(9, &rs2);
  for (int i = 0; i < rs1; i++)
    printf(
        "%s ",
        rbw1[i]); // expect: 0:01,0:02,0:04,0:08,0:16,0:32,1:00,2:00,4:00,8:00
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", rbw2[i]); // expect: null
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rbw1[i]);
  free(rbw1);
  for (int i = 0; i < rs2; i++)
    free(rbw2[i]);
  free(rbw2);
}
