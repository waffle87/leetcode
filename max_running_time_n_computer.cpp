// 2141. Maximum Running Time of N Computers
#include "leetcode.h"

/*
 * you have 'n' computers. you are given the integer 'n' and a 0-indexed integer
 * array 'batteries' where the i'th battery can run a computer for
 * 'batteries[i]' minutes. you are interested in running all 'n' computers
 * simultaneously using the given batteries. initially, you can insert at most
 * one battery into each computer. after that and at any integer time moment,
 * you can remove a battery from a computer and insert another battery any
 * number of times. the inserted battery can be a totally new battery or a
 * battery forom another computer. you may assume that the removing and
 * inserting process takes no time. note that the batteries canot be recharged.
 * return the maximum number of minutes you can run all the 'n' computers
 * simultaneously.
 */

class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    sort(batteries.begin(), batteries.end());
    long long sum = accumulate(batteries.begin(), batteries.end(), 0L);
    int k = 0, i = batteries.size();
    while (batteries[i - 1 - k] > sum / (n - k))
      sum -= batteries[i - 1 - k++];
    return sum / (n - k);
  }
};

int main() {
  Solution obj;
  vector<int> b1 = {3, 3, 3}, b2 = {1, 1, 1, 1};
  printf("%lld\n", obj.maxRunTime(2, b1)); // expect: 4
  printf("%lld\n", obj.maxRunTime(2, b2)); // expect: 2
}
