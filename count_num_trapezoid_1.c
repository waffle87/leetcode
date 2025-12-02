// 3623. Count Number of Trapezoids I
#include "leetcode.h"

/*
 * you are given a 2d integer array 'points' where 'points[i] = [x_i, y_i]'
 * represents the coordinates of the i'th point on the cartesian plane. a
 * horizontal trapezoid is a convex quadrilateral with at least one pair of
 * horizontal sides. two lines are parallel if and only if they have the same
 * slope. return the number of unique horizontal trapezoids that can be formed
 * by choosing any four distinct points from 'points'. since the answer may very
 * large, return it modulo 1e9 + 7.
 */

struct hash_node {
  int key;
  long long val;
  struct hash_node *next;
};

struct hash_map {
  struct hash_node **buckets;
  int size;
};

struct hash_map *hash_map_init(int size) {
  struct hash_map *obj = (struct hash_map *)malloc(sizeof(struct hash_map));
  obj->size = size;
  obj->buckets = (struct hash_node **)calloc(size, sizeof(struct hash_node *));
  return obj;
}

int hash_func(int key, int size) { return abs(key) % size; }

void put(struct hash_map *obj, int key, long long val) {
  int idx = hash_func(key, obj->size);
  struct hash_node *curr = obj->buckets[idx];
  while (curr) {
    if (curr->key == key) {
      curr->val = val;
      return;
    }
    curr = curr->next;
  }
  struct hash_node *new = (struct hash_node *)malloc(sizeof(struct hash_node));
  new->key = key;
  new->val = val;
  new->next = obj->buckets[idx];
  obj->buckets[idx] = new;
}

long long get(struct hash_map *obj, int key) {
  int idx = hash_func(key, obj->size);
  struct hash_node *curr = obj->buckets[idx];
  while (curr) {
    if (curr->key == key)
      return curr->val;
    curr = curr->next;
  }
  return 0;
}

void increment(struct hash_map *obj, int key) {
  int idx = hash_func(key, obj->size);
  struct hash_node *curr = obj->buckets[idx];
  while (curr) {
    if (curr->key == key) {
      curr->val++;
      return;
    }
    curr = curr->next;
  }
  struct hash_node *new = (struct hash_node *)malloc(sizeof(struct hash_node));
  new->key = key;
  new->val = 1;
  new->next = obj->buckets[idx];
  obj->buckets[idx] = new;
}

void hash_map_free(struct hash_map *obj) {
  for (int i = 0; i < obj->size; i++) {
    struct hash_node *curr = obj->buckets[i];
    while (curr) {
      struct hash_node *tmp = curr;
      curr = curr->next;
      free(tmp);
    }
  }
  free(obj->buckets);
  free(obj);
}

int countTrapezoids(int **points, int pointsSize, int *pointsColSize) {
  static int mod = 1e9 + 7;
  struct hash_map *groups = hash_map_init(pointsSize * 2);
  for (int i = 0; i < pointsSize; i++)
    increment(groups, points[i][1]);
  long long ans = 0, total = 0;
  for (int i = 0; i < groups->size; i++) {
    struct hash_node *curr = groups->buckets[i];
    while (curr) {
      long long cnt = curr->val, lines = cnt * (cnt - 1) / 2;
      ans = (ans + total * lines) % mod;
      total = (total + lines) % mod;
      curr = curr->next;
    }
  }
  hash_map_free(groups);
  return (int)ans;
}

int main() {
  int p1i[5][2] = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};
  int p2i[4][2] = {{0, 0}, {1, 0}, {0, 1}, {2, 1}};
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 =
      two_d_arr_init(ARRAY_SIZE(p2i), ARRAY_SIZE(p2i[0]), p2i);
  printf("%d\n",
         countTrapezoids(p1->arr, p1->row_size, p1->col_size)); // expect: 3
  printf("%d\n",
         countTrapezoids(p2->arr, p2->row_size, p2->col_size)); // expect: 1
  two_d_arr_free(p1);
  two_d_arr_free(p2);
}
