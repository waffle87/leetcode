// 1942. The Number of the Smallest Unoccupied Chair
#include "leetcode.h"

/*
 * there is a party where 'n' friends numbered from 0 to 'n - 1' are attending.
 * there is an infinite number of chairs in this part that are numbered from 0
 * to 'infinity'. when a friend arrives at the party, they sit on the unoccupied
 * chair with the smallest number. when a friend leaves the party their chair
 * becomes unoccupied at the moment they leave. if another friend arrives at
 * that same moment, they can sit in that chair. you are given a 0-indexed 2d
 * integer array 'times' where 'times[i] = [arrival[i], leaving[i]]' indicating
 * the arrival and leaving times of the i'th friend respectively. and an integer
 * 'targetFriend'. all arrival times are distinct. return the chair number that
 * the friend numbered 'targetFriend' will sit on.
 */

int cmp(const void *a, const void *b) {
  return (*(int **)a)[0] - (*(int **)b)[0];
}

void heap_down(int **chair, int *heap, int heap_size) {
  int curr = 1, child = curr * 2;
  while (child <= heap_size) {
    if (child + 1 <= heap_size &&
        chair[heap[child + 1]][0] < chair[heap[child]][0])
      child++;
    if (chair[heap[curr]][0] < chair[heap[child]][0])
      break;
    int tmp = heap[child];
    heap[child] = heap[curr];
    heap[curr] = tmp;
    curr = child;
    child *= 2;
  }
}

void heap_up(int **chair, int *heap, int idx, int val) {
  int curr = idx, parent = curr / 2;
  while (parent >= 1) {
    if (chair[heap[parent]][0] <= chair[val][0])
      break;
    heap[curr] = heap[parent];
    curr = parent;
    parent /= 2;
  }
  heap[curr] = val;
}

int smallestChair(int **times, int timesSize, int *timesColSize,
                  int targetFriend) {
  int ans = 0, valid_idx = timesSize, invalid_idx = 0;
  int **chair = (int **)malloc(timesSize * sizeof(int *));
  int **qdata = (int **)malloc(timesSize * sizeof(int *));
  int *valid = (int *)malloc((timesSize + 1) * sizeof(int));
  int *invalid = (int *)malloc((timesSize + 1) * sizeof(int));
  for (int i = 0; i < timesSize; i++) {
    qdata[i] = (int *)malloc(3 * sizeof(int));
    qdata[i][0] = times[i][0];
    qdata[i][1] = times[i][1];
    qdata[i][2] = i;
    chair[i] = (int *)malloc(3 * sizeof(int));
    chair[i][0] = chair[i][1] = i;
    chair[i][2] = 0;
    valid[i + 1] = i;
  }
  qsort(qdata, timesSize, sizeof(qdata[0]), cmp);
  for (int i = 0; i < timesSize; i++) {
    while (invalid_idx && chair[invalid[1]][0] <= qdata[i][0]) {
      int target = invalid[i];
      chair[target][0] = chair[target][1];
      heap_up(chair, valid, ++valid_idx, target);
      invalid[1] = invalid[invalid_idx--];
      heap_down(chair, invalid, invalid_idx);
    }
    if (targetFriend == qdata[i][2])
      ans = chair[valid[1]][1];
    int target = valid[1];
    chair[target][0] = chair[target][2] = qdata[i][1];
    heap_up(chair, invalid, ++invalid_idx, target);
    valid[1] = valid[valid_idx--];
    heap_down(chair, valid, valid_idx);
  }
  for (int i = 0; i < timesSize; i++)
    free(chair[i]), free(qdata[i]);
  free(chair), free(qdata), free(valid), free(invalid);
  return ans;
}

int main() {
  int t1[3][2] = {{1, 4}, {2, 3}, {4, 6}}, t2[3][2] = {{3, 10}, {1, 5}, {2, 6}},
      tcs1 = 2, tcs2 = 2;
  printf("%d\n",
         smallestChair((int **)t1, ARRAY_SIZE(t1), &tcs1, 1)); // expect: 1
  printf("%d\n",
         smallestChair((int **)t2, ARRAY_SIZE(t2), &tcs2, 0)); // expect: 2
}
