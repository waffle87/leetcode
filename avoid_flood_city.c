// 1488. Avoid Flood in The City
#include "leetcode.h"

/*
 * your country has an infinite number of lakes. initially, all the lakes are
 * empty. but when it rains over the n'th lake, the n'th lake becomes full of
 * water. if it rains over a lake that is full of water, there will be a flood.
 * your goal is to avoid any floods. if there are multiple valid answers, return
 * any of them. if it is impossible to avoid flood, return an empty array.
 * notice that if yo uchose to dry a full lake, it becomes empty. but if you
 * chose to dry an empty lake, nothing happens.
 */

#define HASH_SIZE 200003

struct hash_entry {
  int key;
  int val;
  bool used;
};

int hash_func(int key) {
  if (key < 0)
    key = -key;
  return key % HASH_SIZE;
}

int *hash_get(struct hash_entry *obj, int key) {
  int hash = hash_func(key);
  while (obj[hash].used) {
    if (obj[hash].key == key)
      return &obj[hash].val;
    hash++;
    if (hash == HASH_SIZE)
      hash = 0;
  }
  return NULL;
}

int *hash_put(struct hash_entry *obj, int key, int val) {
  int hash = hash_func(key);
  while (obj[hash].used) {
    if (obj[hash].key == key) {
      obj[hash].val = val;
      return &obj[hash].val;
    }
    hash++;
    if (hash == HASH_SIZE)
      hash = 0;
  }
  obj[hash].used = true;
  obj[hash].key = key;
  obj[hash].val = val;
  return &obj[hash].val;
}

int dry_day(int *dry_days, int dry_cnt, int target) {
  int low = 0, high = dry_cnt - 1, res = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (dry_days[mid] > target) {
      res = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  return res;
}

int *avoidFlood(int *rains, int rainsSize, int *returnSize) {
  *returnSize = rainsSize;
  int *ans = (int *)malloc(rainsSize * sizeof(int));
  int *dry = (int *)malloc(rainsSize * sizeof(int));
  int dry_cnt = 0;
  struct hash_entry *hash_table =
      (struct hash_entry *)calloc(HASH_SIZE, sizeof(struct hash_entry));
  for (int i = 0; i < rainsSize; i++) {
    if (!rains[i]) {
      dry[dry_cnt++] = i;
      ans[i] = 1;
    } else {
      int *prev = hash_get(hash_table, rains[i]);
      if (prev) {
        int idx = dry_day(dry, dry_cnt, *prev);
        if (idx == -1) {
          free(ans);
          free(dry);
          free(hash_table);
          *returnSize = 0;
          return NULL;
        }
        int day = dry[idx];
        ans[day] = rains[i];
        memmove(dry + idx, dry + idx + 1, (dry_cnt - idx - 1) * sizeof(int));
        dry_cnt--;
      }
      hash_put(hash_table, rains[i], i);
      ans[i] = -1;
    }
  }
  free(dry);
  free(hash_table);
  return ans;
}

int main() {
  int r1[] = {1, 2, 3, 4}, r2[] = {1, 2, 0, 0, 2, 1}, r3[] = {1, 2, 0, 1, 2};
  int rs1, *af1 = avoidFlood(r1, ARRAY_SIZE(r1), &rs1);
  int rs2, *af2 = avoidFlood(r2, ARRAY_SIZE(r2), &rs2);
  int rs3, *af3 = avoidFlood(r3, ARRAY_SIZE(r3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", af1[i]); // expect: -1 -1 -1 -1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", af2[i]); // expect:  -1 -1 2 1 -1 -1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", af3[i]); // expect: null
  printf("\n");
  free(af1);
  free(af2);
  free(af3);
}
