// 2582. Pass the Pillow
#include "leetcode.h"

/*
 * there are 'n' people standing in a line labeled from 1 to 'n'. the first
 * person in the line is holding a pillow initially. every second, the person
 * holding the pillow passe it to the next person standing in the line. once the
 * pillow reaching the end of the line, the direction changes and people
 * continue passing the pillow in the opposite direction. given the two positive
 * integers 'n' and 'time', return the index of the peson holding the pillow
 * after 'time' seconds.
 */

int passThePillow(int n, int time) {
  int rounds = time / (n - 1), ans = 0;
  ans = !(rounds % 2) ? 1 + time % (n - 1) : n - time % (n - 1);
  return ans;
}

int main() {
  printf("%d\n", passThePillow(4, 5)); // expect: 2
  printf("%d\n", passThePillow(3, 2)); // expect: 3
}
