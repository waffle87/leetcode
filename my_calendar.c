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

typedef struct {
  int *date;
  int idx;
} MyCalendar;

MyCalendar *myCalendarCreate() {
  MyCalendar *n = (MyCalendar *)malloc(sizeof(MyCalendar));
  n->date = (int *)malloc(2000 * sizeof(int));
  n->idx = 0;
  return n;
}

bool myCalendarBook(MyCalendar *obj, int start, int end) {
  for (int i = 0; i < obj->idx; i += 2)
    if (obj->date[i] < end && start < obj->date[i + 1])
      return false;
  obj->date[obj->idx] = start;
  obj->date[obj->idx + 1] = end;
  obj->idx += 2;
  return true;
}

void myCalendarFree(MyCalendar *obj) {
  free(obj->date);
  free(obj);
}

int main() {
  MyCalendar *obj = myCalendarCreate();
  printf("%d\n", myCalendarBook(obj, 10, 20)); // expect: 1
  printf("%d\n", myCalendarBook(obj, 15, 25)); // expect: 0
  printf("%d\n", myCalendarBook(obj, 20, 30)); // expect: 1
  myCalendarFree(obj);
}
