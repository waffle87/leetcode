#include "leetcode.h"

class Point { // basic coordinate geometry
public:
  double x, y;
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
};

class Solution {
public:
  int maxPoints(vvd(int) & points) {
    int n = points.size(), ans = 0;
    if (n <= 2) // 2 or less means points are always collinear
      return n;
    vector<Point> coordinates;
    for (auto &i : points) {
      Point k = Point((double)i[0], (double)i[1]);
      coordinates.push_back(k);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < n; k++)
          if (i != j && j != k && i != k)
            if (isCollinear(coordinates[i], coordinates[j], coordinates[k]))
              cnt++;
        ans = max(cnt + 2, ans);
      }
    return ans;
  }

private:
  bool isCollinear(Point a, Point b,
                   Point c) { // checks if 3 given points lie on same line
    double i = (b.y - a.y) / (b.x - a.x);
    double j = (c.y - b.y) / (c.x - b.x);
    return i == j;
  }
};

int main() {
  Solution obj;
  vvd(int) points1 = {{1, 1}, {2, 2}, {3, 3}},
           points2 = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
  cout << obj.maxPoints(points1) << endl; // expect: 3
  cout << obj.maxPoints(points2) << endl; // expect: 4
}
