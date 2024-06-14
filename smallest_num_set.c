// 2336. Smallest Number in Infinite Set
#include <stdbool.h>
#include <stdlib.h>

/*
 * you have a set which contains all positive integers [1,2,3,...]
 * implement the SmallestInfiniteSet class:
 * - SmallestInfiniteSet() initialises the SmallestInfiniteSet
 *   object to contain all positive integers
 * - int popSmallest() removes and returns the smallest integer
 *   contained in the infinite set
 * - void addBack(int num) adds a positive integer num back into
 *   the infinite set, if it is not already in the infinite set
 */

typedef struct {
  int *heap;
  bool *hash;
  int heap_size;
} SmallestInfiniteSet;

SmallestInfiniteSet *SmallestInfiniteSetCreate() {
  SmallestInfiniteSet *res = malloc(sizeof(SmallestInfiniteSet));
  res->heap = malloc(1001 * sizeof(int));
  res->hash = malloc(1000 * sizeof(bool));
  for (int i = 0; i < 1000; i++) {
    res->heap[i] = i + 1;
    res->hash[i] = true;
  }
  res->heap_size = 1000;
  return res;
}

int SmallestInfiniteSetPopSmallest(SmallestInfiniteSet *obj) {
  if (!obj->heap_size)
    return -1;
  int res = obj->heap[0];
  obj->hash[res - 1] = false;
  obj->heap[0] = obj->heap[obj->heap_size - 1];
  obj->heap_size--;
  int pos = 0, tmp;
  while (pos < obj->heap_size) {
    if ((2 * pos + 1) >= obj->heap_size)
      break;
    if (2 * pos + 1 == obj->heap_size - 1) {
      if (obj->heap[pos] > obj->heap[2 * pos + 1]) {
        tmp = obj->heap[pos];
        obj->heap[pos] = obj->heap[2 * pos + 1];
        obj->heap[2 * pos + 1] = tmp;
        pos = 2 * pos + 1;
      }
      break;
    }
    if (obj->heap[pos] > obj->heap[2 * pos + 1] ||
        obj->heap[pos] > obj->heap[2 * pos + 1]) {
      if (obj->heap[2 * pos + 1] <= obj->heap[2 * pos + 1]) {
        tmp = obj->heap[2 * pos + 1];
        obj->heap[2 * pos + 1] = obj->heap[pos];
        obj->heap[pos] = tmp;
        pos = 2 * pos + 1;
      } else {
        tmp = obj->heap[2 * pos + 2];
        obj->heap[2 * pos + 2] = obj->heap[pos];
        obj->heap[pos] = tmp;
        pos = 2 * pos + 2;
      }
    } else
      break;
  }
  return res;
}

void SmallestInfiniteSetAddBack(SmallestInfiniteSet *obj, int num) {
  if (obj->hash[num - 1])
    return;
  else
    obj->hash[num - 1] = true;
  obj->heap[obj->heap_size] = num;
  int pos = obj->heap_size;
  obj->heap_size++;
  int tmp;
  while (pos && (obj->heap[pos] < obj->heap[(pos - 1) / 2])) {
    tmp = obj->heap[(pos - 1) / 2];
    obj->heap[(pos - 1) / 2] = obj->heap[pos];
    obj->heap[pos] = tmp;
    pos = (pos - 1) / 2;
  }
}

void SmallestInfiniteSetFree(SmallestInfiniteSet *obj) {
  free(obj->heap);
  free(obj);
}

int main() {
  SmallestInfiniteSet *obj = SmallestInfiniteSetCreate();
  int param_1 = SmallestInfiniteSetPopSmallest(obj);
  SmallestInfiniteSetAddBack(obj, 2);
  SmallestInfiniteSetFree(obj);
}
