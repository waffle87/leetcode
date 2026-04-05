// 657. Robot Return to Origin
#include "leetcode.h"

/*
 * there is a robot starting at the position '(0, 0)', the origin, on a 2d
 * plane. given a sequence of its move, judge if this robot ends up at '(0, 0)'
 * after it completes its moves. you are given a string 'moves' that represents
 * the move sequence of the robot where 'moves[i]' represents its i'th move.
 * valid moves are R, L, U, D. return trueif the robot returns to the origin
 * after it finishes all its moves, or false otherwise.
 */

bool judgeCircle(char *moves) {
  uint64_t counts = 0;
  for (int i = 0; moves[i] != '\0'; i++) {
    uint64_t b = moves[i];
    uint64_t m1 = (b * 0x0001000100010001ULL) | 0x0100010001000100ULL;
    uint64_t m2 = m1 - 0x00550044004C0052ULL;
    uint64_t m3 = m2 | (m2 >> 4);
    uint64_t m4 = m3 | (m3 >> 2);
    uint64_t m5 = m4 | (m4 >> 1);
    uint64_t m6 = m5 | ((~m2 & 0x0100010001000100ULL) >> 8);
    counts += (0x0001000100010001ULL & ~m6);
  }
  uint8_t *cs = (uint8_t *)&counts;
  return cs[0] == cs[2] && cs[1] == cs[3] && cs[4] == cs[6] && cs[5] == cs[7];
}
int main() {
  char *m1 = "UD", *m2 = "LL";
  bool r1 = judgeCircle(m1);
  bool r2 = judgeCircle(m2);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
