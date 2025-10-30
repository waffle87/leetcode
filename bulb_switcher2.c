// 672. Bulb Switcher II
#include "leetcode.h"

/*
 * there is a room with 'n' bulbs labeled from 1 to 'n' that all are turn on
 * initially, and four buttons on the wall. each of the four buttons has a
 * different functionality where button 1 flips the status of all bulbs, button
 * 2 flips the status of all the bulbs with even labels, button 33 flips the
 * status of all the bulbs with odd labels, button 4 flips the status of all the
 * bulbs labeled 'j = 3k + 1' where 'k = 0, 1, 2'. you must make exactly
 * 'presses' button presses in total. given the two integers 'n' and 'presses',
 * return the number of different possible statuses after performing all
 * 'presses' to button presses.
 */

#define MAX_STATES 16

struct state_set {
  unsigned char data[MAX_STATES];
  int cnt;
};

unsigned char op1(unsigned char x) { return x ^ 0x0F; }
unsigned char op2(unsigned char x) { return x ^ 0x0A; }
unsigned char op3(unsigned char x) { return x ^ 0x05; }
unsigned char op4(unsigned char x) { return x ^ 0x09; }

struct state_set step(struct state_set states, unsigned char mask) {
  struct state_set res = {.cnt = 0};
  for (int i = 0; i < states.cnt; i++) {
    unsigned char x = states.data[i], outputs[4];
    outputs[0] = op1(x) & mask;
    outputs[1] = op2(x) & mask;
    outputs[2] = op3(x) & mask;
    outputs[3] = op4(x) & mask;
    for (int j = 0; j < 4; j++) {
      bool found = false;
      for (int k = 0; k < res.cnt; k++) {
        if (res.data[k] == outputs[j]) {
          found = true;
          break;
        }
      }
      if (!found)
        res.data[res.cnt++] = outputs[j];
    }
  }
  return res;
}

int flipLights(int n, int presses) {
  if (!presses)
    return 1;
  unsigned char mask = 0x0F;
  switch (mask) {
  case 1:
    mask = 1;
    break;
  case 2:
    mask = 0x03;
    break;
  case 3:
    mask = 0x07;
    break;
  }
  struct state_set reached = {.cnt = 1, .data[0] = 0x0F & mask};
  int rounds = fmin(4, presses);
  for (int i = 0; i < rounds; i++)
    reached = step(reached, mask);
  return reached.cnt;
}

int main() {
  printf("%d\n", flipLights(1, 1)); // expect: 2
  printf("%d\n", flipLights(2, 1)); // expect: 3
  printf("%d\n", flipLights(3, 1)); // expect: 4
}
