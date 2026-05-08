// 3629. Minimum Jumps to Reach End via Prime Teleportation
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n'. you start at index 0,
 * and your goal is to reach index 'n - 1'. from any index 'i', you may perform
 * onee of the following operations: adjacent step: jump to index 'i + 1' or 'i
 * - 1', if the index is within bounds, or prime teleportation: if 'nums[i]' is
 * a prime number, you may instantly jump to any index 'j != i' such that
 * 'nums[j] % p == 0'. return the minimum number of jumps to reach the index 'n
 * - 1'.
 */

#define MAX_SIZE 1000001
#define HASH_SIZE 10007

typedef struct {
  int *data;
  int size;
  int cap;
} vector;

typedef struct node {
  int key;
  vector values;
  struct node *next;
} node;

static node *hash_table[HASH_SIZE];
static vector factors[MAX_SIZE];
static bool precomputed = false;

void vector_push(vector *v, int val) {
  if (v->size == v->cap) {
    v->cap = v->cap == 0 ? 2 : v->cap * 2;
    v->data = (int *)realloc(v->data, v->cap * sizeof(int));
  }
  v->data[v->size++] = val;
}

void hash_push(int key, int val) {
  int h = abs(key) % HASH_SIZE;
  node *cur = hash_table[h];
  while (cur) {
    if (cur->key == key) {
      vector_push(&cur->values, val);
      return;
    }
    cur = cur->next;
  }
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  memset(&new_node->values, 0, sizeof(vector));
  vector_push(&new_node->values, val);
  new_node->next = hash_table[h];
  hash_table[h] = new_node;
}

vector *hash_get(int key) {
  int h = abs(key) % HASH_SIZE;
  node *cur = hash_table[h];
  while (cur) {
    if (cur->key == key)
      return &cur->values;
    cur = cur->next;
  }
  return NULL;
}

void precompute() {
  if (precomputed)
    return;
  for (int i = 2; i < MAX_SIZE; i++) {
    if (factors[i].size == 0) {
      for (int j = i; j < MAX_SIZE; j += i) {
        vector_push(&factors[j], i);
      }
    }
  }
  precomputed = true;
}

void clear_hash() {
  for (int i = 0; i < HASH_SIZE; i++) {
    node *cur = hash_table[i];
    while (cur) {
      node *tmp = cur;
      cur = cur->next;
      free(tmp->values.data);
      free(tmp);
    }
    hash_table[i] = NULL;
  }
}

int minJumps(int *nums, int numsSize) {
  precompute();
  clear_hash();
  int n = numsSize;
  for (int i = 0; i < n; i++)
    for (int p_idx = 0; p_idx < factors[nums[i]].size; p_idx++)
      hash_push(factors[nums[i]].data[p_idx], i);
  bool *vis = (bool *)calloc(n, sizeof(bool));
  int *q = (int *)malloc(n * sizeof(int));
  int q_start = 0, q_end = 0;
  vis[0] = true;
  q[q_end++] = 0;
  int ans = 0;
  while (q_start < q_end) {
    int level_size = q_end - q_start;
    for (int k = 0; k < level_size; k++) {
      int i = q[q_start++];
      if (i == n - 1) {
        free(vis);
        free(q);
        return ans;
      }
      if (i > 0 && !vis[i - 1]) {
        vis[i - 1] = true;
        q[q_end++] = i - 1;
      }
      if (i < n - 1 && !vis[i + 1]) {
        vis[i + 1] = true;
        q[q_end++] = i + 1;
      }
      if (factors[nums[i]].size == 1) {
        int p = nums[i];
        vector *v = hash_get(p);
        if (v) {
          for (int j_idx = 0; j_idx < v->size; j_idx++) {
            int j = v->data[j_idx];
            if (!vis[j]) {
              vis[j] = true;
              q[q_end++] = j;
            }
          }
          v->size = 0;
        }
      }
    }
    ans++;
  }
  return -1;
}

int main() {
  int n1[] = {1, 2, 4, 6};
  int n2[] = {2, 3, 4, 7, 9};
  int n3[] = {4, 6, 5, 8};
  int r1 = minJumps(n1, ARRAY_SIZE(n1));
  int r2 = minJumps(n2, ARRAY_SIZE(n2));
  int r3 = minJumps(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 2);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 3);
}
