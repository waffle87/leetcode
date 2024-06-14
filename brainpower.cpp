// 2140. Solving Questions With Brainpower
#include "leetcode.h"

/*
 * given a 0-indexed 2d integer array 'questions' where 'questions[i] =
 * [pointsi, brainpoweri]'. the array describes the questions of an exam, where
 * you have to process the questions in order (ie starting from question 0) and
 * make a decision whether to solve or skip each question. solving question 'i'
 * will earn you 'pointsi' points, but you will be unable to solve each of the
 * next 'brainpoweri' questions. if you skip question 'i', yo get to make the
 * decision on the next question. return maximum points you can score.
 *
 */

class Solution {
public:
  long long mostPoints(vvd(int) & questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      int points = questions[i][0];
      int jump = questions[i][1];
      int next_q = min(jump + i + 1, n);
      long long p = points + dp[next_q];
      dp[i] = max(p, dp[i + 1]);
    }
    return dp[0];
  }
};

int main() {
  Solution obj;
  vvd(int) q1 = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
  vvd(int) q2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  printf("%lld\n", obj.mostPoints(q1)); // expect: 5
  printf("%lld\n", obj.mostPoints(q2)); // expect: 7
}
