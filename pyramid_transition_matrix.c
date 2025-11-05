// 756. Pyramid Transition Matrix
#include "leetcode.h"

/*
 * you are stacking blocks to form a pyramid. each block has a colour which is
 * represented by a single letter. each row of blocks contains one less block
 * than the row beneat it and is centered on top. to make the pyramid
 * aesthetically pleasing, there are only specific triangular patterns that are
 * allowed. a triangular pattern consists of a single block stacked on top of
 * two blocks. the patterns are given as a list of three letter strings
 * 'allowed', where the first two characters of a pattern represent the third
 * character is the top block. you start with a bottom row of blocks 'bottom',
 * given as a string, that you must use as the base of the pyramid. given
 * 'bottom' and 'allowed', return 'true' if you can build the pyramid all the
 * way to the top such that every triangular pattern in the pyramid is in
 * 'allowed', or false otherwise.
 */

struct map_ent {
  char key[3];
  char *vals;
  int cnt;
  int capacity;
};

struct hashmap {
  struct map_ent *entries;
  int size;
  int capacity;
};

struct hashmap *hashmap_init(int capacity) {
  struct hashmap *obj = (struct hashmap *)malloc(sizeof(struct hashmap));
  obj->entries = (struct map_ent *)calloc(capacity, sizeof(struct map_ent));
  obj->size = 0;
  obj->capacity = capacity;
  return obj;
}

void hashmap_free(struct hashmap *obj) {
  for (int i = 0; i < obj->size; i++)
    if (obj->entries[i].vals)
      free(obj->entries[i].vals);
  free(obj->entries);
  free(obj);
}

void hashmap_push(struct hashmap *obj, const char *key, char val) {
  for (int i = 0; i < obj->size; i++)
    if (!strcmp(obj->entries[i].key, key)) {
      if (obj->entries[i].cnt >= obj->entries[i].capacity) {
        obj->entries[i].capacity =
            !obj->entries[i].capacity ? 4 : obj->entries[i].capacity * 2;
        obj->entries[i].vals = (char *)realloc(
            obj->entries[i].vals, obj->entries[i].capacity * sizeof(char));
      }
      obj->entries[i].vals[obj->entries[i].cnt++] = val;
      return;
    }
  if (obj->size >= obj->capacity) {
    obj->capacity *= 2;
    obj->entries = (struct map_ent *)realloc(
        obj->entries, obj->capacity * sizeof(struct map_ent));
  }
  struct map_ent *entry = &obj->entries[obj->size];
  strcpy(entry->key, key);
  entry->vals = NULL;
  entry->cnt = 0;
  entry->capacity = 0;
  if (!entry->capacity) {
    entry->capacity = 4;
    entry->vals = (char *)malloc(entry->capacity * sizeof(char));
  }
  entry->vals[entry->cnt++] = val;
  obj->size++;
}

char *hashmap_get(struct hashmap *obj, const char *key, int *cnt) {
  for (int i = 0; i < obj->size; i++)
    if (!strcmp(obj->entries[i].key, key)) {
      *cnt = obj->entries[i].cnt;
      return obj->entries[i].vals;
    }
  *cnt = 0;
  return NULL;
}

bool helper(char *bottom, struct hashmap *m, int start, char *next, int n) {
  if (strlen(bottom) == 1)
    return true;
  if (start == (int)strlen(bottom) - 1) {
    next[n] = '\0';
    return helper(next, m, 0, (char *)malloc(strlen(next) + 1), 0);
  }
  char key[3];
  key[0] = bottom[start];
  key[1] = bottom[start + 1];
  key[2] = '\0';
  int cnt;
  char *vals = hashmap_get(m, key, &cnt);
  if (!vals)
    return false;
  for (int i = 0; i < cnt; i++) {
    next[n] = vals[i];
    if (helper(bottom, m, start + 1, next, n + 1))
      return true;
  }
  return false;
}

bool pyramidTransition(char *bottom, char **allowed, int allowedSize) {
  struct hashmap *m = hashmap_init(100);
  for (int i = 0; i < allowedSize; i++) {
    char key[3];
    key[0] = allowed[i][0];
    key[1] = allowed[i][1];
    key[2] = '\0';
    char val = allowed[i][2];
    hashmap_push(m, key, val);
  }
  int n = strlen(bottom);
  char *next = (char *)malloc(n);
  bool ans = helper(bottom, m, 0, next, 0);
  free(next);
  hashmap_free(m);
  return ans;
}

int main() {
  char *b1 = "BCD", *a1[] = {"BCC", "CDE", "CEA", "FFF"};
  char *b2 = "AAAA", *a2[] = {"AAB", "AAC", "BCD", "BBE", "DEF"};
  printf("%d\n", pyramidTransition(b1, a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", pyramidTransition(b2, a2, ARRAY_SIZE(a2))); // expect: 0
}
