// 2409. Count Days Spent Together
#include "leetcode.h"

/*
 * alice and bob are traveling to rome for separate business meetings. you are
 * given 4 strings. alice will be in the city from the dates 'arriveAlice' to
 * 'leaveAlice' (inclusive), and similarly such for bob. each will be a
 * 5-character string in the format "MM-DD", corresponding to the month and day
 * of date. return the total number o days that alice and bob are in rome
 * together. you can assume all date occur in the same calendar year, which is
 * not a leap year.
 */

int convert(char *date) {
  int lengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = (date[3] - '0') * 10 + (date[4] - '0');
  int months = (date[0] - '0') * 10 + (date[1] - '0');
  int total = days;
  for (int i = 0; i < months - 1; i++)
    total += lengths[i];
  return total;
}

int countDaysTogether(char *arriveAlice, char *leaveAlice, char *arriveBob,
                      char *leaveBob) {
  int a1 = convert(arriveAlice);
  int a2 = convert(leaveAlice);
  int b1 = convert(arriveBob);
  int b2 = convert(leaveBob);
  int start = a1, end = a2;
  start = fmax(start, b1);
  end = fmin(end, b2);
  if (end < start)
    return 0;
  return end - start + 1;
}

int main() {
  char *aa1 = "08-15", *la1 = "08-18", *ab1 = "08-16", *lb1 = "08-19";
  char *aa2 = "10-01", *la2 = "10-31", *ab2 = "11-01", *lb2 = "12-31";
  int r1 = countDaysTogether(aa1, la1, ab1, lb1);
  int r2 = countDaysTogether(aa2, la2, ab2, lb2);
  printf("%d\n", r1);
  assert(r1 == 3);
  printf("%d\n", r2);
  assert(r2 == 0);
}
