// 1095. Find in Mountain Array
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * 1. find peak and record location and value that's already been queried, and
 * verify if target has happened
 * 2. if target has happened and idx <= peak, exit and return ans
 * 3. query right of mountain and return true if target is found
 * 4. query left of mountain and return true if target is found
 * 5. if target is not found, return -1
 */

int get(MountainArray *, int index);
int length(MountainArray *);

int find_peak(MountainArray *mountain_arr, int len, int *data, bool *flag,
              int target, int *idx) {
  int left = 0, right = len - 1, mid, l, m, r;
  while (left < right) {
    mid = (left + right) / 2;
    m = get(mountain_arr, mid);
    flag[mid] = true;
    data[mid] = m;
    if (m == target)
      *idx = fmin(*idx, mid);
    r = get(mountain_arr, mid + 1);
    flag[mid + 1] = true;
    data[mid + 1] = r;
    if (r == target)
      *idx = fmin(*idx, mid + 1);
    if (m < r)
      left = mid + 1;
    else {
      l = get(mountain_arr, mid - 1);
      flag[mid - 1] = true;
      data[mid - 1] = l;
      if (l == target)
        *idx = fmin(*idx, mid - 1);
      if (m > l)
        return mid;
      else
        right = mid - 1;
    }
  }
  return left;
}

int find_val(MountainArray *mountain_arr, int begin, int end, int val,
             int *data, bool *flag, bool up) {
  int left = begin, right = end, tmp;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (flag[mid])
      tmp = data[mid];
    else
      tmp = get(mountain_arr, mid);
    if (tmp == val)
      return mid;
    if (tmp > val) {
      if (up)
        right = mid - 1;
      else
        left = mid + 1;
    }
  }
  if (get(mountain_arr, left) == val)
    return left;
  else
    return -1;
}

int findInMountainArray(int target, MountainArray *mountain_arr) {
  int len = length(mountain_arr), *idx = malloc(sizeof(int)), ans;
  int *data = malloc(len * sizeof(int));
  bool *flag = calloc(len, sizeof(bool));
  *idx = INT_MAX;
  int peak = find_peak(mountain_arr, len, data, flag, target, idx);
  if (*idx <= peak) {
    ans = *idx;
    goto exit;
  }
  ans = find_val(mountain_arr, 0, peak, target, data, flag, true);
  if (ans == -1)
    ans = find_val(mountain_arr, peak + 1, len - 1, target, data, flag, false);
exit:
  free(data), free(flag);
  return ans;
}
