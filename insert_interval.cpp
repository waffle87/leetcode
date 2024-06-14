#include "leetcode.h"

class Solution {
public:
  vvd(int) insert(vvd(int) & intervals, vector<int> &newInterval) {
    const int START = 0, END = 1;
    int s = newInterval[START], e = newInterval[END];
    vvd(int) left, right;
    for (auto &curr : intervals) {
      if (curr[END] < s)
        left.push_back(curr);
      else if (curr[START] > e)
        right.push_back(curr);
      else {
        s = min(s, curr[START]);
        e = max(e, curr[END]);
      }
    }
    vvd(int) ans;
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back({s, e});
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) intervals1 = {{1, 3}, {6, 9}},
           intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval1 = {2, 5}, newInterval2 = {4, 8};
  for (auto i : obj.insert(intervals1, newInterval1))
    for (auto j : i)
      cout << j << ' '; // expect: [[1,5],[6,9]]
  cout << endl;
  for (auto i : obj.insert(intervals2, newInterval2))
    for (auto j : i)
      cout << j << ' '; // expect: [[1,2],[3,10],[12,16]]
}
