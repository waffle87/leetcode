// 2561. Rearranging Fruits
#include "leetcode.h"

/*
 * you have two fruit baskests containing 'n' fruits each. you are given two
 * indexed integer arrays 'basket1' and 'basket2' representing the cost of fruit
 * in each baset. you want o make both baskets equal. to do so, you can use the
 * following operation as many times as you want: chose two indices 'i' and 'j'
 * and swap the i'th fruit of 'basket1' with the j'th fruit of 'basket2'. the
 * cost of the swap is 'min(basket1[i], basket2[j])'. two baskets are considered
 * equal if sorting them according to the fruit cost makes them exactly the same
 * baksets. return the minimum cost to make both baskets equal or -1 if
 * impossible.
 */

struct map_entry {
  int key;
  int val;
};

struct map {
  struct map_entry *entries;
  int size;
  int capacity;
};

void map_init(struct map *obj) {
  obj->capacity = 16;
  obj->size = 0;
  obj->entries =
      (struct map_entry *)malloc(obj->capacity * sizeof(struct map_entry));
}

void map_insert(struct map *obj, int key, int delta) {
  for (int i = 0; i < obj->size; i++)
    if (obj->entries[i].key == key) {
      obj->entries[i].val += delta;
      return;
    }
  if (obj->size == obj->capacity) {
    obj->capacity *= 2;
    obj->entries = (struct map_entry *)realloc(
        obj->entries, obj->capacity * sizeof(struct map_entry));
  }
  obj->entries[obj->size].key = key;
  obj->entries[obj->size].val = delta;
  obj->size++;
}

int cmp(const void *a, const void *b) {
  struct map_entry *aa = (struct map_entry *)a;
  struct map_entry *bb = (struct map_entry *)b;
  return aa->key - bb->key;
}

void map_sort(struct map *obj) {
  qsort(obj->entries, obj->size, sizeof(struct map_entry), cmp);
}

long long minCost(int *basket1, int basket1Size, int *basket2,
                  int basket2Size) {
  long long ans = 0;
  struct map map;
  map_init(&map);
  for (int i = 0; i < basket1Size; i++) {
    map_insert(&map, basket1[i], 1);
    map_insert(&map, basket2[i], -1);
  }
  map_sort(&map);
  if (!map.size)
    return 0;
  int m = map.entries[0].key;
  int *arr = NULL, arr_size = 0, arr_capacity = 0;
  for (int i = 0; i < map.size; i++) {
    int val = map.entries[i].key, key = map.entries[i].val;
    if (key % 2) {
      free(map.entries);
      if (arr)
        free(arr);
      return -1;
    }
    int cnt = abs(key) / 2;
    for (int j = 0; j < cnt; j++) {
      if (arr_size == arr_capacity) {
        arr_capacity = !arr_capacity ? 1 : arr_capacity * 2;
        arr = (int *)realloc(arr, arr_capacity * sizeof(int));
      }
      arr[arr_size++] = val;
    }
  }
  for (int i = 0; i < arr_size / 2; i++)
    ans += (arr[i] < 2 * m) ? arr[i] : 2 * m;
  free(map.entries), free(arr);
  return ans;
}

int main() {
  int b11[] = {4, 2, 2, 2}, b21[] = {1, 4, 1, 2};
  int b12[] = {2, 3, 4, 1}, b22[] = {3, 2, 5, 1};
  printf("%lld\n",
         minCost(b11, ARRAY_SIZE(b11), b21, ARRAY_SIZE(b21))); // expect: 1
  printf("%lld\n",
         minCost(b12, ARRAY_SIZE(b12), b22, ARRAY_SIZE(b22))); // expect: -1
}
