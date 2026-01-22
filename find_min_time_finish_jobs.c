// 1723. Find Minimum Time to Finish All Jobs
#include "leetcode.h"

/*
 * you are given an integer array 'jobs' where 'jobs[i]' is the amount of time
 * it takes to complete the i'th job. there are 'k' workers that you can assign
 * jobs to. each job should be assigned to exactly one worker. the working time
 * of a worker is the sum of the time it takes to complete all jobs assigned to
 * them. your goal is to devise an optimal assignment such that the maximum
 * working time of any worker is minimised. return the minimum possible maximum
 * working time of any assignment.
 */

struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

int height(struct node *obj) {
  if (!obj)
    return 0;
  return obj->height;
}

struct node *node_init(int key) {
  struct node *obj = (struct node *)malloc(sizeof(struct node));
  obj->key = key;
  obj->left = NULL;
  obj->right = NULL;
  obj->height = 1;
  return obj;
}

struct node *rotate_right(struct node *y) {
  struct node *x = y->left, *tmp = x->right;
  x->right = y;
  y->left = tmp;
  y->height = fmax(height(y->left), height(y->right)) + 1;
  x->height = fmax(height(x->left), height(x->right)) + 1;
  return x;
}

struct node *rotate_left(struct node *x) {
  struct node *y = x->right, *tmp = y->left;
  y->left = x;
  x->right = tmp;
  x->height = fmax(height(x->left), height(x->right)) + 1;
  y->height = fmax(height(y->left), height(y->right)) + 1;
  return y;
}

int get_balance(struct node *obj) {
  if (!obj)
    return 0;
  return height(obj->left) - height(obj->right);
}

struct node *node_insert(struct node *obj, int key) {
  if (!obj)
    return node_init(key);
  if (key < obj->key)
    obj->left = node_insert(obj->left, key);
  else if (key > obj->key)
    obj->right = node_insert(obj->right, key);
  else
    return obj;
  obj->height = fmax(height(obj->left), height(obj->right)) + 1;
  int balance = get_balance(obj);
  if (balance > 1 && key < obj->left->key)
    return rotate_right(obj);
  if (balance < -1 && key > obj->right->key)
    return rotate_left(obj);
  if (balance > 1 && key > obj->left->key) {
    obj->left = rotate_left(obj->left);
    return rotate_right(obj);
  }
  if (balance < -1 && key < obj->right->key) {
    obj->right = rotate_right(obj->right);
    return rotate_left(obj);
  }
  return obj;
}

bool check(struct node *obj, int val) {
  if (!obj)
    return false;
  else {
    if (obj->key == val)
      return true;
    else if (obj->key < val)
      return check(obj->right, val);
    else
      return check(obj->left, val);
  }
}

void assign(int *assignments, int id, int *jobs, int k, int *ans) {
  int i;
  if (id == -1) {
    int res = INT_MIN;
    for (int i = 0; i < k; i++)
      res = fmax(res, assignments[i]);
    *ans = fmin(*ans, res);
    return;
  } else {
    struct node *root = NULL;
    for (int i = 0; i < k; i++) {
      assignments[i] += jobs[id];
      if (check(root, assignments[i])) {
        assignments[i] -= jobs[id];
        continue;
      }
      root = node_insert(root, assignments[i]);
      if (assignments[i] < *ans)
        assign(assignments, id - 1, jobs, k, ans);
      assignments[i] -= jobs[id];
    }
  }
}

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int helper(int *jobs, int n, int k) {
  int *assignments = (int *)calloc(k, sizeof(int));
  int i = n - 1, dir = -1;
  while (i >= 0) {
    int j = fmax(i - k + 1, 0);
    if (dir == -1) {
      int m = i - j + 1;
      for (int j = 0; j < m; j++)
        assignments[j] += jobs[i - j];
    } else {
      int m = i - j + 1;
      for (int j = 0; j < m; j++)
        assignments[m - 1 - j] += jobs[i - j];
    }
    i = j - 1;
    dir = -dir;
  }
  int res = assignments[0];
  for (int i = 1; i < k; i++)
    res = fmax(res, assignments[i]);
  free(assignments);
  return res;
}

int minimumTimeRequired(int *jobs, int jobsSize, int k) {
  qsort(jobs, jobsSize, sizeof(int), cmp);
  int i, ans = helper(jobs, jobsSize, k);
  int *assignments = (int *)calloc(k, sizeof(int));
  assign(assignments, jobsSize - 1, jobs, k, &ans);
  return ans;
}

int main() {
  int j1[] = {3, 2, 3}, j2[] = {1, 2, 4, 7, 8};
  printf("%d\n", minimumTimeRequired(j1, ARRAY_SIZE(j1), 3)); // expect: 3
  printf("%d\n", minimumTimeRequired(j2, ARRAY_SIZE(j2), 2)); // expect: 11
}
