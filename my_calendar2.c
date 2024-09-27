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

struct interval {
  int start;
  int end;
};

typedef struct {
  struct interval *bookings;
  int bookings_size;
  struct interval *overlaps;
  int overlaps_size;
} MyCalendarTwo;

MyCalendarTwo *myCalendarTwoCreate() {
  MyCalendarTwo *obj = (MyCalendarTwo *)malloc(sizeof(MyCalendarTwo));
  obj->bookings = (struct interval *)malloc(1000 * sizeof(int));
  obj->bookings_size = 0;
  obj->overlaps = (struct interval *)malloc(1000 * sizeof(int));
  obj->overlaps_size = 0;
  return obj;
}

bool myCalendarTwoBook(MyCalendarTwo *obj, int start, int end) {
  for (int i = 0; i < obj->overlaps_size; i++)
    if (start < obj->overlaps[i].end && end > obj->overlaps[i].start)
      return false;
  for (int i = 0; i < obj->bookings_size; i++)
    if (start < obj->bookings[i].end && end > obj->bookings[i].start) {
      int overlap_start =
          start > obj->bookings[i].start ? start : obj->bookings[i].start;
      int overlap_end = end < obj->bookings[i].end ? end : obj->bookings[i].end;
      obj->overlaps[obj->overlaps_size++] =
          (struct interval){overlap_start, overlap_end};
    }
  obj->bookings[obj->bookings_size++] = (struct interval){start, end};
  return true;
}

void myCalendarTwoFree(MyCalendarTwo *obj) {
  free(obj->bookings);
  free(obj->overlaps);
  free(obj);
}

int main() {
  MyCalendarTwo *obj = myCalendarTwoCreate();
  printf("%d\n", myCalendarTwoBook(obj, 10, 20)); // expect: 1
  printf("%d\n", myCalendarTwoBook(obj, 50, 60)); // expect: 1
  printf("%d\n", myCalendarTwoBook(obj, 10, 40)); // expect: 1
  printf("%d\n", myCalendarTwoBook(obj, 5, 15));  // expect: 0
  printf("%d\n", myCalendarTwoBook(obj, 5, 10));  // expect: 1
  printf("%d\n", myCalendarTwoBook(obj, 25, 55)); // expect: 1
  myCalendarTwoFree(obj);
}
