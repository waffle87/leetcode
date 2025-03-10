// 1552. Magnetic Force Between Two Balls
#include "leetcode.h"

/*
 * in the universe earth c-137 rick discovered a special form of magnetic force
 * between two balls if they are put in his new invented basket. rick has 'n'
 * empty baskets the i'th basket is at 'position[i]', more has 'm' ball and
 * needs to distribute the balls into the baskets such that the minimum magnetic
 * force between any two balls is maximum. rick stated that magnetic force
 * betweeen two different balls at positions 'x' and 'y' is '|x - y|'. given the
 * integer array 'position' and the integer 'm', return the required force.
 */

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int ans = 1, i = 999999999;
    while (ans < i) {
      int mid = (ans + i) / 2 + 1;
      if (check(position, m, mid))
        ans = mid;
      else
        i = mid - 1;
    }
    return ans;
  }

private:
  int check(vector<int> &position, int m, int force) {
    int pos = position[0];
    for (auto i = 1; i < position.size() && m > 1; ++i)
      if (position[i] - pos >= force) {
        --m;
        pos = position[i];
      }
    return m < 2;
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {1, 2, 3, 4, 7}, p2 = {5, 4, 3, 2, 1, 1000000000};
  printf("%d\n", obj.maxDistance(p1, 3)); // expect: 3
  printf("%d\n", obj.maxDistance(p2, 2)); // expect: 999999999
}
