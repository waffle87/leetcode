// 1550. Three Consecutive Odds
#include "leetcode.h"

/*
 * given an integer array 'arr', return true if there are three consecutive odd
 * numbers in the array. otherwise, return false
 */

bool threeConsecutiveOdds(int *arr, int arrSize) {
  int odds = 0;
  for (int i = 0; i < arrSize && odds < 3; ++i)
    odds = arr[i] % 2 ? odds + 1 : 0;
  return odds == 3;
}

int main() {
  int a1[] = {2, 6, 4, 1}, a2[] = {1, 2, 34, 3, 4, 5, 7, 23, 12};
  printf("%d\n", threeConsecutiveOdds(a1, ARRAY_SIZE(a1))); // expect: 0
  printf("%d\n", threeConsecutiveOdds(a2, ARRAY_SIZE(a2))); // expect: 1
}
