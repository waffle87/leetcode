// 3516. Find Closest Person
#include "leetcode.h"

/*
 * you are given three integers represnting the positions of three people on a
 * number line. 'x' is the position of person 1, 'y' is the position of person
 * 2, and 'z' is the position of persion 3 who does not move. both person 1 and
 * person 2 move toward person 3 at the same speed. determine which person will
 * reach person 3 first. return 1 if person 1 will arrive first, return 2 if
 * person 2 will arrive first, and 0 if both arrive at the same time.
 */

int findClosest(int x, int y, int z) {
  int a = abs(x - z), b = abs(y - z);
  return (a != b) << (a > b);
}

int main() {
  printf("%d\n", findClosest(2, 7, 4)); // expect: 1
  printf("%d\n", findClosest(2, 5, 6)); // expect: 2
  printf("%d\n", findClosest(1, 5, 3)); // expect: 0
}
