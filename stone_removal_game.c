// 3360. Stone Removal Game
#include "leetcode.h"

bool canAliceWin(int n) { return 0x61f03f807fC00 >> n & 1; }

int main() {
  bool r1 = canAliceWin(12);
  bool r2 = canAliceWin(1);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == false);
}
