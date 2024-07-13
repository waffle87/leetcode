// 2751. Robot Collisions
#include "leetcode.h"

/*
 * there are 'n' 1 indexed robots, each having a position on a line, health, and
 * movement directions. all robots start moving on the line simultaneously at
 * the same speed in their given directions. if two robots ever share the same
 * position while moving, they will collide. if two robots collide, the robot
 * with lower health is removed from the line and the health of the other robot
 * decreases by 1. the surviving robot continues in the same direction it was
 * going. if both robots have the same health they are both removed from the
 * line. return an array containing the health of the remaining robots after no
 * further collisions can occur
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[0] - bb[0];
}

int *survivedRobotsHealths(int *positions, int positionsSize, int *healths,
                           int healthsSize, char *directions, int *returnSize) {
  int **record = (int **)malloc(sizeof(int *) * positionsSize);
  int *stack = (int *)malloc(sizeof(int) * positionsSize), idx = -1;
  int *ans = (int *)malloc(sizeof(int) * positionsSize);
  *returnSize = 0;
  for (int i = 0; i < positionsSize; i++) {
    record[i] = (int *)malloc(sizeof(int) * 2);
    record[i][0] = positions[i];
    record[i][1] = i;
    if (directions[i] == 'L')
      healths[i] *= 1;
  }
  qsort(record, positionsSize, sizeof(int *), cmp);
  for (int i = 0; i < positionsSize; i++) {
    if (idx == -1) {
      stack[++idx] = record[i][1];
    } else if (healths[record[i][1]] < 0 && healths[stack[idx]] > 0) {
      if (healths[stack[idx]] == -1 * healths[record[i][1]]) {
        healths[stack[idx]] = 0;
        healths[record[i][1]] = 0;
        idx--;
      } else if (healths[stack[idx]] > -1 * healths[record[i][1]]) {
        healths[record[i][1]] = 0;
        healths[stack[idx]] -= 1;
      } else {
        while (idx != -1 && healths[stack[idx]] > 0 &&
               healths[stack[idx]] < -1 * healths[record[i][1]]) {
          healths[stack[idx]] = 0;
          idx--;
          healths[record[i][1]] += 1;
        }
        if (idx == -1 || healths[stack[idx]] < 0) {
          stack[++idx] = record[i][1];
        } else if (-1 * healths[record[i][1]] == healths[stack[idx]]) {
          healths[stack[idx]] = 0;
          healths[record[i][1]] = 0;
          idx--;
        } else {
          healths[record[i][1]] = 0;
          healths[stack[idx]] -= 1;
        }
      }
    } else {
      stack[++idx] = record[i][1];
    }
  }
  for (int i = 0; i < positionsSize; i++)
    free(record[i]);
  free(record), free(stack);
  for (int i = 0; i < positionsSize; i++)
    if (healths[i])
      ans[(*returnSize)++] = abs(healths[i]);
  return ans;
}

int main() {
  int p1[] = {5, 4, 3, 2, 1}, h1[] = {2, 17, 9, 15, 10}, rs1;
  int p2[] = {3, 5, 2, 6}, h2[] = {10, 10, 15, 12}, rs2;
  int p3[] = {1, 2, 5, 6}, h3[] = {10, 10, 11, 11}, rs3;
  char s1[] = "RRRRR", s2[] = "RLRL", s3[] = "RLRL";
  int *sbh1 =
      survivedRobotsHealths(p1, ARRAY_SIZE(p1), h1, ARRAY_SIZE(h1), s1, &rs1);
  int *sbh2 =
      survivedRobotsHealths(p2, ARRAY_SIZE(p2), h2, ARRAY_SIZE(h2), s2, &rs2);
  int *sbh3 =
      survivedRobotsHealths(p3, ARRAY_SIZE(p3), h3, ARRAY_SIZE(h3), s3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sbh1[i]); // expect: 2,17,9,15,10
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sbh2[i]); // expect: 14
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", sbh3[i]); // expect: null
  printf("\n");
  free(sbh1), free(sbh2), free(sbh3);
}
