// 1964. Find the Longest Valid Obstacle Course at Each Position
#include "leetcode.h"

/*
 * you want to build obstacle courses. you are given a 0-indexed integer array
 * 'obstacles' of length 'n' where 'obstacles[i]' describes the height of the
 * i'th obstacle. for every index 'i' between 0 and 'n - 1' (inclusive), find
 * the length of the longest obstacle course in 'obstacles' such that:
 * - you choose any number of obstacles between 0 and 'i' inclusive
 * - you must include the i'th obstacle in the course
 * - you must put the chosen obstacles in the same order as they appear in
 * 'obstacles'
 * - every obstacle (except the first) is taller than or the same height as the
 * obstacle immediately before it return an array 'ans' of length 'n', where
 * 'ans[i]' is the length of the longest obstacle course for index 'i' as
 * described aboveeeeeeeee
 */

class Solution {
public:
  vector<int> longestObstacleCourseAtEachEachPosition(vector<int> &obstacles) {
    vector<int> n;
    for (int i = 0; i < obstacles.size(); ++i) {
      auto it = upper_bound(n.begin(), n.end(), obstacles[i]);
      if (it == n.end()) {
        n.push_back(obstacles[i]);
        it = prev(n.end());
      } else {
        *it = obstacles[i];
      }
      obstacles[i] = it - n.begin() + 1;
    }
    return obstacles;
  }
};

int main() {
  Solution obj;
  vector<int> o1 = {1, 2, 3, 2}, o2 = {2, 2, 1}, o3 = {3, 1, 5, 6, 4, 2};
  for (auto i : obj.longestObstacleCourseAtEachEachPosition(o1))
    printf("%d ", i); // expect: 1 2 3 3
  printf("\n");
  for (auto i : obj.longestObstacleCourseAtEachEachPosition(o2))
    printf("%d ", i); // expect: 1 2 1
  printf("\n");
  for (auto i : obj.longestObstacleCourseAtEachEachPosition(o3))
    printf("%d ", i); // expect: 1 1 2 3 2 2
  printf("\n");
}
