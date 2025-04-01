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
 */

long long mostPoints(int **questions, int questionsSize,
                     int *questionsColSize) {
  long long *dp = (long long *)malloc((questionsSize + 1) * sizeof(long long));
  dp[questionsSize] = 0;
  for (int i = questionsSize - 1; i >= 0; i--) {
    int k = fmin(i + questions[i][1] + 1, questionsSize);
    dp[i] = fmax(questions[i][0] + dp[k], dp[i + 1]);
  }
  long long ans = dp[0];
  free(dp);
  return ans;
}

int main() {
  int q1i[4][2] = {{3, 2}, {4, 3}, {4, 4}, {2, 5}},
      q2i[5][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  struct two_d_arr q1, q2;
  two_d_arr_init(&q1, ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  two_d_arr_init(&q2, ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  printf("%lld\n", mostPoints(q1.arr, q1.row_size, q1.col_size)); // expect: 5
  printf("%lld\n", mostPoints(q2.arr, q2.row_size, q2.col_size)); // expect: 7
}
