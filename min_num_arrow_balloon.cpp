#include "leetcode.h"

class Solution {
public:
  int findMinArrowShots(vvd(int) & points) {
    if (points.size() == 0)
      return 0;
    sort(points.begin(), points.end(), cmp);
    int arrows = 1, end = points[0][1];
    for (int i = 1; i < points.size(); i++)
      if (points[i][0] > end) {
        arrows++;
        end = points[i][1];
      }
    return arrows;
  }

private:
  static bool cmp(vector<int> &x, vector<int> &y) { return x[1] < y[1]; }
};

int main() {
  Solution obj;
  vvd(int) points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}},
           points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}},
           points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  cout << obj.findMinArrowShots(points1) << endl; // expect: 2
  cout << obj.findMinArrowShots(points2) << endl; // expect: 4
  cout << obj.findMinArrowShots(points3) << endl; // expect: 2
}
