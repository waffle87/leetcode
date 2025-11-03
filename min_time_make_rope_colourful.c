// 1578. Minimum Time to Make Rope Colorful
#include "leetcode.h"

/*
 * alice has 'n' balloons arranged on a rope. you are given a 0-indexed string
 * 'colours' where 'colours[i]' is the colour of the i'th balloon. alice wants
 * the rope to be colourful. she does not want two consecutive balloons to be
 * the of the same colour, so she asks bob for help. bob can remove some
 * balloons from the rope to make it colourful. you are given a 0-indexed
 * integer array 'neededTime' where 'neededTime[i]' is the time (in seconds)
 * that bob needs to remove the i'th balloon from the rope. return the minimum
 * time bob needs to make the rop colourful.
 */

int minCost(char *colors, int *neededTime, int neededTimeSize) {
  int ans = 0, n = strlen(colors);
  for (int i = 1; i < n; i++) {
    int max = 0;
    while (i < n && colors[i] == colors[i - 1]) {
      ans += neededTime[i - 1];
      max = fmax(max, neededTime[i - 1]);
      ++i;
    }
    ans += neededTime[i - 1];
    max = fmax(max, neededTime[i - 1]);
    if (max != 0)
      ans -= max;
  }
  return ans;
}

int main() {
  char *c1 = "abaac", *c2 = "abc", *c3 = "aabaa";
  int nt1[] = {1, 2, 3, 4, 5}, nt2[] = {1, 2, 3}, nt3[] = {1, 2, 3, 4, 1};
  printf("%d\n", minCost(c1, nt1, ARRAY_SIZE(nt1))); // expect: 3
  printf("%d\n", minCost(c2, nt2, ARRAY_SIZE(nt2))); // expect: 0
  printf("%d\n", minCost(c3, nt3, ARRAY_SIZE(nt3))); // expect: 2
}
