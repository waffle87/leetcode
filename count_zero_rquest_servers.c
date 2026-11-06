// 2747. Count Zero Request Servers
#include "leetcode.h"

/*
 * you are given an integer 'n' denoting the total number of servers and a 2d
 * 0-indexed integer array 'logs' where 'logs[i] = [server_id, time]' denotes
 * that the server with id 'server_id' received a request at time 'time'. you
 * are also given an integer 'x' and a 0-indexed integer array 'queries'. return
 * a 0-indexed integer array 'arr' of length 'queries.len' where 'arr[i]'
 * represents the number of servers that did not receive any requests during the
 * time interval '[queries[i] - x, queries[i]]'. note that the time intervals
 * are inclusive.
 */

struct log_entry {
  int id;
  int time;
};

static int cmp_log(const void *a, const void *b) {
  const struct log_entry *aa = (const struct log_entry *)a;
  const struct log_entry *bb = (const struct log_entry *)b;
  if (aa->time < bb->time)
    return -1;
  if (aa->time > bb->time)
    return 1;
  return 0;
}

struct query_entry {
  int idx;
  int q;
};

static int cmp_query(const void *a, const void *b) {
  const struct query_entry *aa = (const struct query_entry *)a;
  const struct query_entry *bb = (const struct query_entry *)b;
  if (aa->q < bb->q)
    return -1;
  if (aa->q > bb->q)
    return 1;
  return 0;
}

int *countServers(int n, int **logs, int logsSize, int *logsColSize, int x,
                  int *queries, int queriesSize, int *returnSize) {
  struct log_entry *l_entries = (struct log_entry *)malloc(
      (logsSize > 0 ? logsSize : 1) * sizeof(struct log_entry));
  for (int i = 0; i < logsSize; i++) {
    l_entries[i].id = logs[i][0];
    l_entries[i].time = logs[i][1];
  }
  qsort(l_entries, logsSize, sizeof(struct log_entry), cmp_log);
  struct query_entry *q_entries =
      (struct query_entry *)malloc(queriesSize * sizeof(struct query_entry));
  for (int i = 0; i < queriesSize; i++) {
    q_entries[i].idx = i;
    q_entries[i].q = queries[i];
  }
  qsort(q_entries, queriesSize, sizeof(struct query_entry), cmp_query);
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  int *cnt = (int *)calloc(n + 1, sizeof(int));
  int left = 0, right = 0, active = 0;
  for (int k = 0; k < queriesSize; ++k) {
    int i = q_entries[k].idx;
    int q = q_entries[k].q;
    while (right < logsSize && l_entries[right].time <= q) {
      int id = l_entries[right++].id;
      if (!cnt[id])
        ++active;
    }
    while (left < right && l_entries[left].time < q - x) {
      int id = l_entries[left++].id;
      if (!--cnt[id])
        --active;
    }
    ans[i] = n - active;
  }
  free(l_entries);
  free(q_entries);
  free(cnt);
  *returnSize = queriesSize;
  return ans;
}

int main() {
  int l1i[3][2] = {{1, 3}, {2, 6}, {1, 5}};
  int l2i[4][2] = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
  struct two_d_arr *l1 =
      two_d_arr_init(ARRAY_SIZE(l1i), ARRAY_SIZE(l1i[0]), l1i);
  struct two_d_arr *l2 =
      two_d_arr_init(ARRAY_SIZE(l2i), ARRAY_SIZE(l2i[0]), l2i);
  int q1[] = {10, 11}, r1[] = {1, 2}, rs1;
  int q2[] = {3, 4}, r2[] = {3, 4}, rs2;
  int *cs1 = countServers(3, l1->arr, l1->row_size, l1->col_size, 5, q1,
                          ARRAY_SIZE(q1), &rs1);
  int *cs2 = countServers(3, l2->arr, l2->row_size, l2->col_size, 2, q2,
                          ARRAY_SIZE(q2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", cs1[i]);
    assert(cs1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", cs2[i]);
    assert(cs2[i] == r2[i]);
  }
  printf("\n");
  free(cs1);
  free(cs2);
  two_d_arr_free(l1);
  two_d_arr_free(l2);
}
