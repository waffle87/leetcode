#include "leetcode.h"

struct lNode {
public:
  int start, end;
  lNode *next;
  lNode(int s, int e, lNode *n) {
    start = s;
    end = e;
    next = n;
  }
};

class MyCalendar {
public:
  MyCalendar() {
    lNode *tail = new lNode(INT_MAX, INT_MAX, nullptr);
    calendar = new lNode(-1, -1, tail);
  }
  bool book(int start, int end) {
    lNode *curr = calendar, *last = curr;
    while (start >= curr->end)
      last = curr, curr = curr->next;
    if (curr->start < end)
      return false;
    last->next = new lNode(start, end, curr);
    return true;
  }

private:
  lNode *calendar;
};

int main() {
  int start, end;
  MyCalendar *obj = new MyCalendar();
  bool param_1 = obj->book(start, end);
}
