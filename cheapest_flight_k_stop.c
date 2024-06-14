// 787. Cheapest Flights Within K Stops
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF (INT_MAX >> 2)

/*
 * there are 'n' cities connected by some number of flights. you are given array
 * 'flights' where 'flight[i] = [fromi, toi, pricei]' indicates that there is a
 * flight from city 'fromi' to city 'toi' with cost 'pricei'.
 * you are also given three integers 'src, dst, & k'. return the cheapest price
 * from 'src' to 'dst' with at most 'k' stops. if there is no such route, -1
 */

int findCheapestPrice(int n, int **flights, int flightsSize,
                      int *flightsColSize, int src, int dst, int k) {
  int *dist = malloc(n * sizeof(int)), *tmp = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    tmp[i] = INF;
  }
  dist[src] = 0;
  tmp[src] = 0;
  while (k >= 0) {
    for (int i = 0; i < flightsSize; i++) {
      int from = flights[i][0], to = flights[i][1], price = flights[i][2];
      if (tmp[to] > dist[from] + price)
        tmp[to] = dist[from] + price;
    }
    memcpy(&dist[0], &tmp[0], n * sizeof(int));
    k--;
  }
  int ans = dist[dst];
  if (ans == INF)
    return -1;
  return ans;
}
