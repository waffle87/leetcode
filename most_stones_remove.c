// 947. Most Stones Removed with Same Row or Column
#include "leetcode.h"

/*
 * on a 2d plane, we place 'n' stones at some integer coordinate points. each
 * coordinate point may have at most one stone. a stone can be removed if it
 * shares either the same row or the same column as another stone that has not
 * been removed. given an array 'stones' of length 'n' where 'stones[i] = [x_i,
 * y_i]' represents the location of the i'th stone, return the largest possible
 * number of stones that can be removed
 */

struct hash {
  struct hash *parent;
  UT_hash_handle set_hh;
  UT_hash_handle by_row_hh;
  UT_hash_handle by_col_hh;
};

struct hash *find_parent(struct hash *stone) {
  while (stone->parent)
    stone = stone->parent;
  return stone;
}

int removeStones(int **stones, int stonesSize, int *stonesColSize) {
  struct hash *set = NULL, *by_row = NULL, *by_col = NULL;
  struct hash *const entries = (struct hash *)malloc(sizeof(struct hash));
  for (int i = 0; i < stonesSize; i++) {
    struct hash *entry = &entries[i], *row_entry, *col_entry;
    HASH_FIND(by_row_hh, by_row, &stones[i][0], sizeof(stones[i][0]),
              row_entry);
    HASH_FIND(by_col_hh, by_col, &stones[i][1], sizeof(stones[i][1]),
              col_entry);
    if (row_entry && col_entry) {
      struct hash *row_parent = find_parent(row_entry);
      struct hash *col_parent = find_parent(col_entry);
      if (row_parent != col_parent) {
        col_parent->parent = row_parent;
        HASH_DELETE(set_hh, set, col_parent);
      }
      entry->parent = row_parent;
    } else if (row_entry) {
      entry->parent = row_entry;
      HASH_ADD_KEYPTR(by_col_hh, by_col, &stones[i][1], sizeof(stones[i][1]),
                      entry);
    } else if (col_entry) {
      entry->parent = col_entry;
      HASH_ADD_KEYPTR(by_row_hh, by_row, &stones[i][0], sizeof(stones[i][0]),
                      entry);
    } else {
      entry->parent = NULL;
      HASH_ADD_KEYPTR(set_hh, set, entry, sizeof(entry), entry);
      HASH_ADD_KEYPTR(by_row_hh, by_row, &stones[i][0], sizeof(stones[i][0]),
                      entry);
      HASH_ADD_KEYPTR(by_col_hh, by_col, &stones[i][1], sizeof(stones[i][1]),
                      entry);
    }
  }
  int ans = stonesSize - HASH_CNT(set_hh, set);
  HASH_CLEAR(set_hh, set);
  HASH_CLEAR(by_row_hh, by_row);
  HASH_CLEAR(by_col_hh, by_col);
  free(entries);
  return ans;
}

int main() {
  int s1[6][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}},
      s2[5][2] = {{0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 2}}, scs1 = 6, scs2 = 5;
  printf("%d\n", removeStones((int **)s1, ARRAY_SIZE(s1), &scs1)); // expect: 5
  printf("%d\n", removeStones((int **)s2, ARRAY_SIZE(s2), &scs2)); // expect: 3
}
