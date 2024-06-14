#include "leetcode.h"

class MyCalendarTwo {
public:
  map<int, int> m;
  MyCalendarTwo() {}
  bool book(int start, int end) {
    m[start]++;
    m[end]--;
    int booked = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      booked += it->second;
      if (booked == 3) {
        m[start]--;
        m[end]++;
        return false;
      }
    }
    return true;
  }
};

int main() {
  int start, end;
  MyCalendarTwo *obj = new MyCalendarTwo();
  bool param_1 = obj->book(start, end);
  if (param_1)
    cout << "true";
  else
    cout << "false";
}
