// 1352. Product of the Last K Numbers
#include "leetcode.h"

/*
 * design an algorithm that accepts a stream of integers and retrieves the
 * product of the last 'k' integers of the stream. implement the
 * 'ProductOfNumbers' class. the test cases are generated so that at any time,
 * the product of any contiguous sequence of numbers will fit into a single
 * 32-bit integer without overflowing.
 */

typedef struct {
  int *pre;
  int size;
  int capacity;
} ProductOfNumbers;

ProductOfNumbers *productOfNumbersCreate() {
  ProductOfNumbers *obj =
      (ProductOfNumbers *)calloc(1, sizeof(ProductOfNumbers));
  obj->pre = (int *)calloc(2, sizeof(int));
  obj->pre[0] = 1;
  obj->size = 1;
  obj->capacity = 2;
  return obj;
}

void productOfNumbersAdd(ProductOfNumbers *obj, int num) {
  if (obj->size == obj->capacity) {
    obj->capacity *= 2;
    obj->pre = (int *)realloc(obj->pre, obj->capacity * sizeof(int));
  }
  if (num) {
    int prev = obj->pre[obj->size - 1];
    obj->pre[obj->size++] = prev * num;
  } else {
    obj->size = 0;
    obj->capacity = 2;
    obj->pre = (int *)realloc(obj->pre, obj->capacity * sizeof(int));
    obj->pre[obj->size++] = 1;
  }
}

int productOfNumbersGetProduct(ProductOfNumbers *obj, int k) {
  return k < obj->size ? obj->pre[obj->size - 1] / obj->pre[obj->size - k - 1]
                       : 0;
}

void productOfNumbersFree(ProductOfNumbers *obj) {
  free(obj->pre);
  free(obj);
}

int main() {
  ProductOfNumbers *obj = productOfNumbersCreate();
  productOfNumbersAdd(obj, 3);
  productOfNumbersAdd(obj, 0);
  productOfNumbersAdd(obj, 2);
  productOfNumbersAdd(obj, 5);
  productOfNumbersAdd(obj, 4);
  int r1 = productOfNumbersGetProduct(obj, 2);
  int r2 = productOfNumbersGetProduct(obj, 3);
  int r3 = productOfNumbersGetProduct(obj, 4);
  printf("%d\n", r1);
  assert(r1 == 20);
  printf("%d\n", r2);
  assert(r2 == 40);
  printf("%d\n", r3);
  assert(r3 == 0);
  productOfNumbersAdd(obj, 8);
  int r4 = productOfNumbersGetProduct(obj, 2);
  printf("%d\n", r4);
  assert(r4 == 32);
  productOfNumbersFree(obj);
}
