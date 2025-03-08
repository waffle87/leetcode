// 2379. Minimum Recolors to Get K Consecutive Black Blocks
#include "leetcode.h"

/*
 * you are given a 0-indexed string 'blocks' of length 'n' where 'blocks[i]' is
 * either 'W' or 'B', representing the colour of the i'th block. the characters
 * 'W' and 'B' denote the colours white and black, respectively. you are also
 * given an integer 'k', which is the desired number of consecutive black
 * blocks. in one operation, you can recolour a white block such that it becomes
 * a black block. return the minimum number of operations needed such that there
 * is at least one occurence of 'k' consecutive black blocks.
 */

int minimumRecolors(char *blocks, int k) {
  int n = strlen(blocks), min = INT_MAX, flips = 0, cnt = 0, i = 0;
  for (int j = 0; j < n; ++j) {
    if (blocks[j] == 'W') {
      flips++;
      cnt++;
    } else if (blocks[j] == 'B')
      cnt++;
    if (cnt == k) {
      min = fmin(min, flips);
      if (blocks[i] == 'W') {
        flips--;
        cnt--;
      } else
        cnt--;
      i++;
    }
  }
  return min;
}

int main() {
  char *b1 = "WBBWWBBWBW", *b2 = "WBWBBBW";
  printf("%d\n", minimumRecolors(b1, 7)); // expect: 3
  printf("%d\n", minimumRecolors(b2, 2)); // expect: 0
}
