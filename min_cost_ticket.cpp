// 983. Minimum Cost For Tickets
#include "leetcode.h"

/*
 * you have planned some train traveling one year in advance. the days of the
 * year in which you will travel are given as an integer array 'days'. each day
 * is an integer 1 - 365. train tickets are sold in three different ways: 1 day
 * pass sold for 'costs[0]' dollars 7 day pass sold for 'costs[1]' dollars 30
 * day pass sold for 'costs[2]' dollars the passes allow that many days of
 * consecutive travel. return mininum number of dollars you need to travel every
 * day in the given list of days.
 */

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    unordered_map<int, int> tickets;
    tickets[1] = costs[0];
    tickets[7] = costs[1];
    tickets[30] = costs[2];
    vector<int> dp(366, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < 366; i++) {
      if (find(days.begin(), days.end(), i) == days.end()) {
        dp[i] = dp[i - 1];
        continue;
      }
      for (auto t : tickets)
        dp[i] = min(dp[i], dp[max(0, i - t.first)] + t.second);
    }
    return dp[365];
  }
};

int main() {
  Solution obj;
  vector<int> d1 = {1, 4, 6, 7, 8, 20},
              d2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  vector<int> c1 = {2, 7, 15};
  printf("%d\n", obj.mincostTickets(d1, c1)); // expect: 11
  printf("%d\n", obj.mincostTickets(d2, c1)); // expect: 17
}
