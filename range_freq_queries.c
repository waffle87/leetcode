// 2080. Range Frequency Queries
#include "leetcode.h"

/*
 * design a data structure to find the frequency of a given value in a given
 * subarray. the frequency of a value in a subarray is the number of occurences
 * of that value in the subarray. implement the 'RangeFreqQuery' class:
 * 'rangeFreqQueryCreate(int[] arr)' constructs an instance of the class with
 * the given 0-indexed integer array 'arr'. 'int RangeFreqQuery(int left, int
 * right, int val)' returns the frequency of 'val' in the subarray 'arr[left ...
 * right]'. a subarray is contiguous sequence of elements within an array.
 * 'arr[left ... right]' denotes the subarray that contains the elements of
 * 'nums' between indices 'left' and 'right' inclusively
 */

typedef struct {
  int *a;
  int size;
} RangeFreqQuery;

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

RangeFreqQuery *rangeFreqQueryCreate(int *arr, int arrSize) {
  RangeFreqQuery *obj = (RangeFreqQuery *)calloc(1, sizeof(RangeFreqQuery));
  obj->size = arrSize + 1;
  obj->a = (int *)calloc(obj->size, sizeof(int));
  for (int i = 0; i < arrSize; i++)
    obj->a[i] = arr[i] << 17 | i;
  obj->a[arrSize] = 10001 << 17;
  qsort(obj->a, obj->size - 1, sizeof(int), cmp);
  return obj;
}

int bsearch1(int *a, int size, int target) {
  int l = 0, r = size - 1, m;
  while (l < r) {
    m = l + ((r - l) >> 1);
    if (a[m] < target)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int bsearch2(int *a, int size, int target) {
  int l = 0, r = size - 1, m;
  while (l < r) {
    m = l + ((r - l) >> 1);
    if (a[m] <= target)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int rangeFreqQueryQuery(RangeFreqQuery *obj, int left, int right, int value) {
  int l = bsearch1(obj->a, obj->size, value << 17 | left);
  int r = bsearch2(obj->a, obj->size, value << 17 | right);
  return r - l;
}

void rangeFreqQueryFree(RangeFreqQuery *obj) {
  free(obj->a);
  free(obj);
}

int main() {
  int arr[] = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
  RangeFreqQuery *obj = rangeFreqQueryCreate(arr, ARRAY_SIZE(arr));
  printf("%d\n", rangeFreqQueryQuery(obj, 1, 2, 4));   // expect: 1
  printf("%d\n", rangeFreqQueryQuery(obj, 0, 11, 33)); // expect: 2
  rangeFreqQueryFree(obj);
}
