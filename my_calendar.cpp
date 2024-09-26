// 729. My Calendar I
#include "leetcode.h"

/*
 * you are implementing a program to use as your calendar. we can add a new
 * event if adding the event will not cause a double booking. a double booking
 * happens when two events have some non empty intersection (ie. some moment is
 * common to both events.). the event can be represented as a pair of integers
 * 'start' and 'end' that represent a booking on the half open interval '[start,
 * end)', the range of real numbers 'x' such that 'start <= x < end'.
 */

class MyCalendar {
  vector<pair<int, int>> books;

public:
  bool book(int start, int end) {
    for (pair<int, int> p : books)
      if (max(p.first, start) < min(end, p.second))
        return false;
    books.push_back({start, end});
    return true;
  }
};

int main() {
  MyCalendar *obj = new MyCalendar();
  printf("%d\n", obj->book(10, 20)); // expect: 1
  printf("%d\n", obj->book(15, 25)); // expect: 0
  printf("%d\n", obj->book(20, 30)); // expect: 1
}
