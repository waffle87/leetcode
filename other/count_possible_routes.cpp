// 1575. Count All Possible Routes
#include "leetcode.h"

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

class Solution {
public:
  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
    int n = locations.size(), mod = 1e9 + 7, ans = 0;
    vvd dp(n, vector<int>(fuel + 1));
    dp[start][fuel] = 1;
    for (int f = fuel; f >= 0; f--)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
          int diff = abs(locations[i] - locations[j]);
          if (i != j && f >= diff)
            dp[j][f - diff] = (dp[j][f - diff] % mod + dp[i][f] % mod) % mod;
        }
    for (int i = 0; i <= fuel; i++)
      ans = (ans % mod + dp[finish][i] % mod) % mod;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> l1 = {2, 3, 6, 8, 4}, l2 = {4, 3, 1};
  printf("%d\n", obj.countRoutes(l1, 1, 3, 5)); // expect: 4
  printf("%d\n", obj.countRoutes(l2, 1, 0, 6)); // expect: 5
}
