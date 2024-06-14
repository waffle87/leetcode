#include "leetcode.h"

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    int time = 0;
    priority_queue<int> pq;
    sort(courses.begin(), courses.end(), compare);
    for (int i = 0; i < courses.size(); i++) {
      if (time + courses[i][0] <= courses[i][1]) {
        time += courses[i][0];
        pq.push(courses[i][0]);
      } else {
        if (!pq.empty() && pq.top() > courses[i][0]) {
          pq.pop();
          time -= pq.top();
          time += courses[i][0];
          pq.push(courses[i][0]);
        }
      }
    }
    return pq.size();
  }

private:
  static bool compare(vector<int> a, vector<int> b) { return a[1] < b[1]; }
};
