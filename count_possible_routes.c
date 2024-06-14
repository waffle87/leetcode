// 1575. Count All Possible Routes
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of disticnt positive integers locations where 'locations[i]'
 * represents the position of city 'i'. you are lso given integers 'start,
 * finish, fuel' representing the starting city, ending city, and the initial
 * amount of fuel you have, respectively. at each step if you are in city 'i',
 * you can pick any city 'j' such that 'j != i' and '0 <= j < locations.length'
 * and move to city 'j'. moving city 'i' to 'j' reduces the amount of fuel you
 * have by |locations[i] - locations[j]|. Please notice that |x| denotes the
 * absolute value of x. notice that fuel cannot become negative at any point in
 * time. and that are allowed to visit any city more than once (including
 * 'start' and 'finish'). return the count of all possible routes from 'start'
 * to 'finish'. since the answer may be large, return it modulo 10^9+7.
 */

#define MOD 1000000007

int solve(int *locations, int locations_size, int start, int finish, int fuel,
          int **memo) {
  if (fuel < 0)
    return 0;
  if (memo[start][fuel] != -1)
    return memo[start][fuel];
  int ans = start == finish ? 1 : 0;
  for (int i = 0; i < locations_size; i++)
    if (start != i)
      ans = (ans + solve(locations, locations_size, i, finish,
                         fuel - abs(locations[i] - locations[start]), memo)) %
            MOD;
  return memo[start][fuel] = ans;
}

int countRoutes(int *locations, int locations_size, int start, int finish,
                int fuel) {
  int ans = 0;
  int **memo = (int **)malloc(sizeof(int *) * locations_size);
  for (int i = 0; i < locations_size; i++) {
    memo[i] = (int *)malloc(sizeof(int) * (fuel + 1));
    for (int j = 0; j <= fuel; j++)
      memo[i][j] = -1;
  }
  return solve(locations, locations_size, start, finish, fuel, memo);
}

int main() {
  int l1[] = {2, 3, 6, 8, 4}, l2[] = {4, 3, 1};
  printf("%d\n", countRoutes(l1, 5, 1, 3, 5)); // expect: 4
  printf("%d\n", countRoutes(l2, 3, 1, 0, 6)); // expect: 5
}
