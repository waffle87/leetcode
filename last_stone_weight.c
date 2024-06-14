// 1046. Last Stone Weight
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * you are given an array of integers 'stones' where 'stones[i]' is the weight
 * of the i'th stone. on each turn, we choose the heaviest two stones and smash
 * them together suppose the heaviest two stones have weights x and y with x <=
 * y. the result of the smash is if x == y, both stones are destroyed. and if x
 * != y, the stone of weight x is destroyed, and the stone of weight y has new
 * weight y - x. at the end of the game there is at most one stone left. return
 * the weight of the remaining stone or zero.
 */

int lastStoneWeight(int *stones, int stones_size) {
  int h[1001] = {}, mx = INT_MIN;
  for (int i = 0; i < stones_size; ++i) {
    h[stones[i]]++;
    mx = fmax(mx, stones[i]);
  }
  int w = mx;
  h[w]--;
  while (w) {
    if (h[w]) {
      if (mx) {
        int d = mx - w;
        h[d]++;
        h[w]--;
        w = fmax(w, d);
        mx = 0;
      } else {
        h[w]--;
        mx = w;
      }
    } else
      --w;
  }
  return mx;
}

int main() {
  int s1[] = {2, 7, 4, 1, 8, 1}, s2[] = {1};
  printf("%d\n", lastStoneWeight(s1, 6)); // expect: 1
  printf("%d\n", lastStoneWeight(s2, 1)); // expect: 1
}
