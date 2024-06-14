// 875. Koko Eating Bananas
#include <stdio.h>

// return minimum integer 'k' such that koko can eat all bananas within 'h'
// hours

int minEatingSpeed(int *piles, int piles_size, int h) {
  int l = 1, r = 1000000000;
  while (l < r) {
    int m = (l + r) / 2, total = 0;
    for (int i = 0; i < piles_size; i++)
      total += (piles[i] + m - 1) / m;
    if (total > h)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int main() {
  int p1[] = {3, 6, 7, 11}, p2_3[] = {30, 11, 23, 4, 20};
  printf("%d\n", minEatingSpeed(p1, sizeof(p1) / sizeof(p1[0]), 8)); // expect:
                                                                     // 4
  printf("%d\n",
         minEatingSpeed(p2_3, sizeof(p2_3) / sizeof(p2_3[0]), 5)); // expect: 30
  printf("%d\n",
         minEatingSpeed(p2_3, sizeof(p2_3) / sizeof(p2_3[0]), 6)); // expect: 23
}
