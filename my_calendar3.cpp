#include "leetcode.h"

class MyCalendarThree {
public:
  map<int, int> count = {{-1, 0}};
  int ans = 0;
  MyCalendarThree() {}
  int book(int start, int end) {
    auto s = count.emplace(start, (--count.upper_bound(start))->second);
    auto e = count.emplace(end, (--count.upper_bound(end))->second);
    for (auto i = s.first; i != e.first; ++i)
      ans = max(ans, ++(i->second));
    return ans;
  }
};

int main() {
  int start, end;
  MyCalendarThree *obj = new MyCalendarThree();
  int param_1 = obj->book(start, end);
}
