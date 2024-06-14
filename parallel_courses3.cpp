// 2050. Parallel Courses III
#include "leetcode.h"

/*
 * given an integer 'n' which indicates that there are n courses labeled from 1
 * to n. you are also given a 2d integer array rleations where relations[j] =
 * pre_course[j], denotes that course pre_course has to be completed before
 * next_course. furthermore, you are given a 0-indexed integer array 'time'
 * where 'time[i]' denotes how many months it takes to complete the '(i + 1)'th
 * course. you must find the minimum number of months needed to complete all the
 * courses following these rules. you may start taking courses at any time if
 * the prerequisites have been met, and any number of courses can be taken at
 * the same time. return the minimum number of monthsneeded to omplete all the
 * courses.
 */

class Solution {
public:
  int minimumTime(int n, vvd(int) & relations, vector<int> &time) {
    vector<int> in_deg(n + 1);
    vvd(int) g(n + 1);
    for (auto r : relations) {
      int a = r[0];
      int b = r[1];
      g[a].push_back(b);
      in_deg[b]++;
    }
    vector<int> finish_time(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (!in_deg[i])
        q.push(i);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      finish_time[curr] += time[curr - 1];
      for (auto next : g[curr]) {
        in_deg[next]--;
        finish_time[next] = max(finish_time[next], finish_time[curr]);
        if (!in_deg[next])
          q.push(next);
      }
    }
    return *max_element(finish_time.begin(), finish_time.end());
  }
};

int main() {
  Solution obj;
  vvd(int) r1 = {{1, 3}, {2, 3}}, r2 = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
  vector<int> t1 = {3, 2, 5}, t2 = {1, 2, 3, 4, 5};
  printf("%d\n", obj.minimumTime(3, r1, t1)); // expect: 8
  printf("%d\n", obj.minimumTime(5, r2, t2)); // expect: 12
}
