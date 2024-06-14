// 2140. Solving Questions With Brainpower
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

long long mostPoints(int **questions, int questions_size,
                     int *questions_col_size) {
  long long *dp = malloc((questions_size + 1) * sizeof(long long));
  dp[questions_size] = 0;
  for (int i = questions_size - 1; i >= 0; i--) {
    int k = fmin(i + questions[i][1] + 1, questions_size);
    dp[i] = fmax(questions[i][0] + dp[k], dp[i + 1]);
  }
  long long ans = dp[0];
  free(dp);
  return ans;
}

int main() {
  int q1[4][2] = {{3, 2}, {4, 3}, {4, 4}, {2, 5}}, qs1 = 4, qcs1[] = {};
  int q2[5][2] = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}}, qs2 = 5, qcs2[] = {};
  printf("%lld\n", mostPoints(q1, qs1, qcs1)); // expect: 5
  printf("%lld\n", mostPoints(q2, qs2, qcs2)); // expect: 7
}
