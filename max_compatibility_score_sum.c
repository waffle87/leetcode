// 1947. Maximum Compatibility Score Sum
#include "leetcode.h"

/*
 * there is a survey that consists of 'n' questions where each questions answer
 * is either 0 (no) or 1 (yes). the survey was given to 'm' students numbered
 * from 0 to 'm - 1' and 'm' mentors numbered from 0 to 'm - 1'. the answers of
 * the students are represented by a 2d integer array 'students' where
 * 'students[i]' is an integer array that contains the answers of the i'th
 * student. the answers of the mentors are represented by a 2d integer array
 * 'mentors' where 'mentors[j]' is an integer array that contains the answers of
 * the j'th mentor. each student will be assigned to one mentor. the
 * compatibility score of a student-mentor pair is the number of answers that
 * are the same for both student and mentor. given 'students' and 'mentors',
 * return the maximum compatibility score sum that can be achieved
 */

static int max;

void swap(int *arr, int x, int y) {
  int tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

void per(int *stu, int size, int **score, int start_idx) {
  if (start_idx == size) {
    int total = 0;
    for (int i = 0; i < size; i++)
      total += score[stu[i]][i];
    if (total > max)
      max = total;
    return;
  }
  for (int i = start_idx; i < size; i++) {
    swap(stu, start_idx, i);
    per(stu, size, score, start_idx + 1);
    swap(stu, start_idx, i);
  }
}

int maxCompatibilitySum(int **students, int studentsSize, int *studentsColSize,
                        int **mentors, int mentorsSize, int *mentorsColSize) {
  max = 0;
  int **score = (int **)calloc(studentsSize, sizeof(int *));
  for (int s = 0; s < studentsSize; s++) {
    score[s] = (int *)calloc(mentorsSize, sizeof(int));
    for (int m = 0; m < mentorsSize; m++)
      for (int i = 0; i < *studentsColSize; i++)
        score[s][m] += (students[s][i] == mentors[m][i]);
  }
  int *stu = (int *)malloc(studentsSize * sizeof(int));
  for (int i = 0; i < studentsSize; i++)
    stu[i] = i;
  per(stu, studentsSize, score, 0);
  free(stu);
  for (int i = 0; i < studentsSize; i++)
    free(score[i]);
  free(score);
  return max;
}

int main() {
  int s1[3][3] = {{1, 1, 0}, {1, 0, 1}, {0, 0, 1}},
      m1[3][3] = {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}}, scs1[] = {3, 3, 3},
      mcs1[] = {3, 3, 3};
  int s2[3][2] = {{0, 0}, {0, 0}, {0, 0}}, m2[3][2] = {{1, 1}, {1, 1}, {1, 1}},
      scs2[] = {2, 2, 2}, mcs2[] = {2, 2, 2};
  printf("%d\n",
         maxCompatibilitySum((int **)s1, ARRAY_SIZE(s1), scs1, (int **)m1,
                             ARRAY_SIZE(m1), mcs1)); // expect: 8
  printf("%d\n",
         maxCompatibilitySum((int **)s2, ARRAY_SIZE(s2), scs2, (int **)m2,
                             ARRAY_SIZE(m2), mcs2)); // expect: 0
}
