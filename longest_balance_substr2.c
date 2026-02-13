// 3714. Longest Balanced Substring II
#include "leetcode.h"

/*
 * you are given a string 's' consisting only of the characters a, b, and c. a
 * substring of 's' is called balanced if all distinct characters in the
 * substring appear the same number of times. return the length of the longest
 * balance substring of 's'.
 */

#define HASH_SIZE 1000003

struct hash_entry {
  long long key;
  int val;
  int used;
};

static inline int get_idx(struct hash_entry *table, long long key) {
  unsigned long long hash = (unsigned long long)key;
  hash ^= (hash >> 17);
  hash ^= (hash >> 11);
  unsigned int idx = hash % HASH_SIZE;
  while (table[idx].used) {
    if (table[idx].key == key)
      return idx;
    idx++;
    if (idx == HASH_SIZE)
      idx = 0;
  }
  return idx;
}

static inline void insert_map(struct hash_entry *table, long long key,
                              int val) {
  int hash = get_idx(table, key);
  if (!table[hash].used) {
    table[hash].key = key;
    table[hash].val = val;
    table[hash].used = 1;
  }
}

static inline int query_map(struct hash_entry *table, long long key) {
  int hash = get_idx(table, key);
  if (table[hash].used)
    return table[hash].val;
  return -2;
}

int solve_pair(char *s, int n, int c1, int c2, char block, int *pos,
               int *modified) {
  int max_len = 0, mod_cnt = 0, offset = n, diff = 0;
  for (int k = 0; k <= 2 * n; k++)
    pos[k] = -2;
  pos[0 + offset] = -1;
  modified[mod_cnt++] = 0 + offset;
  for (int i = 0; i < n; i++) {
    if (s[i] == block) {
      diff = 0;
      while (mod_cnt > 0)
        pos[modified[--mod_cnt]] = -2;
      pos[0 + offset] = i;
      modified[mod_cnt++] = 0 + offset;
    } else {
      if (s[i] == c1)
        diff++;
      else if (s[i] == c2)
        diff--;
      int idx = diff + offset;
      if (pos[idx] != -2) {
        int curr_len = i - pos[idx];
        max_len = fmax(max_len, curr_len);
      } else {
        pos[idx] = i;
        modified[mod_cnt++] = idx;
      }
    }
  }
  return max_len;
}

int longestBalanced(char *s) {
  int n = strlen(s), ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i] == s[i - 1])
      cnt++;
    else
      cnt = 1;
    ans = fmax(ans, cnt);
  }
  int *pos = (int *)malloc((2 * n + 1) * sizeof(int));
  int *modified = (int *)malloc((n + 1) * sizeof(int));
  int res = solve_pair(s, n, 'a', 'b', 'c', pos, modified);
  ans = fmax(ans, res);
  res = solve_pair(s, n, 'a', 'c', 'b', pos, modified);
  ans = fmax(ans, res);
  res = solve_pair(s, n, 'b', 'c', 'a', pos, modified);
  ans = fmax(ans, res);
  free(pos);
  free(modified);
  struct hash_entry *map =
      (struct hash_entry *)calloc(HASH_SIZE, sizeof(struct hash_entry));
  insert_map(map, 0, -1);
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
    case 'a':
      a++;
      break;
    case 'b':
      b++;
      break;
    case 'c':
      c++;
      break;
    }
    long long key = ((unsigned long long)(unsigned int)(a - b) << 32) |
                    (unsigned int)(b - c);
    int prev_idx = query_map(map, key);
    if (prev_idx != -2) {
      int curr = i - prev_idx;
      ans = fmax(ans, curr);
    } else
      insert_map(map, key, i);
  }
  free(map);
  return ans;
}

int main() {
  char *s1 = "abbac", *s2 = "aabcc", *s3 = "aba";
  int r1 = longestBalanced(s1);
  int r2 = longestBalanced(s2);
  int r3 = longestBalanced(s3);
  printf("%d\n", r1); // expect: 4
  assert(r1 == 4);
  printf("%d\n", r2); // expect: 3
  assert(r2 == 3);
  printf("%d\n", r3); // expect: 2
  assert(r3 == 2);
}
