// 2092. Find All People With Secret
#include "leetcode.h"

/*
 * given an integer 'n' indicating there are 'n' people numbered from 0 to 'n -
 * 1'. you are also given a 0-indexed 2d integer array 'meetings' where
 * 'meetings[i] = [x_i, y_i, time_i]' indicates that person 'x_i'  and person
 * 'y_i' have a metting at 'time_i'. a person may attend multiple meetings at
 * the same time. finally, you are given an integer 'firstPerson'. person 0 has
 * a secret and initially shares the secret with a person 'firstPerson' at time
 * 0. this secret is then shared every time a meeting takes place with a person
 * that has the secret. more formall, for every meeting 'x_i', has secret at
 * 'time_i' then they will share the secret with person 'y_i' and vice versa
 */

int cmp(const void **a, const void **b) {
  if ((*(int **)a)[2] == (*(int **)b)[2])
    return (*(int **)a)[0] - (*(int **)b)[0];
  return (*(int **)a)[2] - (*(int **)b)[2];
}

void check(int *list, int a, int b, int i, int *returnSize, int *ans, int *time,
           int *timecount) {
  if (list[a] - list[b] == 1) {
    list[b]++;
    ans[*returnSize] = b;
    *returnSize += 1;
  } else if (list[b] - list[a] == 1) {
    list[a]++;
    ans[*returnSize] = a;
    *returnSize += 1;
  } else if (list[b] == 0 && list[a] == 0) {
    time[*timecount] = i;
    *timecount += 1;
  }
}

void sametime(int **meetings, int *ans, int *returnSize, int *time,
              int timecount, int *list) {
  int count = 1, newtimecount;
  while (count) {
    int copy = *returnSize;
    newtimecount = 0;
    for (int i = 0; i < timecount; i++) {
      check(list, meetings[time[i]][0], meetings[time[i]][1], time[i],
            returnSize, ans, time, &newtimecount);
    }
    count = *returnSize - copy;
    if (count == 0) {
      break;
    }
    copy = *returnSize;
    timecount = newtimecount;
    newtimecount = 0;
    for (int i = timecount - 1; i >= 0; i--) {
      check(list, meetings[time[i]][0], meetings[time[i]][1], time[i],
            returnSize, ans, time, &newtimecount);
    }
    count = *returnSize - copy;
    timecount = newtimecount;
  }
}

int *findAllPeople(int n, int **meetings, int meetingsSize,
                   int *meetingsColSize, int firstPerson, int *returnSize) {
  int *list = calloc(n, sizeof(int));
  int *ans = malloc(sizeof(int) * n);
  int *time = malloc(sizeof(int) * n);
  int timecount = 0;
  *returnSize = 2;
  for (int i = 0; i < meetingsSize; i++) {
    if (meetings[i][0] > meetings[i][1]) {
      int a = meetings[i][1];
      meetings[i][1] = meetings[i][0];
      meetings[i][0] = a;
    }
  }
  qsort(meetings, meetingsSize, sizeof(int *), cmp);
  list[0]++;
  list[firstPerson]++;
  ans[0] = 0;
  ans[1] = firstPerson;
  for (int i = 0; i < meetingsSize; i++) {
    if (list[meetings[i][0]] - list[meetings[i][1]] == 1) {
      list[meetings[i][1]]++;
      ans[*returnSize] = meetings[i][1];
      *returnSize += 1;
    } else if (list[meetings[i][1]] - list[meetings[i][0]] == 1) {
      list[meetings[i][0]]++;
      ans[*returnSize] = meetings[i][0];
      *returnSize += 1;
    } else if (i + 1 < meetingsSize && meetings[i][2] == meetings[i + 1][2]) {
      timecount = 0;
      check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time,
            &timecount);
      i++;
      while (i + 1 < meetingsSize && meetings[i][2] == meetings[i + 1][2]) {
        check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time,
              &timecount);
        i++;
      }
      check(list, meetings[i][0], meetings[i][1], i, returnSize, ans, time,
            &timecount);
      sametime(meetings, ans, returnSize, time, timecount, list);
    }
  }
  free(list);
  free(time);
  return ans;
}

int main() {
  int m1[3][3] = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}},
      m2[3][3] = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}},
      m3[3][3] = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
  int *mcs1, *mcs2, *mcs3, *rs1, *rs2, *rs3;
  int *fap1 = findAllPeople(6, (int **)m1, 3, mcs1, 1, rs1);
  int *fap2 = findAllPeople(4, (int **)m2, 3, mcs2, 1, rs2);
  int *fap3 = findAllPeople(5, (int **)m3, 3, mcs3, 1, rs3);
  for (int i = 0; i < 5; i++)
    printf("%d ", fap1[i]);
  printf("\n");
  for (int i = 0; i < 3; i++)
    printf("%d ", fap2[i]);
  printf("\n");
  for (int i = 0; i < 5; i++)
    printf("%d ", fap3[i]);
  printf("\n");
}
