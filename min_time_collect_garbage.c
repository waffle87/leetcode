// 2391. Minimum Amount of Time to Collect Garbage
#include "leetcode.h"

/*
 * given a 0-indexed array of strings 'garbage' where 'garbage[i]' represents
 * the assortment of garbage at the i'th house. 'garbage[i]' consists of only
 * characters 'M, P, and G' representing one unit of metal, paper, and glass
 * garbage respectively. picking up one unitof any type of garbage takes 1
 * minute. you are also given a 0-indexed integer array 'travel' where
 * 'travel[i]' is the number of minutes needed to go from house 'i' to house 'i
 * + 1'. there are three garbage trucks in the city, each responsible for
 * picking up one type of garbage. each garbage truck starts at house 0 and must
 * visit each house in order, however they do not need to visit every house.
 * only one garbage truck may be used at any given moment. while one truck is
 * driving or picking up garbage, the other two trucks cannot do anything.
 * return the minimum number of minutes needed to pick up all the garbage.
 */

int garbageCollection(char **garbage, int garbage_size, int *travel,
                      int travel_size) {
  int total_bag = 0, len, ans = 0;
  bool m = false, p = false, g = false;
  for (int i = garbage_size - 1; i >= 0; i--) {
    len = strlen(garbage[i]);
    total_bag += len;
    if (!m || !p || !g) {
      for (int j = 0; j < len; j++) {
        if (!m && garbage[i][j] == 'M') {
          m = 1;
          for (int k = i - 1; k >= 0; k--)
            ans += travel[k];
        } else if (!p && garbage[i][j] == 'P') {
          p = 1;
          for (int k = i - 1; k >= 0; k--)
            ans += travel[k];
        } else if (!g && garbage[i][j] == 'G') {
          g = 1;
          for (int k = i - 1; k >= 0; k--)
            ans += travel[k];
        }
      }
    }
  }
  ans += total_bag;
  return ans;
}
