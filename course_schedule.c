// 207. Course Schedule
#include <stdbool.h>
#include <stdlib.h>

/*
 * there are a total of 'num_courses' courses you have to take labeled from 0 to
 * 'num_courses - 1'. you are given an array 'prerequisites' where
 * 'prerequisites[i] = [ai, bi]' indicates that you must take course 'bi' first
 * if you want to take course 'ai'. return true if you can finish all courses,
 * otherwise, return false
 */

int cmp(const void *a, const void *b) {
  int *arr1 = *(int **)a;
  int *arr2 = *(int **)b;
  return arr1[1] - arr2[1];
}

int bts(int **arr, int arr_size, int val) {
  int left = 0, right = arr_size - 1, mid;
  while (left < right) {
    mid = left + (right - left) / 2;
    if (arr[mid][1] >= val)
      right = mid;
    else
      left = mid + 1;
  }
  if (arr[left][1] == val)
    return left;
  else
    return -1;
}

bool canFinish(int num_courses, int **prerequisites, int prerequisites_size,
               int *prerequisites_col_size) {
  int *pre_cnt = calloc(num_courses, sizeof(int));
  for (int i = 0; i < prerequisites_size; i++)
    pre_cnt[prerequisites[i][0]]++;
  int *queue = malloc(1000 * sizeof(int)), queue_idx = 0;
  for (int i = 0; i < num_courses; i++)
    if (!pre_cnt[i]) {
      queue[queue_idx] = i;
      queue_idx++;
    }
  if (prerequisites_size)
    qsort(prerequisites, prerequisites_size, sizeof(int *), cmp);
  int course_seq = 0;
  while (queue_idx) {
    queue_idx--;
    int val = queue[queue_idx];
    course_seq++;
    if (prerequisites_size) {
      int k = bts(prerequisites, prerequisites_size, val);
      if (k != -1)
        while (k < prerequisites_size && prerequisites[k][1] == val) {
          pre_cnt[prerequisites[k][0]]--;
          if (!pre_cnt[prerequisites[k][0]]) {
            queue[queue_idx] = prerequisites[k][0];
            queue_idx++;
          }
          k++;
        }
    }
  }
  if (course_seq != num_courses)
    return false;
  else
    return true;
}
