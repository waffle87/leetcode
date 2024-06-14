// 2477. Minimum Fuel Cost to Report to the Capital
#include <stdio.h>
#include <stdlib.h>

/*
 * there is a tree (ie. a connected, undirected graph with no cycles) structure
 * country network consisting of 'n' cities numbered from 0 to 'n - 1' and
 * exactly 'n - 1' roads the capital city is city 0. given a 2d integer array
 * 'roads' where 'roads[i] = [ai, bi]' denotes that there exists a bidirectional
 * road connecting cities ai & bi. there is a meeting for the representitive of
 * each city. the meeting is in the capital city. there is a car in each city.
 * given integer seats that indicates the number of seats in each car. a
 * representitive can use the car in their city to travel or change the car and
 * ride with another representitive. the cost of traveling between two cities is
 * 1 liter of fuel. return minimum number of liters of fuel needed to reach
 * capital city.
 */

void dfs(int seats, int from, int now, long long *ans, int **can_go, int *cnt,
         int *ppl) {
  if (cnt[now] == 1) {
    *ppl = 1;
    return;
  }
  int next = 0, next_city = 0;
  for (int i = 0; i < cnt[now]; i++) {
    if (can_go[now][i] == from) {
      i++;
      while (i < cnt[now]) {
        dfs(seats, now, can_go[now][i], ans, can_go, cnt, &next_city);
        *ans += next_city / seats;
        if (next_city % seats != 0)
          *ans += 1;
        next += next_city;
        i++;
      }
    } else {
      dfs(seats, now, can_go[now][i], ans, can_go, cnt, &next_city);
      *ans += next_city / seats;
      if (next_city % seats != 0)
        *ans += 1;
      next += next_city;
    }
  }
  *ppl = next + 1;
  return;
}

long long minimumFuelCost(int **roads, int roadsSize, int *roadsColSize,
                          int seats) {
  int **can_go = malloc(sizeof(int *) * (roadsSize + 1));
  for (int i = 0; i <= roadsSize; i++)
    can_go[i] = malloc(sizeof(int) * 20);
  int *cnt = calloc((roadsSize + 1), sizeof(int));
  for (int i = 0; i < roadsSize; i++) {
    can_go[roads[i][0]][cnt[roads[i][0]]] = roads[i][1];
    can_go[roads[i][1]][cnt[roads[i][1]]] = roads[i][0];
    cnt[roads[i][0]]++;
    cnt[roads[i][1]]++;
  }
  long long ans = 0;
  int ppl = 0;
  for (int i = 0; i < cnt[0]; i++) {
    dfs(seats, 0, can_go[0][i], &ans, can_go, cnt, &ppl);
    ans += (ppl / seats);
    if (ppl % seats != 0)
      ans += 1;
  }
  free(cnt);
  for (int i = 0; i <= roadsSize; i++)
    free(can_go[i]);
  free(can_go);
  return ans;
}

int main() {
  int roads1[3][2] = {{0, 1}, {0, 2}, {0, 3}};
  int rs1 = 3;
  int rcs1[] = {3};
  int seats1 = 5;
  printf("%lld\n", minimumFuelCost(roads1, rs1, rcs1, seats1));
}
