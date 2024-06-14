// 703. Kth Largest Element in a Stream
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/*
 * design a class to find the k'th largest element in a stream. note that it is
 * the k'th largest element in the sorted order, not the k'th distinct element.
 * implement 'KthLargest' class:
 * - KthLargest(int k, int[] nums) initialises the objct with the integer 'k'
 * and the stream of integers 'nums' int add(int val) appends the integer 'val'
 * to the stream and returns the element representing the k'th largest stream
 * element
 */

typedef struct {
  int *min_heap;
  int size;
  int curr;
} KthLargest;

int cmp_func(const void *a, const void *b) { return *(int *)a - *(int *)b; }

KthLargest *kthLargestCreate(int k, int *nums, int nums_size) {
  if (nums_size)
    qsort(nums, nums_size, sizeof(int), cmp_func);
  KthLargest *res = malloc(sizeof(KthLargest));
  res->size = k;
  res->min_heap = malloc(k * sizeof(int));
  if (k <= nums_size) {
    memcpy(res->min_heap, &nums[nums_size - k], k * sizeof(int));
    res->curr = k;
  } else {
    for (int i = 0; i < k; i++) {
      if (i < nums_size)
        res->min_heap[i] = nums[i];
      else
        res->min_heap[i] = INT_MAX;
      res->curr = nums_size;
    }
  }
  return res;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int kthLargestAdd(KthLargest *obj, int val) {
  if (obj->curr < obj->size) {
    obj->min_heap[obj->curr] = val;
    int pos = obj->curr;
    obj->curr++;
    while (pos) {
      if (obj->min_heap[pos] < obj->min_heap[(pos - 1) / 2]) {
        swap(&obj->min_heap[pos], &obj->min_heap[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
      } else
        break;
    }
    if (obj->curr == obj->size)
      return obj->min_heap[0];
    else
      return -1;
  } else if (obj->curr == obj->size && val > obj->min_heap[0]) {
    obj->min_heap[0] = val;
    int idx = 0;
    while (2 * idx + 1 < obj->size && 2 * idx + 2 < obj->size) {
      if (obj->min_heap[2 * idx + 1] <= obj->min_heap[2 * idx + 1]) {
        if (obj->min_heap[idx] > obj->min_heap[2 * idx + 1]) {
          swap(&obj->min_heap[idx], &obj->min_heap[2 * idx + 1]);
          idx = 2 * idx + 1;
        } else
          break;
      } else {
        if (obj->min_heap[idx] > obj->min_heap[2 * idx + 2]) {
          swap(&obj->min_heap[idx], &obj->min_heap[2 * idx + 2]);
          idx = 2 * idx + 2;
        } else
          break;
      }
    }
    if (2 * idx + 1 < obj->size) {
      if (obj->min_heap[idx] > obj->min_heap[2 * idx + 1]) {
        swap(&obj->min_heap[idx], &obj->min_heap[2 * idx + 1]);
        idx = 2 * idx + 1;
      }
    }
  }
  return obj->min_heap[0];
}

void kthLargestFree(KthLargest *obj) {
  free(obj->min_heap);
  free(obj);
}

int main() {
  int k, nums[] = {}, nums_size, val;
  KthLargest *obj = kthLargestCreate(k, nums, nums_size);
  int param_1 = kthLargestAdd(obj, val);
  kthLargestFree(obj);
}
