// 3208. alternating groups ii
#include "leetcode.h"

/*
 * there is a circle of red and blue tiles. you are given an array of integers
 * 'colours' and an integer 'k'. the colour of tile 'i' is represented by
 * 'colours[i]': '0' means that tile 'i' is red, and '1' means that tile 'i' is
 * blue. an alternating group is every 'k' contiguous tiles in the circle with
 * alternating colours. return the number of alternating groups. note that since
 * 'colours' represents a circle, the first and last tiles are considered to be
 * next to eachother.
 */

int numberOfAlternatingGroups(int *colours, int coloursSize, int k) {
  int cnt = 0, left = 0;
  for (int right = 0; right < coloursSize + k - 1; ++right) {
    if (right &&
        colours[right % coloursSize] == colours[(right - 1) % coloursSize])
      left = right;
    if (right - left + 1 >= k)
      cnt++;
  }
  return cnt;
}

int main() {
  int c1[] = {0, 1, 0, 1, 0}, c2[] = {0, 1, 0, 0, 1, 0, 1}, c3[] = {1, 1, 0, 1};
  printf("%d\n", numberOfAlternatingGroups(c1, ARRAY_SIZE(c1), 3)); // expect: 3
  printf("%d\n", numberOfAlternatingGroups(c2, ARRAY_SIZE(c2), 6)); // expect: 2
  printf("%d\n", numberOfAlternatingGroups(c3, ARRAY_SIZE(c3), 4)); // expect: 0
}
