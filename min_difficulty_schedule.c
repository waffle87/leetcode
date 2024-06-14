// 1335. Minimum Difficulty of a Job Schedule
#include "leetcode.h"

/*
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work
on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule
is the sum of difficulties of each day of the d days. The difficulty of a day is
the maximum difficulty of a job done on that day.

You are given an integer array job_difficulty and an integer d. The difficulty
of the ith job is job_difficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule
for the jobs return -1.
*/

int minDifficulty(int *job_difficulty, int job_difficulty_size, int d) {
  int maxValue = 10001, max_difficulty = 0;
  if (job_difficulty_size < d)
    return -1;
  if (d == 1) {
    for (int i = 0; i < job_difficulty_size; i++)
      max_difficulty = fmax(max_difficulty, job_difficulty[i]);
    return max_difficulty;
  }
  max_difficulty = 0;
  int min_job_diff[job_difficulty_size + 1];
  for (int i = 0; i < job_difficulty_size; i++)
    min_job_diff[i] = maxValue;
  min_job_diff[job_difficulty_size] = 0;
  for (int day = 1; day <= d; ++day) {
    for (int i = 0; i <= job_difficulty_size - day; i++) {
      max_difficulty = 0, min_job_diff[i] = maxValue;
      for (int j = i; j <= job_difficulty_size - day; j++) {
        max_difficulty = fmax(max_difficulty, job_difficulty[j]);
        min_job_diff[i] =
            fmin(min_job_diff[i], max_difficulty + min_job_diff[j + 1]);
      }
    }
  }
  return min_job_diff[0];
}

int main() {
  int jb1[] = {6, 5, 4, 3, 2, 1}, jb2[] = {9, 9, 9}, jb3[] = {1, 1, 1};
  printf("%d\n", minDifficulty(jb1, ARRAY_SIZE(jb1), 2)); // expect: 7
  printf("%d\n", minDifficulty(jb2, ARRAY_SIZE(jb2), 4)); // expect: -1
  printf("%d\n", minDifficulty(jb3, ARRAY_SIZE(jb3), 3)); // expect: 3
}
