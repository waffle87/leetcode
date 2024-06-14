// 1578. Minimum Time to Make Rope Colorful
#include "leetcode.h"

/*
 * alice has 'n' balloons arranged on a rope. you are given a 0-indexed string
 * 'colours' where 'colours[i]' is the colour of the i'th balloon. alice wants
 * the rope to be colourful. she does not want two consecutive balloons to be
 * the of the same colour, so she asks bob for help. bob can remove some
 * balloons from the rope to make it colourful. you are given a 0-indexed
 * integer array 'needed_time' where 'needed_time[i]' is the time (in seconds)
 * that bob needs to remove the i'th balloon from the rope. return the minimum
 * time bob needs to make the rop colourful.
 */

int calc_cost(int idx, int continue_len, int *needed_time) {
  int max = needed_time[idx], sum = 0;
  for (int i = idx; i < idx + continue_len; i++) {
    sum += needed_time[i];
    if (i + 1 < idx + continue_len)
      if (needed_time[i + 1] > max)
        max = needed_time[i + 1];
  }
  return sum - max;
}

int minCost(char *colours, int *needed_time, int needed_time_size) {
  int continue_len = 1, idx = 0, min_cost = 0, cost = 0;
  for (int i = 0; i < needed_time_size; i++) {
    if (colours[i] == colours[i + 1]) {
      continue_len++;
      idx = i - continue_len - 2;
    } else {
      if (continue_len != 1) {
        cost = calc_cost(idx, continue_len, needed_time);
        min_cost += cost;
        cost = 0;
      }
      continue_len = 1;
    }
  }
  return min_cost;
}

int main() {
  char *c1 = "abaac", *c2 = "abc", *c3 = "aabaa";
  int nt1[] = {1, 2, 3, 4, 5}, nt2[] = {1, 2, 3}, nt3[] = {1, 2, 3, 4, 1};
  printf("%d\n", minCost(c1, nt1, ARRAY_SIZE(nt1))); // expect: 3
  printf("%d\n", minCost(c2, nt2, ARRAY_SIZE(nt2))); // expect: 0
  printf("%d\n", minCost(c3, nt3, ARRAY_SIZE(nt3))); // expect: 2
}
