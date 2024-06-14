// 706. Design HashMap
#include <stdio.h>
#include <stdlib.h>

/*
 * design a hashmap without usin any built-in hash table libraries. implement
 * the 'MyHashMap' class:
 * - myHashMapCreate() initialises the object with an empty map
 * - put() inserts a key, value pair into the hashmap. if the key already exists
 * in the map, update the corresponding value
 * - get() returns the value to which the specified key is mapped, or -1 if this
 * map contains no mapping for the key
 * - remove() removes the key and its corresponding value if the map contains
 * the mapping for the key
 */

typedef struct {
  int **map;
  int size;
} MyHashMap;

MyHashMap *myHashMapCreate() {
  MyHashMap *res = malloc(sizeof(MyHashMap));
  res->size = 10000;
  res->map = calloc((res->size), sizeof(int *));
  return res;
}

void myHashMapPut(MyHashMap *obj, int key, int val) {
  int d = key, n = obj->size;
  while (1) {
    if (!obj->map[d % n]) {
      obj->map[d % n] = malloc(2 * sizeof(int));
      obj->map[d % n][0] = key;
      obj->map[d % n][1] = val;
      break;
    } else if (obj->map[d % n][0] == key) {
      obj->map[d % n][1] = val;
      break;
    } else {
      d++;
    }
  }
}

int myHashMapGet(MyHashMap *obj, int key) {
  int d = key, n = obj->size;
  while (1) {
    if (!obj->map[d % n])
      return -1;
    else if (obj->map[d % n][0] == key)
      return obj->map[d % n][1];
    else
      d++;
  }
  return -1;
}

void myHashMapRemove(MyHashMap *obj, int key) {
  int d = key, n = obj->size;
  while (1) {
    if (!obj->map[d % n])
      break;
    else if (obj->map[d % n][0] == key) {
      obj->map[d % n][0] = -1;
      break;
    } else {
      d++;
    }
  }
}

void myHashMapFree(MyHashMap *obj) {
  int n = obj->size;
  for (int i = 0; i < n; i++)
    if (obj->map[i])
      free(obj->map[i]);
  free(obj->map);
  free(obj);
}

int main() {
  MyHashMap *obj = myHashMapCreate();
  myHashMapPut(obj, 1, 1);
  myHashMapPut(obj, 2, 2);
  printf("%d\n", myHashMapGet(obj, 1)); // expect: 1
  printf("%d\n", myHashMapGet(obj, 3)); // expect: -1
  myHashMapPut(obj, 2, 1);
  printf("%d\n", myHashMapGet(obj, 2)); // expect: 1
  myHashMapRemove(obj, 2);
  printf("%d\n", myHashMapGet(obj, 2)); // expect: -1
}
