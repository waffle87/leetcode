// 806. Number of Lines To Write String
#include "leetcode.h"

/*
 * given a string 's' of lowercase english letters and an array 'widths'
 * denoting how many pixels wide each lowercase english letter is. specifically,
 * 'widths[0]' is the width of 'a', 'widths[1]' is the width of 'b', and so on.
 * you are trying to write 's' across several lines, where each line is no
 * longer than 100 pixels. starting at the beginning of 's', write as many
 * letters on the first line such that the total width does not exceed 100
 * pixels. then from where you topped in 's', continue writing as many letters
 * as you can on the second line. continue this process until you have written
 * all of 's'.
 */

int *numberOfLines(int *widths, int widthsSize, char *s, int *returnSize) {
  int *ans = malloc(2 * sizeof(int));
  *returnSize = 2;
  int n = strlen(s), pixels = 0, line = 0;
  for (int i = 0; i < n; i++) {
    pixels += widths[s[i] - 'a'];
    if (pixels > 100) {
      line++;
      pixels = widths[s[i] - 'a'];
    }
  }
  ans[0] = line + 1;
  ans[1] = pixels;
  return ans;
}

int main() {
  int w1[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
              10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
      w2[] = {4,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
              10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  char *s1 = "abcdefghijklmnopqrstuvwxyz", *s2 = "bbbcccdddaaa";
  int rs1 = 0, rs2 = 0;
  int *nol1 = numberOfLines(w1, ARRAY_SIZE(w1), s1, &rs1);
  int *nol2 = numberOfLines(w2, ARRAY_SIZE(w2), s2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", nol1[i]); // expect: 3 60
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", nol2[i]); // expect: 2 4
  printf("\n");
  free(nol1), free(nol2);
}
