// 815. Bus Routes
#include "leetcode.h"

/*
 * you are given an array 'routes' representing bus routes where 'routes[i]' is
 * a bus route that the i'th bus repeats forever. you will start at the bus stop
 * 'source' you are not on any bus initially and you want to go to the bus stop
 * 'target'. you can only travel between bus stops by buses only. return the
 * least number of buses you must take to travel from 'source' to 'target'.
 * return -1 if it is not possible.
 */

int numBusesToDestination(int **routes, int routes_size, int *routes_col_size,
                          int source, int target) {
  if (source == target)
    return 0;
  bool vis[routes_size], flag = false;
  int hash[100001], size = routes_size;
  memset(vis, false, sizeof(vis));
  memset(hash, -1, sizeof(hash));
  for (int i = 0; i < routes_size; i++)
    for (int j = 0; j < routes_col_size[i]; i++)
      if (routes[i][j] == source) {
        vis[i] = true;
        size--;
        for (j = 0; j < routes_col_size[i]; j++)
          hash[routes[i][j]] = 1;
        break;
      }
  if (size == routes_size)
    return -1;
  if (hash[target] != -1)
    return hash[target];
  while (size) {
    // flag = false;
    for (int i = 0; i < routes_size; i++) {
      if (vis[i])
        continue;
      int min = INT_MAX;
      for (int j = 0; j < routes_col_size[i]; j++)
        if (hash[routes[i][j]] != -1)
          min = fmin(min, hash[routes[i][j]]);
      if (min != INT_MAX) {
        flag = true;
        vis[i] = 1;
        size--;
        for (int j = 0; j < routes_col_size[i]; j++)
          if (hash[routes[i][j]] == -1)
            hash[routes[i][j]] = min + 1;
        if (hash[target] != -1 || size <= 0)
          break;
      }
    }
    if (hash[target] != -1 || size <= 0 || !flag)
      break;
  }
  return hash[target];
}
