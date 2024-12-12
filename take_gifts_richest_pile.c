// 2558. Take Gifts From the Richest Pile
#include "leetcode.h"

/*
 * you are given an integer array 'gifts' denoting the number of gifts in
 * various piles. every second, you do the following: choose the pile with the
 * maximum number of gifts, if there is more than one pile with the maximum
 * number of gifts, choose any. leave behind the floor of the square root of the
 * number of gifts in the pile. take the rest of the gifts. return the number of
 * gifts remaining after 'k' seconds.
 */

long long pickGifts(int *gifts, int giftsSize, int k) {
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    int max = 0, x;
    for (int j = 0; j < giftsSize; j++)
      if (max < gifts[j]) {
        max = gifts[j];
        x = j;
      }
    gifts[x] = sqrt(gifts[x]);
  }
  for (int i = 0; i < giftsSize; i++)
    ans += gifts[i];
  return ans;
}

int main() {
  int g1[] = {25, 64, 9, 4, 100}, g2[] = {1, 1, 1, 1};
  printf("%lld\n", pickGifts(g1, ARRAY_SIZE(g1), 4)); // expect: 29
  printf("%lld\n", pickGifts(g2, ARRAY_SIZE(g2), 4)); // expect: 4
}
