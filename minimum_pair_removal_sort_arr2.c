// 3510. Minimum Pair Removal to Sort Array II
#include "leetcode.h"

/*
 * given an array 'nums', you can perfor the following operation any number of
 * times: select the adjacent pair with the minimum sum in 'nums'. if multiple
 * such pairs exist, choose the leftmost one. replace the pair with their sum.
 * return the minimum number of operations needed to make the array
 * non-decreasing. an array is said to be non-decreasing if each element is
 * greater than or equal to its previous element.
 */

#define QUEUE_SIZE 4096

struct node {
  long long val;
  int left;
  struct node *prev;
  struct node *next;
};

struct node *node_init(long long val, int left) {
  struct node *obj = (struct node *)malloc(sizeof(struct node));
  obj->val = val;
  obj->left = left;
  obj->prev = NULL;
  obj->next = NULL;
  return obj;
}

struct queue_item {
  struct node *first;
  struct node *second;
  long long cost;
  int first_left;
  int second_left;
};

struct element {
  struct queue_item item;
};

typedef bool (*cmp)(const void *, const void *);

static bool item_less(const void *a, const void *b) {
  const struct element *e1 = (const struct element *)a;
  const struct element *e2 = (const struct element *)b;
  const struct queue_item *i1 = &e1->item;
  const struct queue_item *i2 = &e2->item;
  if (i1->cost != i2->cost)
    return i1->cost > i2->cost;
  return i1->first_left > i2->first_left;
}

static void swap(struct element *obj, int i, int j) {
  struct element tmp = obj[i];
  obj[i] = obj[j];
  obj[j] = tmp;
}

struct priority_queue {
  struct element *arr;
  int capacity;
  int queue_size;
  cmp less_fn;
};

struct priority_queue *priority_queue_init(cmp cmp_fn) {
  struct priority_queue *obj =
      (struct priority_queue *)malloc(sizeof(struct priority_queue));
  obj->capacity = QUEUE_SIZE;
  obj->arr = (struct element *)malloc(obj->capacity * sizeof(struct element));
  obj->queue_size = 0;
  obj->less_fn = cmp_fn;
  return obj;
}

static void down(struct element *obj, int size, int i, cmp cmp_fn) {
  while (true) {
    int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
    if (left < size && cmp_fn(&obj[smallest], &obj[left]))
      smallest = left;
    if (right < size && cmp_fn(&obj[smallest], &obj[right]))
      smallest = right;
    if (smallest == i)
      break;
    swap(obj, i, smallest);
    i = smallest;
  }
}

void queue_push(struct priority_queue *obj, const struct queue_item *item) {
  if (obj->queue_size == obj->capacity) {
    obj->capacity *= 2;
    obj->arr = (struct element *)realloc(obj->arr, obj->capacity *
                                                       sizeof(struct element));
  }
  obj->arr[obj->queue_size].item = *item;
  int i = obj->queue_size;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (!obj->less_fn(&obj->arr[parent], &obj->arr[i]))
      break;
    swap(obj->arr, i, parent);
    i = parent;
  }
  obj->queue_size++;
}

struct queue_item *queue_pop(struct priority_queue *obj) {
  if (!obj->queue_size)
    return NULL;
  swap(obj->arr, 0, obj->queue_size - 1);
  struct queue_item *res = &obj->arr[obj->queue_size - 1].item;
  obj->queue_size--;
  if (obj->queue_size > 0)
    down(obj->arr, obj->queue_size, 0, obj->less_fn);
  return res;
}

struct queue_item *queue_top(const struct priority_queue *obj) {
  if (!obj->queue_size)
    return NULL;
  return &obj->arr[0].item;
}

bool empty(const struct priority_queue *obj) { return !obj->queue_size; }

int size(const struct priority_queue *obj) { return obj->queue_size; }

void queue_free(struct priority_queue *obj) {
  free(obj->arr);
  free(obj);
}

int minimumPairRemoval(int *nums, int numsSize) {
  struct priority_queue *pq = priority_queue_init(item_less);
  bool *merged = (bool *)calloc(numsSize, sizeof(bool));
  int decrease_cnt = 0, cnt = 0;
  struct node **nodes =
      (struct node **)malloc(numsSize * sizeof(struct node *));
  for (int i = 0; i < numsSize; i++) {
    nodes[i] = node_init(nums[i], i);
    if (i > 0) {
      nodes[i - 1]->next = nodes[i];
      nodes[i]->prev = nodes[i - 1];
    }
  }
  for (int i = 1; i < numsSize; i++) {
    struct queue_item item;
    item.first = nodes[i - 1];
    item.second = nodes[i];
    item.cost = item.first->val + item.second->val;
    item.first_left = item.first->left;
    item.second_left = item.second->left;
    queue_push(pq, &item);
    if (nums[i - 1] > nums[i])
      decrease_cnt++;
  }
  while (decrease_cnt > 0 && !empty(pq)) {
    struct queue_item *item_ptr = queue_pop(pq);
    if (!item_ptr)
      break;
    struct queue_item item = *item_ptr;
    if (merged[item.first_left] && merged[item.second_left])
      continue;
    struct node *first = item.first, *second = item.second;
    long long cost = item.cost;
    if (!first || !second)
      continue;
    if (first->next != second)
      continue;
    if (first->val + second->val != cost)
      continue;
    cnt++;
    if (first->val > second->val)
      decrease_cnt--;
    struct node *prev_node = first->prev, *next_node = second->next;
    first->next = next_node;
    if (next_node)
      next_node->prev = first;
    second->prev = second->next = NULL;
    if (prev_node) {
      if (prev_node->val > first->val && prev_node->val <= cost)
        decrease_cnt--;
      if (prev_node->val <= first->val && prev_node->val > cost)
        decrease_cnt++;
      struct queue_item new_item;
      new_item.first = prev_node;
      new_item.second = first;
      new_item.cost = prev_node->val + cost;
      new_item.first_left = prev_node->left;
      new_item.second_left = first->left;
      queue_push(pq, &new_item);
    }
    if (next_node) {
      if (second->val > next_node->val && cost <= next_node->val)
        decrease_cnt--;
      if (second->val <= next_node->val && cost > next_node->val)
        decrease_cnt++;
      struct queue_item new_item;
      new_item.first = first;
      new_item.second = next_node;
      new_item.cost = cost + next_node->val;
      new_item.first_left = first->left;
      new_item.second_left = next_node->left;
      queue_push(pq, &new_item);
    }
    first->val = cost;
    merged[second->left] = true;
  }
  for (int i = 0; i < numsSize; i++)
    if (!merged[i])
      free(nodes[i]);
  free(nodes);
  free(merged);
  queue_free(pq);
  return cnt;
}

int main() {
  int n1[] = {5, 2, 3, 1}, n2[] = {1, 2, 2};
  printf("%d\n", minimumPairRemoval(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", minimumPairRemoval(n2, ARRAY_SIZE(n2))); // expect: 0
}
