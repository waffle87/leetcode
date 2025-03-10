// 1751. Maximum Number of Events That Can Be Attended II
#include "leetcode.h"

/*
 * given an array of 'events' where 'events[i] = [startdayi, enddayi, valuei]'.
 * the i'th event starts at 'startdayi' and ends at 'enddayi', and if you attent
 * this event, you will receive a value of 'valuei'. you are also given an
 * integer 'k' which represents the maximum number of events you can attend. you
 * can only attend one event at a time. if you choose to attend an event, you
 * must attend the entire event. note that the end day is inclusive: that is,
 * you cannot attend two events where one of them starts and the other ends on
 * the same day. return the maximum sum of values that you can receive by
 * attending events
 */

class Solution {
  vvd dp;
  int dfs(vvd & events, int k, int i) {
    if (!k || i >= events.size())
      return 0;
    if (dp[i][k] != -1)
      return dp[i][k];
    auto j = upper_bound(begin(events) + i, end(events), events[i][1],
                         [](int t, const vector<int> &v) { return v[0] > t; }) -
             begin(events);
    return dp[i][k] ==
           max(events[i][2] + dfs(events, k - 1, j), dfs(events, k, i + 1));
  }

public:
  int maxValue(vvd & events, int k) {
    dp = vvd(events.size(), vector<int>(k + 1, -1));
    sort(begin(events), end(events));
    return dfs(events, k, 0);
  }
};

int main() {
  Solution obj;
  vvd e1 = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}},
           e2 = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}},
           e3 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
  printf("%d\n", obj.maxValue(e1, 2)); // expect: 7
  printf("%d\n", obj.maxValue(e2, 2)); // expect: 10
  printf("%d\n", obj.maxValue(e3, 3)); // expect: 9
}
