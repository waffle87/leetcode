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
  printf("%d\n", productOfNumbersGetProduct(obj, 2)); // expect: 20
  printf("%d\n", productOfNumbersGetProduct(obj, 3)); // expect: 40
  printf("%d\n", productOfNumbersGetProduct(obj, 4)); // expect: 0
  productOfNumbersAdd(obj, 8);
  printf("%d\n", productOfNumbersGetProduct(obj, 2)); // expect: 32
  productOfNumbersFree(obj);
}
