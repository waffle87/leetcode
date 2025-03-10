// 731. My Calendar II
#include "leetcode.h"

/*
 * you are implementing a program to use as your calendar. we can add a new
 * event if adding the event will not cause a triple booking. a triple booking
 * happens when three events have the same non empty intersection (ie. some
 * moment is common to all the three event). the event can be represented as a
 * pair of integers 'start' and 'end' that represents a booking on the half open
 * interval '[start, end]', the range of real numbers 'x' such that 'start <= x
 * < end'.
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

class MyCalendarTwo {
  vector<pair<int, int>> books;

public:
  bool book(int start, int end) {
    MyCalendar overlaps;
    for (pair<int, int> p : books)
      if (max(p.first, start) < min(end, p.second)) {
        pair<int, int> overlapped = getOverlap(p.first, p.second, start, end);
        if (!overlaps.book(overlapped.first, overlapped.second))
          return false;
      }
    books.push_back({start, end});
    return true;
  }
  pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
    return {max(s0, s1), min(e0, e1)};
  }
};

int main() {
  MyCalendarTwo *obj = new MyCalendarTwo();
  printf("%d\n", obj->book(10, 20)); // expect: 1
  printf("%d\n", obj->book(50, 60)); // expect: 1
  printf("%d\n", obj->book(10, 40)); // expect: 1
  printf("%d\n", obj->book(5, 15));  // expect: 0
  printf("%d\n", obj->book(5, 10));  // expect: 1
  printf("%d\n", obj->book(25, 55)); // expect: 1
  delete obj;
}
