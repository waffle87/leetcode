// 435. Non-overlapping Intervals
#include "leetcode.h"

/*
 * given an array of intervals 'intervals' where 'intervals[i] = [start[i],
 * end[i]]', return the minimum number of intervals you need to remove to make
 * the rest of the intervals non-overlapping
 */

class Solution {
  static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

public:
  int eraseOverlapIntervals(vvd & intervals) {
    int ans = -1;
    if (!intervals.size())
      return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    vector<int> prev = intervals[0];
    for (vector<int> i : intervals) {
      if (prev[1] > i[0])
        ans++;
      else
        prev = i;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd i1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vvd i2 = {{1, 2}, {1, 2}, {1, 2}};
  vvd i3 = {{1, 2}, {2, 3}};
  printf("%d\n", obj.eraseOverlapIntervals(i1)); // expect: 1
  printf("%d\n", obj.eraseOverlapIntervals(i2)); // expect: 2
  printf("%d\n", obj.eraseOverlapIntervals(i3)); // expect: 0
}
