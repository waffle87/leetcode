// 319. Bulb Switcher
#include <math.h>
#include <stdio.h>

/*
 * there are 'n' light bulbs that are initially off. you first turn on all the
 * bulbs, then you turn off every second bulb. on the third round, you toggle
 * every third bulb (turning on if it is off or vice-versa). for the i'th round,
 * you toggle every 'i' bulb for the n'th round, you only toggle the last bulb.
 * return the number that on after 'n'
 */

int bulbSwitch(int n) { return sqrt(n); }

int main() {
  printf("%d\n", bulbSwitch(3)); // expect: 1
  printf("%d\n", bulbSwitch(0)); // expect: 0
  printf("%d\n", bulbSwitch(1)); // expect: 1
}
