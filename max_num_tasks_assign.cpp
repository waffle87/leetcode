// 2071. Maximum Number of Tasks You Can Assign
#include "leetcode.h"

/*
 * you have 'n' tasks and 'm' workers. each task has a strength requirement
 * stored in a 0-indexed integer array 'tasks', with the i'th task requiring
 * 'tasks[i]' strength to complete. the strength of each worker is stored in a
 * 0-indexed array 'workers' with the j'th worker having 'workers[j]' strength.
 * each worker can only be assigned to a single task and must have a strength
 * greather than or equal to the task's strength requirement. additionally, you
 * have 'pills' magic pills that will increase a workers strength by 'strength'.
 * you can decide which workers receive the pills, however, you may only give
 * each worker at most one magical pill. given the 0-indexed integer arrays
 * 'tasks' and 'workers' and the integers 'pills' and 'strength', return the
 * maximum number of tasks that can be completed.
 */

class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    int n = tasks.size(), m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int lo = 0, hi = min(m, n), ans;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = 0;
      bool flag = true;
      multiset<int> st(workers.begin(), workers.end());
      for (int i = mid - 1; i >= 0; i--) {
        auto it = prev(st.end());
        if (tasks[i] <= *it)
          st.erase(it);
        else {
          auto it = st.lower_bound(tasks[i] - strength);
          if (it != st.end()) {
            cnt++;
            st.erase(it);
          } else {
            flag = false;
            break;
          }
        }
        if (cnt > pills) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> t1 = {3, 2, 1}, t2 = {5, 4}, t3 = {10, 15, 30};
  vector<int> w1 = {0, 3, 3}, w2 = {0, 0, 0}, w3 = {0, 10, 10, 10, 10};
  printf("%d\n", obj.maxTaskAssign(t1, w1, 1, 1));  // expect: 3
  printf("%d\n", obj.maxTaskAssign(t2, w2, 1, 5));  // expect: 1
  printf("%d\n", obj.maxTaskAssign(t3, w3, 3, 10)); // expect: 2
}
