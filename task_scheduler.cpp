// 2365. Task Scheduler II
#include "leetcode.h"

/*
 * given a 0-indexed array of positive integers 'tasks', representing tasks that
 * need to be completed in order, where 'tasks[i]' represents the type of the
 * i'th task. you are also given a positve integer 'space' which represents the
 * minimum number of days that must pass after the completion of a task before
 * another task of the same type can be performed. each day until all tasks have
 * been completed, you must either
 * - complete the next task from 'tasks' or
 * - take a break
 * return the minimum number of days needed to complete all tasks.
 */

class Solution {
public:
  long long taskSchedulerII(vector<int> &tasks, int space) {
    unordered_map<int, long long> last;
    long long ans = 0;
    for (int t : tasks) {
      if (last.count(t))
        last[t] = ans = max(ans, last[t] + space) + 1;
      else
        last[t] = ++ans;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> t1 = {1, 2, 1, 2, 3, 1}, t2 = {5, 8, 8, 5};
  printf("%lld\n", obj.taskSchedulerII(t1, 3)); // expect: 9
  printf("%lld\n", obj.taskSchedulerII(t2, 2)); // expect: 6
}
