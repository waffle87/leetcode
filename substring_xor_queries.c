// 2564. Substring XOR Queries
#include "leetcode.h"

/*
 * you are given a binary string 's' and a 2d integer array 'queries' where
 * 'queries[i] = [first_i, second_i]'. for the i'th query, find the shortest
 * substring of 's' whose decimal value 'val' yields 'second_i' when bitwise
 * xor'd with 'first_i'. in other words, 'val ^ first_i == second_i'. the answer
 * to the i'th query is the endpoints of the substring '[left_i, right_i]' or
 * '[-1, -1]' if no such substring exists. if there are multiple answers, choose
 * the one with the minimum 'left_i'. return an array 'ans' where 'ans[i] =
 * [left_i, right_i]' is the answer to the i'th query. a substring is a
 * contiguous non-empty sequence of characters within a string.
 */

struct hash {
  int key;
  struct hash *next;
  UT_hash_handle hh;
};

void resp(struct hash *entry, int idx, struct hash *entries, int **out) {
  int start = idx, end = idx, target = entry->key;
  while (target >>= 1)
    --start;
  do {
    int res = entry - entries;
    out[res][0] = start;
    out[res][1] = end;
  } while ((entry = entry->next));
}

int **substringXorQueries(char *s, int **queries, int queriesSize,
                          int *queriesColSize, int *returnSize,
                          int **returnColumnSizes) {
  int **ans = (int **)malloc(queriesSize * sizeof(int *));
  *returnColumnSizes = (int *)malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    ans[i] = (int *)malloc(2 * sizeof(int));
    (*returnColumnSizes)[i] = 2;
  }
  *returnSize = queriesSize;
  struct hash *table = NULL, *entry;
  struct hash *const entries =
      (struct hash *)malloc(queriesSize * sizeof(struct hash));
  for (int i = 0; i < queriesSize; ++i) {
    int target = queries[i][0] ^ queries[i][1];
    HASH_FIND_INT(table, &target, entry);
    if (!entry) {
      entries[i].key = target;
      entries[i].next = NULL;
      HASH_ADD_INT(table, key, &entries[i]);
    } else {
      entries[i].next = entry->next;
      entry->next = &entries[i];
    }
  }
  int arr[31], cnt = 0;
  for (int i = 0; s[i]; i++) {
    cnt = 30 == cnt ? 30 : cnt + 1;
    for (int j = cnt - 1; j; --j) {
      arr[j] = (arr[j - 1] << 1) + ('1' == s[i]);
      HASH_FIND_INT(table, &arr[j], entry);
      if (entry) {
        resp(entry, i, entries, ans);
        HASH_DEL(table, entry);
      }
    }
    arr[0] = ('1' == s[i]);
    HASH_FIND_INT(table, &arr[0], entry);
    if (entry) {
      resp(entry, i, entries, ans);
      HASH_DEL(table, entry);
    }
  }
  struct hash *tmp;
  HASH_ITER(hh, table, entry, tmp) {
    do {
      ans[entry - entries][0] = -1;
      ans[entry - entries][1] = -1;
    } while ((entry = entry->next));
  }
  HASH_CLEAR(hh, table);
  free(entries);
  return ans;
}

int main() {
  char *s1 = "101101", *s2 = "0101", *s3 = "1";
  int q1i[2][2] = {{0, 5}, {1, 2}}, q2i[1][2] = {{12, 8}}, q3i[1][2] = {{4, 5}};
  struct two_d_arr q1, q2, q3;
  two_d_arr_init(&q1, ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  two_d_arr_init(&q2, ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  two_d_arr_init(&q3, ARRAY_SIZE(q3i), ARRAY_SIZE(q3i[0]), q3i);
  int rs1, *rcs1,
      **sxq1 = substringXorQueries(s1, q1.arr, q1.row_size, q1.col_size, &rs1,
                                   &rcs1);
  int rs2, *rcs2,
      **sxq2 = substringXorQueries(s2, q2.arr, q2.row_size, q2.col_size, &rs2,
                                   &rcs2);
  int rs3, *rcs3,
      **sxq3 = substringXorQueries(s3, q3.arr, q3.row_size, q3.col_size, &rs3,
                                   &rcs3);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", sxq1[i][j]); // expect: [[0,2],[2,3]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", sxq2[i][j]); // expect: [[-1,-1]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    for (int j = 0; j < rcs3[i]; j++)
      printf("%d ", sxq1[i][j]); // expect: [[0,0]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(sxq1[i]);
  free(sxq1);
  for (int i = 0; i < rs2; i++)
    free(sxq2[i]);
  free(sxq1);
  for (int i = 0; i < rs3; i++)
    free(sxq3[i]);
  free(sxq3);
  free(rcs1);
  free(rcs2);
  free(rcs3);
  two_d_arr_free(&q1);
  two_d_arr_free(&q2);
  two_d_arr_free(&q3);
}
