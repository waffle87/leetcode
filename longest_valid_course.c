// 1964. Find the Longest Valid Obstacle Course at Each Position
#include "leetcode.h"

/*
 * you want to build obstacle courses. you are given a 0-indexed integer array
 * 'obstacles' of length 'n' where 'obstacles[i]' describes the height of the
 * i'th obstacle. for every index 'i' between 0 and 'n - 1' (inclusive), find
 * the length of the longest obstacle course in 'obstacles' such that:
 * - you choose any number of obstacles between 0 and 'i' inclusive
 * - you must include the i'th obstacle in the course
 * - you must put the chosen obstacles in the same order as they appear in
 * 'obstacles'
 * - every obstacle (except the first) is taller than or the same height as the
 * obstacle immediately before it return an array 'ans' of length 'n', where
 * 'ans[i]' is the length of the longest obstacle course for index 'i' as
 * described above
 */

int find(int *arr, int start, int end, int target) {
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
      start = mid + 1;
    else if (arr[mid] > target)
      end = mid;
    else
      start = mid + 1;
  }
  return start;
}

int *longestObstacleCourseAtEachPosition(int *obstacles, int obstaclesSize,
                                         int *returnSize) {
  int *ans = (int *)calloc(obstaclesSize, sizeof(int));
  int *cnt = (int *)calloc(obstaclesSize, sizeof(int)), n = 1;
  ans[0] = 1;
  cnt[0] = obstacles[0];
  for (int i = 1; i < obstaclesSize; i++) {
    int idx = find(cnt, 0, n, obstacles[i]);
    if (idx == n)
      cnt[n++] = obstacles[i];
    else
      cnt[idx] = obstacles[i];
    ans[i] = idx + 1;
  }
  *returnSize = obstaclesSize;
  free(cnt);
  return ans;
}

int main() {
  int o1[] = {1, 2, 3, 2}, o2[] = {2, 2, 1}, o3[] = {3, 1, 5, 6, 4, 2}, rs1,
      rs2, rs3;
  int *locaep1 = longestObstacleCourseAtEachPosition(o1, ARRAY_SIZE(o1), &rs1);
  int *locaep2 = longestObstacleCourseAtEachPosition(o2, ARRAY_SIZE(o2), &rs2);
  int *locaep3 = longestObstacleCourseAtEachPosition(o3, ARRAY_SIZE(o3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", locaep1[i]); // expect: 1 2 3 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", locaep2[i]); // expect: 1 2 1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", locaep3[i]); // expect: 1 1 2 3 2 2
  printf("\n");
  free(locaep1), free(locaep2), free(locaep3);
}
