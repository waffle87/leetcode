// 1344. Angle Between Hands of a Clock
#include "leetcode.h"

/*
 * given two numbers, 'hour' and 'minutes', return the smaller angle (in
 * degrees) formed between the 'hour' and the 'minute' hand. answers within
 * 10^-5 of the actual value will be accepted.
 */

double angleClock(int hour, int minutes) {
  double min = minutes * 6;
  double hr = hour * 30 + (double)minutes / 2;
  double diff = fabs(hr - min);
  return fmin(diff, 360 - diff);
}

int main() {
  double r1 = angleClock(12, 30);
  double r2 = angleClock(3, 30);
  double r3 = angleClock(3, 15);
  printf("%f\n", r1);
  assert(r1 == 165);
  printf("%f\n", r2);
  assert(r2 == 75);
  printf("%f\n", r3);
  assert(r3 == 7.5);
}
