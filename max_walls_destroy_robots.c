// 3661. Maximum Walls Destroyed by Robots
#include "leetcode.h"

/*
 * there is an endless straight line populated with some robots and walls. you
 * are given integer arrays 'robots', 'distance', and 'walls'. 'robots[i]' is
 * the position of the i'th robot, 'distance[i]' is the maximum distance the
 * i'th robot's bullet can travel, and 'walls[j]' is the position of the j'th
 * wall. every robot has one bullet that can either fire to the left or right at
 * most 'distance[i]'. a bullet destroys every wall in its path that lies within
 * its range. robots are fixed obstacles. if a bullet hits another robot before
 * reaching a wall, it immediately stops at that robot  and cannot continue.
 * return the maximum number of unique walls that can be dstroyed by the robots.
 */

struct hash_item {
  int key;
  int val;
  UT_hash_handle hh;
};

struct hash_item *hash_find_item(struct hash_item **obj, int key) {
  struct hash_item *p = NULL;
  HASH_FIND_INT(*obj, &key, p);
  return p;
}

bool hash_add_item(struct hash_item **obj, int key, int val) {
  if (hash_find_item(obj, key))
    return false;
  struct hash_item *p = (struct hash_item *)malloc(sizeof(struct hash_item));
  p->key = key;
  p->val = val;
  HASH_ADD_INT(*obj, key, p);
  return true;
}

bool hash_set_item(struct hash_item **obj, int key, int val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    hash_add_item(obj, key, val);
  else
    p->val = val;
  return true;
}

int hash_get_item(struct hash_item **obj, int key, int def_val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    return def_val;
  return p->val;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int lower_bound(int *arr, int n, int target) {
  int left = 0, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int upper_bound(int *arr, int n, int target) {
  int left = 0, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] <= target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int maxWalls(int *robots, int robotsSize, int *distance, int distanceSize,
             int *walls, int wallsSize) {
  int n = robotsSize;
  int *left = (int *)calloc(n, sizeof(int));
  int *right = (int *)calloc(n, sizeof(int));
  int *num = (int *)calloc(n, sizeof(int));
  struct hash_item *robot_dist = NULL;
  for (int i = 0; i < n; i++)
    hash_add_item(&robot_dist, robots[i], distance[i]);
  int *sorted_robots = (int *)malloc(n * sizeof(int));
  memcpy(sorted_robots, robots, n * sizeof(int));
  qsort(sorted_robots, n, sizeof(int), cmp);
  int *sorted_walls = (int *)malloc(wallsSize * sizeof(int));
  memcpy(sorted_walls, walls, wallsSize * sizeof(int));
  qsort(sorted_walls, wallsSize, sizeof(int), cmp);
  for (int i = 0; i < n; i++) {
    int p1 = upper_bound(sorted_walls, wallsSize, sorted_robots[i]), lp;
    if (i >= 1) {
      int lb = fmax(sorted_robots[i] -
                        hash_get_item(&robot_dist, sorted_robots[i], 0),
                    sorted_robots[i - 1] + 1);
      lp = lower_bound(sorted_walls, wallsSize, lb);
    } else
      lp = lower_bound(sorted_walls, wallsSize,
                       sorted_robots[i] -
                           hash_get_item(&robot_dist, sorted_robots[i], 0));
    left[i] = p1 - lp;
    int rp;
    if (i < n - 1) {
      int rb = fmin(sorted_robots[i] +
                        hash_get_item(&robot_dist, sorted_robots[i], 0),
                    sorted_robots[i + 1] - 1);
      rp = upper_bound(sorted_walls, wallsSize, rb);
    } else
      rp = upper_bound(sorted_walls, wallsSize,
                       sorted_robots[i] +
                           hash_get_item(&robot_dist, sorted_robots[i], 0));
    int p2 = lower_bound(sorted_walls, wallsSize, sorted_robots[i]);
    right[i] = rp - p2;
    if (!i)
      continue;
    int p3 = lower_bound(sorted_walls, wallsSize, sorted_robots[i - 1]);
    num[i] = p1 - p3;
  }
  int sl = left[0], sr = right[0];
  for (int i = 1; i < n; i++) {
    int cl = fmax(sl + left[i],
                  sr - right[i - 1] + fmin(left[i] + right[i - 1], num[i]));
    int cr = fmax(sl + right[i], sr + right[i]);
    sl = cl;
    sr = cr;
  }
  int ans = fmax(sl, sr);
  free(left);
  free(right);
  free(num);
  free(sorted_robots);
  free(sorted_walls);
  hash_free(&robot_dist);
  return ans;
}

int main() {
  int r1[] = {4}, d1[] = {3}, w1[] = {1, 10};
  int r2[] = {10, 2}, d2[] = {5, 1}, w2[] = {5, 2, 7};
  int r3[] = {1, 2}, d3[] = {100, 1}, w3[] = {10};
  int mw1 =
      maxWalls(r1, ARRAY_SIZE(r1), d1, ARRAY_SIZE(d1), w1, ARRAY_SIZE(w1));
  int mw2 =
      maxWalls(r2, ARRAY_SIZE(r2), d2, ARRAY_SIZE(d2), w2, ARRAY_SIZE(w2));
  int mw3 =
      maxWalls(r3, ARRAY_SIZE(r3), d3, ARRAY_SIZE(d3), w3, ARRAY_SIZE(w3));
  printf("%d\n", mw1);
  assert(mw1 == 1);
  printf("%d\n", mw2);
  assert(mw2 == 3);
  printf("%d\n", mw3);
  assert(mw3 == 0);
}
