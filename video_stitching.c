// 1024. Video Stitching
#include "leetcode.h"

/*
 * you are given a series of video clips from a sporting event that lasted
 * 'time' seconds. these video clips can be overlapping with eachother and have
 * varying lengths. each video clip is described by an array 'clips' where
 * 'clips[i] = [start_i, end_i]' indicates that the i'th clip started at
 * 'start_i' end 'end_i'. we can cut these clips into segments freely. return
 * the minimum number of clips needed so that we can cut the clips needed so
 * that we can cut the clips into segments that cover the entire sporting event
 * '[0, time]'. if the task is impossible, return -1
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  if (aa[0] == bb[0])
    return aa[1] - bb[1];
  return aa[0] - bb[0];
}

int videoStitching(int **clips, int clipsSize, int *clipsColSize, int time) {
  qsort(clips, clipsSize, sizeof(int *), cmp);
  if (clips[0][0])
    return -1;
  int idx = -1;
  for (int i = 0; i < clipsSize; i++) {
    int left = clips[i][0], right = clips[i][1];
    if (idx != -1 && clips[idx][1] >= time)
      return idx + 1;
    if (idx != -1 && left > clips[idx][1])
      return -1;
    if (idx == -1) {
      idx++;
      clips[idx][0] = clips[i][0];
      clips[idx][1] = clips[i][1];
    } else if (left == clips[idx][0] && right >= clips[idx][1]) {
      clips[idx][1] = right;
      continue;
    } else if (left >= clips[idx][0] && right <= clips[idx][1]) {
      continue;
    } else if (left < clips[idx][0] && right > clips[idx][1]) {
      while (idx != -1 && left < clips[idx][0] && right > clips[idx][1])
        idx--;
      left = fmax(clips[idx][1], clips[i][0]);
      clips[++idx][0] = left;
      clips[idx][1] = right;
    } else if (left <= clips[idx][1] && right > clips[idx][1]) {
      left = fmax(clips[idx][1], clips[i][0]);
      clips[++idx][0] = left;
      clips[idx][1] = right;
    }
  }
  if (clips[idx][1] < time)
    return -1;
  return idx + 1;
}

int main() {
  int c1i[6][2] = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
  int c2i[2][2] = {{0, 1}, {1, 2}};
  int c3i[16][2] = {{0, 1}, {6, 8}, {0, 2}, {5, 6}, {0, 4}, {0, 3},
                    {6, 7}, {1, 3}, {4, 7}, {1, 4}, {2, 5}, {2, 6},
                    {3, 4}, {4, 5}, {5, 7}, {6, 9}};
  struct two_d_arr *c1 =
      two_d_arr_init(ARRAY_SIZE(c1i), ARRAY_SIZE(c1i[0]), c1i);
  struct two_d_arr *c2 =
      two_d_arr_init(ARRAY_SIZE(c2i), ARRAY_SIZE(c2i[0]), c2i);
  struct two_d_arr *c3 =
      two_d_arr_init(ARRAY_SIZE(c3i), ARRAY_SIZE(c3i[0]), c3i);
  printf("%d\n",
         videoStitching(c1->arr, c1->row_size, c1->col_size, 3)); // expect: 3
  printf("%d\n",
         videoStitching(c2->arr, c2->row_size, c2->col_size, 5)); // expect: -1
  printf("%d\n",
         videoStitching(c3->arr, c3->row_size, c3->col_size, 9)); // expect: 3
  two_d_arr_free(c1);
  two_d_arr_free(c2);
  two_d_arr_free(c3);
}
