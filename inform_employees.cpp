// 1376. Time Needed to Inform All Employees
#include "leetcode.h"

/*
 * a company has 'n' employees with a unique id for each employee from 0 to 'n -
 * 1'. the head of the company is the one with the 'head_id'. each employee has
 * one direct manager given the 'manager' array where 'manager[i]' is the direct
 * manager of the i'th employee, 'manager[head_id] = -1'. also it is guaranteed
 * that the subordination relations have a tree structure. the head of the
 * company wants to inform all the company employees of an urgent piece of new.
 * he will inform his direct subordinates, and they will inform their
 * subordinates and so on until all the employees know about the urgent news.
 * the i'th employee needs 'inform_time[i]' minutes to inform all of his direct
 * subordinates (ie. after 'inform_time[i]' minutes, all his direct subordinates
 * can start spreading the news) return the number of minutes needed to inform
 * all the employees about the urget news.
 */

class Solution {
  int dfs(int i, vector<int> &manager, vector<int> &inform_time) {
    if (manager[i] != -1) {
      inform_time[i] += dfs(manager[i], manager, inform_time);
      manager[i] = -1;
    }
    return inform_time[i];
  }

public:
  int numOfMinutes(int n, int head_id, vector<int> &manager,
                   vector<int> &inform_time) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = max(ans, dfs(i, manager, inform_time));
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> m1 = {-1}, m2 = {2, 2, -1, 2, 2, 2};
  vector<int> it1 = {0}, it2 = {0, 0, 1, 0, 0, 0};
  printf("%d\n", obj.numOfMinutes(1, 0, m1, it1)); // expect: 0
  printf("%d\n", obj.numOfMinutes(6, 2, m2, it2)); // expect: 1
}
