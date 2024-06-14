// 1232. Check If It Is a Straight Line
#include "leetcode.h"

/*
 * given an array 'coordinates, coordinates[i] = [x, y]' where '[x, y]'
 * represents the coordinate of a point. check if these points make a straight
 * line in the xy plane
 */

class Solution {
public:
  bool checkStraightLine(vvd(int) & coordinates) {
    int n = coordinates.size();
    if (n == 1)
      return false;
    if (n == 2)
      return true;
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    int dx = coordinates[1][0] - x0, dy = coordinates[1][1] - y0;
    for (int i = 1; i < n; i++) {
      int x = coordinates[i][0], y = coordinates[i][1];
      if (dx * (y - y0) != dy * (x - x0))
        return false;
    }
    return true;
  }
};

int main() {
  Solution obj;
  vvd(int) c1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
  vvd(int) c2 = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  printf("%d\n", obj.checkStraightLine(c1)); // expect: 1
  printf("%d\n", obj.checkStraightLine(c2)); // expect: 0
}
