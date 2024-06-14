// 849. Maximize Distance to Closest Person
#include "leetcode.h"

/*
 * given an array representing a row of 'seats' where 'seats[i] = 1' represents
 * a person sitting in the i'th seat, and 'seats[i] = 0' represents that the
 * i'th seat is empty (0-indexed). there is at least one empty seat, and at
 * least one person sitting. alex wants to sit in the seat such that the
 * distance between him and the closest person to him is maximised. return that
 * maximum distance to the closest person.
 */

class Solution {
public:
  int maxDistToClosest(vector<int> &seats) {
    int n = seats.size(), empty = 0, ans = 0, idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; i++) {
      if (seats[i] == 1) {
        empty = 0;
        if (idx1 == -1)
          idx1 = i;
        idx2 = i;
      } else {
        empty++;
        ans = max(ans, (empty + 1) / 2);
      }
    }
    ans = max({ans, idx1, n - 1 - idx2});
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {1, 0, 0, 0, 1, 0, 1}, s2 = {1, 0, 0, 0}, s3 = {0, 1};
  printf("%d\n", obj.maxDistToClosest(s1)); // expect: 2
  printf("%d\n", obj.maxDistToClosest(s2)); // expect: 3
  printf("%d\n", obj.maxDistToClosest(s3)); // expect: 1
}
