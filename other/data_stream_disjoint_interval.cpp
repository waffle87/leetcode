// 352. Data Stream as Disjoint Intervals
#include "leetcode.h"

/*
 * given a data stream input of non-negative integers 'a1, a2, ..., an',
 * summarize the numbers seen so far as a list of disjoint intervals. implement
 * 'SummaryRanges': SummaryRanges() initialises the object with an empty stream
 * void addNum(int value) adds the integer 'value' to the stream
 * int[][] getIntervals() returns a summary of the integers in the stream
 * currently as a list of disjoint intervals '[starti, endi]'. sort answer by
 * 'starti'
 */

class SummaryRanges {
public:
  map<int, int> m;
  void addNum(int value) {
    if (m.count(value))
      return;
    m[value] = value;
    int mn = value, mx = value;
    if (m.count(value - 1))
      mn = m[value - 1];
    if (m.count(value + 1))
      mx = m[value + 1];
    m[mn] = mx;
    m[mx] = mn;
  }
  vvd getIntervals() {
    vvd ans;
    auto it = m.begin();
    while (it != m.end()) {
      ans.push_back({it->first, it->second});
      it = m.upper_bound(it->second);
    }
    return ans;
  }
};

int main() {
  SummaryRanges *obj = new SummaryRanges();
  int value;
  obj->addNum(value);
  vvd param_2 = obj->getIntervals();
}
