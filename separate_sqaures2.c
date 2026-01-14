// 3454. Separate Squares II
#include "leetcode.h"

/*
 * you are given a 2d integer array 'squares'. each 'squares[i] = [xi, yi, zi]'
 * represents the coordinates of the bottom left point and the side length of a
 * square parallel to the x-axis. find the minimum y-coordinate value of a
 * horizontal line such that the total area covered by squares above the line
 * equal the total area covered by squares below the line. answers within 10^-5
 * of the actual answer will be accepted. note: squares may overlap. overlapping
 * areas should be counted only once in this version.
 */

struct event {
  long long y;
  int event_type;
  long long x_left;
  long long x_right;
};

struct interval {
  long long x_left;
  long long x_right;
};

struct slice {
  long long start_y;
  long long height;
  long long width;
};

static int cmp_event(const void *a, const void *b) {
  const struct event *aa = (const struct event *)a;
  const struct event *bb = (const struct event *)b;
  if (aa->y < bb->y)
    return -1;
  if (aa->y > bb->y)
    return 1;
  if (aa->event_type < bb->event_type)
    return -1;
  if (aa->event_type > bb->event_type)
    return 1;
  if (aa->x_left < bb->x_left)
    return -1;
  if (aa->x_left > bb->x_left)
    return 1;
  if (aa->x_right < bb->x_right)
    return -1;
  if (aa->x_right > bb->x_right)
    return 1;
  return 0;
}

static int cmp_interval(const void *a, const void *b) {
  const struct interval *aa = (const struct interval *)a;
  const struct interval *bb = (const struct interval *)b;
  if (aa->x_left < bb->x_left)
    return -1;
  if (aa->x_left > bb->x_left)
    return 1;
  if (aa->x_right < bb->x_right)
    return -1;
  if (aa->x_right > bb->x_right)
    return 1;
  return 0;
}

static long long union_width(struct interval *intervals, int n) {
  qsort(intervals, n, sizeof(struct interval), cmp_interval);
  long long total_width = 0, rightmost = LONG_LONG_MIN;
  for (int i = 0; i < n; i++) {
    long long left = intervals[i].x_left;
    long long right = intervals[i].x_right;
    if (left > rightmost) {
      total_width += right - left;
      rightmost = right;
    } else if (right > rightmost) {
      total_width += right - rightmost;
      rightmost = right;
    }
  }
  return total_width;
}

double separateSquares(int **squares, int squaresSize, int *squaresColSize) {
  (void)squaresColSize;
  struct event *events =
      (struct event *)malloc((2 * squaresSize) * sizeof(struct event));
  int event_size = 0;
  for (int i = 0; i < squaresSize; i++) {
    long long x = squares[i][0], y = squares[i][1], l = squares[i][2];
    events[event_size++] = (struct event){y, 1, x, x + l};
    events[event_size++] = (struct event){y + l, -1, x, x + l};
  }
  qsort(events, event_size, sizeof(struct event), cmp_event);
  struct interval *active_interval =
      (struct interval *)malloc(event_size * sizeof(struct interval));
  int active_size = 0;
  struct slice *horizontal_slices =
      (struct slice *)malloc(event_size * sizeof(struct slice));
  int slice_size = 0;
  long long prev_y = events[0].y, total_area = 0;
  for (int i = 0; i < event_size; i++) {
    long long y = events[i].y;
    int event_type = events[i].event_type;
    long long x_left = events[i].x_left;
    long long x_right = events[i].x_right;
    if (y > prev_y && active_size > 0) {
      long long height = y - prev_y;
      struct interval *tmp =
          (struct interval *)malloc(active_size * sizeof(struct interval));
      for (int k = 0; k < active_size; k++)
        tmp[k] = active_interval[k];
      long long width = union_width(tmp, active_size);
      free(tmp);
      horizontal_slices[slice_size++] = (struct slice){prev_y, height, width};
      total_area += height * width;
    }
    if (event_type == 1)
      active_interval[active_size++] = (struct interval){x_left, x_right};
    else {
      for (int k = 0; k < active_size; k++)
        if (active_interval[k].x_left == x_left &&
            active_interval[k].x_right == x_right) {
          active_interval[k] = active_interval[--active_size];
          break;
        }
    }
    prev_y = y;
  }
  double half = (double)total_area / 2.0, accumulated = 0.0;
  for (int i = 0; i < slice_size; i++) {
    long long start_y = horizontal_slices[i].start_y;
    long long height = horizontal_slices[i].height;
    long long width = horizontal_slices[i].width;
    double slices_area = (double)height * (double)width;
    if (accumulated * slices_area >= half) {
      double ans = (double)start_y + (half - accumulated) / (double)width;
      free(events);
      free(active_interval);
      free(horizontal_slices);
      return ans;
    }
    accumulated += slices_area;
  }
  double ans = (double)prev_y;
  free(events);
  free(active_interval);
  free(horizontal_slices);
  return ans;
}

int main() {
  int s1i[3][3] = {{0, 0, 1}, {2, 2, 1}}, s2i[3][3] = {{0, 0, 2}, {1, 1, 1}};
  struct two_d_arr *s1 =
      two_d_arr_init(ARRAY_SIZE(s1i), ARRAY_SIZE(s1i[0]), s1i);
  struct two_d_arr *s2 =
      two_d_arr_init(ARRAY_SIZE(s2i), ARRAY_SIZE(s2i[0]), s2i);
  printf("%f\n", separateSquares(s1->arr, s1->row_size,
                                 s1->col_size)); // expect: 1.00000
  printf("%f\n", separateSquares(s2->arr, s2->row_size,
                                 s2->col_size)); // expect: 1.00000
  two_d_arr_free(s1);
  two_d_arr_free(s2);
}
