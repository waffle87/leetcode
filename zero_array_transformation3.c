// 3362. Zero Array Transformation III
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and a 2d array 'queries'
 * where 'queries[i] = [li, ri]'. each 'queries[i]' represents the following
 * action on 'nums': decrement the value at each index in the range '[li, ri]'
 * in 'nums' by at most 1. the amount by which the value is decremented can be
 * chosen independently for each index. a zero array is an array with all its
 * elements equal to 0. return the maximum number of elements that can be
 * removed from 'queries' such that 'nums' can still be converted to a zero
 * array using the remaining queries. if it is not possible to convert 'nums' to
 * a zero array, return -1.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  return aa[0] - bb[0];
}

struct heap {
  int *data;
  int cap;
  int size;
};

struct heap *heap_create(int cap) {
  struct heap *obj = (struct heap *)malloc(sizeof(struct heap));
  obj->data = (int *)malloc(cap * sizeof(int));
  obj->cap = cap;
  obj->size = 0;
  return obj;
}

void heap_free(struct heap *obj) {
  free(obj->data);
  free(obj);
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heap_up(struct heap *obj, int idx) {
  while (idx > 0 && obj->data[(idx - 1) / 2] < obj->data[idx]) {
    swap(&obj->data[(idx - 1) / 2], &obj->data[idx]);
    idx = (idx - 1) / 2;
  }
}

void heap_down(struct heap *obj, int idx) {
  int max = idx, left = 2 * idx + 1, right = 2 * idx + 2;
  if (left < obj->size && obj->data[left] > obj->data[max])
    max = left;
  if (right < obj->size && obj->data[right] > obj->data[max])
    max = right;
  if (max != idx) {
    swap(&obj->data[idx], &obj->data[max]);
    heap_down(obj, max);
  }
}

void heap_push(struct heap *obj, int val) {
  if (obj->size == obj->cap)
    return;
  obj->data[obj->size++] = val;
  heap_up(obj, obj->size - 1);
}

int heap_pop(struct heap *obj) {
  if (!obj->size)
    return -1;
  int max = obj->data[0];
  obj->data[0] = obj->data[--obj->size];
  heap_down(obj, 0);
  return max;
}

int heap_top(struct heap *obj) {
  if (!obj->size)
    return -1;
  return obj->data[0];
}

int maxRemoval(int *nums, int numsSize, int **queries, int queriesSize,
               int *queriesColSize) {
  qsort(queries, queriesSize, sizeof(int *), cmp);
  struct heap *heap = heap_create(queriesSize);
  int *end = (int *)calloc(numsSize + 1, sizeof(int));
  int curr = 0, j = 0;
  for (int i = 0; i < numsSize; ++i) {
    curr -= end[i];
    while (j < queriesSize && queries[j][0] <= i)
      heap_push(heap, queries[j++][1]);
    while (curr < nums[i]) {
      if (!heap->size || heap_top(heap) < i) {
        heap_free(heap);
        free(end);
        return -1;
      }
      int top = heap_top(heap);
      end[top + 1]++;
      heap_pop(heap);
      curr++;
    }
  }
  int ans = heap->size;
  heap_free(heap);
  free(end);
  return ans;
}

int main() {
  int n1[] = {2, 0, 2}, q1i[3][2] = {{0, 2}, {0, 2}, {1, 1}};
  int n2[] = {1, 1, 1, 1}, q2i[4][2] = {{1, 3}, {0, 2}, {1, 3}, {1, 2}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  printf("%d\n", maxRemoval(n1, ARRAY_SIZE(n1), q1->arr, q1->row_size,
                            q1->col_size)); // expect: 2
  printf("%d\n", maxRemoval(n2, ARRAY_SIZE(n2), q2->arr, q2->row_size,
                            q2->col_size)); // expect: 1
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
