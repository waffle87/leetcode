// 1882. Process Tasks Using Servers
#include "leetcode.h"

/*
 * You are given two 0-indexed integer arrays 'servers' and 'tasks' of lengths
 * 'n' and 'm' respectively. 'servers[i]' is the weight of the i'th server, and
 * 'tasks[j]' is the time needed to process the j'th task in seconds. tasks are
 * assigned to the servers using a task queue. initially, all servers are free,
 * and the queue is empty. at second 'j', the j'th task is inserted into the
 * queue (starting with the 0'th task being inserted at second 0). as long as
 * there are free servers and the queue is not empyt, the task in the front of
 * the queue will be assigned to a free server with the smallest weight, and
 * incase of a tie, it is assigned to a free server with the smallest index. a
 * server that is assigned task 'j' at second 't' will be free again at second
 * 't + tasks[j]'. build an array 'ans' of length 'm' where 'ans[j]' is the
 * index of the server the j'th task will be assigned to.
 */

struct node {
  long long time;
  int weight;
  int idx;
};

struct heap {
  struct node *data;
  int size;
  int capacity;
  int busy;
};

static int less_node(struct node a, struct node b, int busy) {
  if (busy && a.time != b.time)
    return a.time;
  if (a.weight != b.weight)
    return a.weight < b.weight;
  return a.idx < b.idx;
}

static struct heap *heap_init(int capacity, int busy) {
  struct heap *obj = (struct heap *)malloc(sizeof(struct heap));
  obj->data = (struct node *)malloc(capacity * sizeof(struct node));
  obj->size = 0;
  obj->capacity = capacity;
  obj->busy = busy;
  return obj;
}

static void heap_push(struct heap *obj, struct node val) {
  int i = obj->size++;
  obj->data[i] = val;
  while (i > 0) {
    int p = (i - 1) / 2;
    if (!less_node(obj->data[i], obj->data[p], obj->busy))
      break;
    struct node tmp = obj->data[i];
    obj->data[i] = obj->data[p];
    obj->data[p] = tmp;
    i = p;
  }
}

static struct node heap_pop(struct heap *obj) {
  struct node res = obj->data[0];
  obj->size--;
  if (!obj->size)
    return res;
  obj->data[0] = obj->data[obj->size];
  int i = 0;
  while (true) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int best = i;
    if (l < obj->size && less_node(obj->data[l], obj->data[best], obj->busy))
      best = l;
    if (r < obj->size && less_node(obj->data[r], obj->data[best], obj->busy))
      best = r;
    if (best == i)
      break;
    struct node tmp = obj->data[i];
    obj->data[i] = obj->data[best];
    obj->data[best] = tmp;
    i = best;
  }
  return res;
}

int *assignTasks(int *servers, int serversSize, int *tasks, int tasksSize,
                 int *returnSize) {
  int n = serversSize, m = tasksSize;
  *returnSize = m;
  int *ans = (int *)malloc(m * sizeof(int));
  struct heap *heap_small = heap_init(n, 0);
  struct heap *heap_large = heap_init(n, 1);
  for (int i = 0; i < n; i++)
    heap_push(heap_small, (struct node){0, servers[i], i});
  for (int i = 0; i < m; i++) {
    while (heap_large->size > 0 && heap_large->data[0].time <= i) {
      struct node n = heap_pop(heap_large);
      heap_push(heap_small, n);
    }
    if (heap_small->size > 0) {
      struct node n = heap_pop(heap_small);
      ans[i] = n.idx;
      n.time = (long long)i + tasks[i];
      heap_push(heap_large, n);
    } else {
      struct node n = heap_pop(heap_large);
      ans[i] = n.idx;
      n.time += tasks[i];
      heap_push(heap_large, n);
    }
  }
  free(heap_small->data);
  free(heap_large->data);
  free(heap_small);
  free(heap_large);
  return ans;
}

int main() {
  int s1[] = {3, 3, 2}, t1[] = {1, 2, 3, 2, 1, 2};
  int r1[] = {2, 2, 0, 2, 1, 2}, rs1;
  int s2[] = {5, 1, 4, 3, 2}, t2[] = {2, 1, 2, 4, 5, 2, 1};
  int r2[] = {1, 4, 1, 4, 1, 3, 2}, rs2;
  int *at1 = assignTasks(s1, ARRAY_SIZE(s1), t1, ARRAY_SIZE(t1), &rs1);
  int *at2 = assignTasks(s2, ARRAY_SIZE(s2), t2, ARRAY_SIZE(t2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", at1[i]);
    assert(at1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", at2[i]);
    assert(at2[i] == r2[i]);
  }
  printf("\n");
  free(at1);
  free(at2);
}
