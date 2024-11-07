// 2100. Find Good Days to Rob the Bank
#include "leetcode.h"

/*
 * you and a gang of thieves are planning on robbing a bank. you are given a
 * 0-indexed integer array 'security' where 'security[i]' is the number of
 * guards on duty on the i'th day. the days are numbered starting from 0. you
 * are also given an integer 'time'. the i'th day is a good day to rob the bank
 * if there are at least 'time' days before and after the i'th day, the number
 * of guards at the bank for the 'time' days before/after 'i' are
 * non-increasing/non-decreasing. return a list of all days (0-indexed) that are
 * good days to rob the bank. the order that the days are returned in does not
 * matter
 */

int *goodDaysToRobBank(int *security, int securitySize, int time,
                       int *returnSize) {
  int **duty = (int **)malloc(securitySize * sizeof(int *));
  int *ans = (int *)malloc(securitySize * sizeof(int));
  *returnSize = 0;
  for (int i = 0; i < securitySize; i++)
    duty[i] = (int *)calloc(1, sizeof(int) * 2);
  for (int i = 1, guards = security[0], cnt = 0; i < securitySize; i++) {
    cnt = guards >= security[i] ? cnt + 1 : 0;
    guards = security[i];
    duty[i][0] = cnt;
  }
  for (int i = securitySize - 2, guards = security[securitySize - 1], cnt = 0;
       i >= 0; i--) {
    cnt = guards >= security[i] ? cnt + 1 : 0;
    guards = security[i];
    duty[i][1] = cnt;
  }
  for (int i = 0; i < securitySize; i++) {
    if (duty[i][0] >= time && duty[i][1] >= time) {
      ans[*returnSize] = i;
      (*returnSize)++;
    }
    free(duty[i]);
  }
  free(duty);
  return ans;
}

int main() {
  int s1[] = {5, 3, 3, 3, 5, 6, 2}, rs1;
  int s2[] = {1, 1, 1, 1, 1}, rs2;
  int s3[] = {1, 2, 3, 4, 5, 6}, rs3;
  int *gdtrb1 = goodDaysToRobBank(s1, ARRAY_SIZE(s1), 2, &rs1);
  int *gdtrb2 = goodDaysToRobBank(s2, ARRAY_SIZE(s2), 0, &rs2);
  int *gdtrb3 = goodDaysToRobBank(s3, ARRAY_SIZE(s3), 2, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", gdtrb1[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", gdtrb2[i]); // expect: 0 1 2 3 4
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", gdtrb3[i]); // expect: NULL
  printf("\n");
  free(gdtrb1), free(gdtrb2), free(gdtrb3);
}
