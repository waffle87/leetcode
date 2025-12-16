// 3562. Maximum Profit from Trading Stocks with Discounts
#include "leetcode.h"

/*
 * you are given an integer 'n' representing the number of employees in a
 * company. each employee is assign a unique id from 1 to 'n', and employee 1 is
 * the ceo. you are given two integers arrays 'present' and 'future', each of
 * length 'n', where 'present[i]' represents the current price at which the i'th
 * employee can buy  stock today. 'future[i]' represents the expected price at
 * which the i'th employee can sell the stock tomorrow. the company's hierarchy
 * is represented by a 2d integer array 'hierarchy', where 'hierarchy[i] = [u_i,
 * v_i]' means that employee 'u_i' is the direct boss of employee can buy their
 * stock at half the original price. return the maximum profit that can be
 * achieve without exceeding the budget.
 */

struct data {
  int *arr;
  int size;
  int capacity;
};

void array_init(struct data *obj) {
  obj->capacity = 10;
  obj->size = 0;
  obj->arr = (int *)malloc(obj->capacity * sizeof(int));
}

void array_push(struct data *obj, int val) {
  if (obj->size >= obj->capacity) {
    obj->capacity *= 2;
    obj->arr = (int *)realloc(obj->arr, obj->capacity * sizeof(int));
  }
  obj->arr[obj->size++] = val;
}

void array_free(struct data *obj) { free(obj->arr); }

int **children, *children_cnt, *present, *future, global_budget, ***memo;

void dfs(int node, int parent_bought, int **dp_out, int *dp_size) {
  if (memo[node][parent_bought]) {
    *dp_out = memo[node][parent_bought];
    *dp_size = (global_budget + 1) * 2;
    return;
  }
  int *dp = (int *)malloc((global_budget + 1) * sizeof(int));
  for (int i = 0; i <= global_budget; i++)
    dp[i] = -1;
  dp[0] = 0;
  int cost = parent_bought ? present[node - 1] / 2 : present[node - 1];
  int profit = future[node - 1] - cost;
  if (!children_cnt[node]) {
    if (cost <= global_budget)
      dp[cost] = profit;
    memo[node][parent_bought] = dp;
    *dp_out = dp;
    *dp_size = global_budget + 1;
    return;
  }
  int **child_dp_not_bought =
      (int **)malloc(children_cnt[node] * sizeof(int *));
  int *child_dp_not_bought_size =
      (int *)malloc(children_cnt[node] * sizeof(int));
  for (int i = 0; i < children_cnt[node]; i++)
    dfs(children[node][i], 0, &child_dp_not_bought[i],
        &child_dp_not_bought_size[i]);
  int **child_dp_bought = (int **)malloc(children_cnt[node] * sizeof(int *));
  int *child_dp_bought_size = (int *)malloc(children_cnt[node] * sizeof(int));
  for (int i = 0; i < children_cnt[node]; i++)
    dfs(children[node][i], 1, &child_dp_bought[i], &child_dp_bought_size[i]);
  int *curr = (int *)malloc((global_budget + 1) * sizeof(int));
  for (int i = 0; i <= global_budget; i++)
    curr[i] = -1;
  curr[0] = 0;
  for (int i = 0; i < children_cnt[node]; i++) {
    int *next = (int *)malloc((global_budget + 1) * sizeof(int));
    for (int j = 0; j <= global_budget; j++)
      next[j] = -1;
    for (int b1 = 0; b1 <= global_budget; b1++) {
      if (curr[b1] == -1)
        continue;
      for (int b2 = 0; b2 <= global_budget - b1; b2++) {
        if (child_dp_not_bought[i][b2] == -1)
          continue;
        int total_budget = b1 + b2,
            total_profit = curr[b1] + child_dp_not_bought[i][b2];
        if (next[total_budget] < total_profit)
          next[total_budget] = total_profit;
      }
    }
    free(curr);
    curr = next;
  }
  for (int b = 0; b <= global_budget; b++)
    if (curr[b] > dp[b])
      dp[b] = curr[b];
  if (cost <= global_budget) {
    int *buying = (int *)malloc((global_budget + 1) * sizeof(int));
    for (int i = 0; i <= global_budget; i++)
      buying[i] = -1;
    buying[0] = 0;
    for (int i = 0; i < children_cnt[node]; i++) {
      int *next = (int *)malloc((global_budget + 1) * sizeof(int));
      for (int j = 0; j <= global_budget; j++)
        next[j] = -1;
      for (int b1 = 0; b1 <= global_budget - cost; b1++) {
        if (buying[b1] == -1)
          continue;
        for (int b2 = 0; b2 <= global_budget - cost - b1; b2++) {
          if (child_dp_bought[i][b2] == -1)
            continue;
          int total_budget = b1 + b2,
              total_profit = buying[b1] + child_dp_bought[i][b2];
          if (next[total_budget] < total_profit)
            next[total_budget] = total_profit;
        }
      }
      free(buying);
      buying = next;
    }
    for (int b = 0; b <= global_budget - cost; b++) {
      if (buying[b] != -1) {
        int total_budget = b + cost, total_profit = buying[b] + profit;
        if (dp[total_budget] < total_profit)
          dp[total_budget] = total_profit;
      }
    }
    free(buying);
  }
  free(curr);
  free(child_dp_not_bought);
  free(child_dp_not_bought_size);
  free(child_dp_bought);
  free(child_dp_bought_size);
  memo[node][parent_bought] = dp;
  *dp_out = dp;
  *dp_size = global_budget + 1;
}

int maxProfit(int n, int *presentArr, int presentSize, int *futureArr,
              int futureSize, int **hierarchy, int hierarchySize,
              int *hierarchyColSize, int budget) {
  present = presentArr;
  future = futureArr;
  global_budget = budget;
  children = (int **)malloc((n + 1) * sizeof(int *));
  children_cnt = (int *)calloc(n + 1, sizeof(int));
  for (int i = 0; i <= n; i++)
    children[i] = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < hierarchySize; i++) {
    int parent = hierarchy[i][0];
    int child = hierarchy[i][1];
    children[parent][children_cnt[parent]++] = child;
  }
  memo = (int ***)malloc((n + 1) * sizeof(int **));
  for (int i = 0; i <= n; i++)
    memo[i] = (int **)calloc(2, sizeof(int *));
  int *dp, dp_size, max_profit = 0;
  dfs(1, 0, &dp, &dp_size);
  for (int b = 0; b <= global_budget; b++)
    if (dp[b] > max_profit)
      max_profit = dp[b];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 2; j++)
      if (memo[i][j] != NULL)
        free(memo[i][j]);
    free(memo[i]);
    free(children[i]);
  }
  free(memo);
  free(children);
  free(children_cnt);
  return max_profit;
}

int main() {
  int p1[] = {1, 2}, f1[] = {4, 3}, h1i[1][2] = {{1, 2}};
  int p2[] = {3, 4}, f2[] = {5, 8}, h2i[1][2] = {{1, 2}};
  int p3[] = {4, 6, 8}, f3[] = {7, 9, 11}, h3i[2][2] = {{1, 2}, {1, 3}};
  struct two_d_arr *h1 =
      two_d_arr_init(ARRAY_SIZE(h1i), ARRAY_SIZE(h1i[0]), h1i);
  struct two_d_arr *h2 =
      two_d_arr_init(ARRAY_SIZE(h2i), ARRAY_SIZE(h2i[0]), h2i);
  struct two_d_arr *h3 =
      two_d_arr_init(ARRAY_SIZE(h3i), ARRAY_SIZE(h3i[0]), h3i);
  printf("%d\n", maxProfit(2, p1, ARRAY_SIZE(p1), f1, ARRAY_SIZE(f1), h1->arr,
                           h1->row_size, h1->col_size, 3)); // expect: 5
  printf("%d\n", maxProfit(2, p2, ARRAY_SIZE(p2), f2, ARRAY_SIZE(f2), h2->arr,
                           h2->row_size, h2->col_size, 4)); // expect: 4
  printf("%d\n", maxProfit(3, p3, ARRAY_SIZE(p3), f3, ARRAY_SIZE(f3), h3->arr,
                           h3->row_size, h3->col_size, 10)); // expect: 10
  two_d_arr_free(h1);
  two_d_arr_free(h2);
  two_d_arr_free(h3);
}
