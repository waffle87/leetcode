// 1784. Check if Binary String Has at Most One Segment of Ones
#include "leetcode.h"

/*
 * given a binary string 's' without leading zeros, return 'true' if 's'
 * contains at most one contiguous segment of ones. otherwise, return false.
 */

bool checkOnesSegment(char *s) { return !strstr(s, "01"); }

int main() {
  char *s1 = "1001", *s2 = "110";
  bool r1 = checkOnesSegment(s1);
  bool r2 = checkOnesSegment(s2);
  printf("%d\n", r1); // expect: 0
  assert(r1 == false);
  printf("%d\n", r2); // expect: 1
  assert(r2 == true);
}
