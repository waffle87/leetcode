// 735. Asteroid Collision
#include "leetcode.h"

/*
 * given an array 'asteroids' o intergers representing asteroids in a row. for
 * each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * each asteroid moves at the same speed. find out the state of the asteroids
 * after all collisions. if two asteroids meet the smaller one will explode. if
 * both are the same size, both will explode. two asteroids moving in the same
 * direction will never meet.
 */

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    int n = asteroids.size();
    stack<int> s;
    for (int i = 0; i < n; i++) {
      if (asteroids[i] || s.empty())
        s.push(asteroids[i]);
      else {
        while (!s.empty() && s.top() && s.top() < abs(asteroids[i]))
          s.pop();
        if (!s.empty() && s.top() == abs(asteroids[i]))
          s.pop();
        else if (s.empty() || s.top() < 0)
          s.push(asteroids[i]);
      }
    }
    vector<int> ans(s.size());
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      ans[i] = s.top();
      s.pop();
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {5, 10, -5}, a2 = {8, -8}, a3 = {10, 2, -5};
  for (auto i : obj.asteroidCollision(a1))
    printf("%d ", i); // expect: 5 10
  printf("\n");
  for (auto i : obj.asteroidCollision(a2))
    printf("%d ", i); // expect: nil
  printf("\n");
  for (auto i : obj.asteroidCollision(a3))
    printf("%d ", i); // expect: 10
  printf("\n");
}
