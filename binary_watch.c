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
  char **ans = (char **)malloc(12 * 60 * sizeof(char *));
  *returnSize = 0;
  for (int i = 0; i < 1024; ++i) {
    int h = i >> 6, m = i & 63;
    if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
      char *tmp = (char *)malloc(6 * sizeof(char));
      sprintf(tmp, "%d:%02d", h, m);
      ans[(*returnSize)++] = tmp;
    }
  }
  return ans;
}

int main() {
  int rs1, rs2;
  char **rbw1 = readBinaryWatch(1, &rs1);
  char **rbw2 = readBinaryWatch(9, &rs2);
  char *r1[] = {"0:01", "0:02", "0:04", "0:08", "0:16",
                "0:32", "1:00", "2:00", "4:00", "8:00"};
  char *r2[] = {};
  for (int i = 0; i < rs1; i++) {
    printf("%s ", rbw1[i]);
    assert(!strcmp(r1[i], rbw1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", rbw2[i]);
    assert(!strcmp(r2[i], rbw2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rbw1[i]);
  free(rbw1);
  for (int i = 0; i < rs2; i++)
    free(rbw2[i]);
  free(rbw2);
}
