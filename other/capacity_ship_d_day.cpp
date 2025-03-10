// 1011. Capacity To Ship Packages Within D Days
#include "leetcode.h"

/*
 * a conveyor belt has packages that must be shipped from one port to another
 * within 'days' days. the i'th package on the conveyor belt has a weight of
 * 'weights[i]'. each day, the ship is loaded with packages on the conveyor belt
 * (in order given by 'weights'). we may not load more weight than the maximum
 * capacity of the ship. return the least weight capacity of the ship that will
 * result in all the packages on the conveyor belt being shipped within 'days'
 * days.
 */

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    auto r = accumulate(begin(weights), end(weights), 0);
    auto l = max(r / days, *max_element(begin(weights), end(weights)));
    while (l < r) {
      auto m = (l + r) / 2;
      if (countDays(weights, m) <= days)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

private:
  int countDays(vector<int> &weights, int tot_cap, int cur_cap = 0,
                int res = 1) {
    for (auto w : weights) {
      cur_cap += w;
      if (cur_cap > tot_cap) {
        ++res;
        cur_cap = w;
      }
    }
    return res;
  }
};

int main() {
  Solution obj;
  vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
              weights2 = {3, 2, 2, 4, 1, 4}, weights3 = {1, 2, 3, 1, 1};
  cout << obj.shipWithinDays(weights1, 5) << endl; // expect: 15
  cout << obj.shipWithinDays(weights2, 3) << endl; // expect: 6
  cout << obj.shipWithinDays(weights3, 4) << endl; // expect: 3
}
