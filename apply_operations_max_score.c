// 2818. Apply Operations to Maximize Score
#include "leetcode.h"

/*
 * you are given an array 'nums' of 'n' positive integers and an integer 'k'.
 * initially, you start with a score of 1. you have to maxmise your score by
 * applying the following operation at most 'k' times: chose any non-empty
 * element 'x' of 'nums[l .. r]' with the highest prime score. if multiple such
 * elements exist, choose the one with the smallest index. multiple your score
 * 'x'. return the maximum possible score after applying at most 'k' operations.
 * since the answer may be very large, return it module '10e9+7'
 */

static int mod = 1e9 + 7, *vals;

void prime_score(int *score, int upper) {
  memset(score, 0, upper * sizeof(int));
  for (int i = 2; i < upper; i++)
    if (!score[i])
      for (int j = i; j < upper; j += i)
        score[j] += 1;
}

long long mod_pow(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp) {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

int cmp(const void *a, const void *b) {
  return vals[*(int *)b] - vals[*(int *)a];
}

int maximumScore(int *nums, int n, int k) {
  int upper = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > upper)
      upper = nums[i];
  }
  upper++;
  int *score = (int *)malloc(upper * sizeof(int));
  int *next = (int *)malloc(n * sizeof(int));
  int *prev = (int *)malloc(n * sizeof(int));
  int *stack = (int *)malloc(n * sizeof(int));
  prime_score(score, upper);
  int top = -1, ans = 1;
  for (int i = 0; i < n; i++) {
    while (top >= 0 && score[nums[i]] > score[nums[stack[top]]])
      top--;
    prev[i] = (top >= 0) ? stack[top] : -1;
    stack[++top] = i;
  }
  top = -1;
  for (int i = n - 1; i >= 0; i--) {
    while (top >= 0 && score[nums[i]] >= score[nums[stack[top]]])
      top--;
    next[i] = (top >= 0) ? stack[top] : n;
    stack[++top] = i;
  }
  int *indices = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    indices[i] = i;
  vals = nums;
  qsort(indices, n, sizeof(int), cmp);
  for (int i = 0; i < n && k > 0; i++) {
    int idx = indices[i], num = nums[idx];
    long long operations = (long long)(idx - prev[idx]) * (next[idx] - idx);
    if (operations > k)
      operations = k;
    ans = (ans * mod_pow(num, operations, mod)) % mod;
    k -= operations;
    if (!k)
      break;
  }
  free(score);
  free(next);
  free(prev);
  free(stack);
  free(indices);
  return ans;
}

int main() {
  int n1[] = {8, 3, 9, 3, 8}, n2[] = {19, 12, 14, 6, 10, 18};
  printf("%d\n", maximumScore(n1, ARRAY_SIZE(n1), 2)); // expect: 81
  printf("%d\n", maximumScore(n2, ARRAY_SIZE(n2), 3)); // expect: 4788
}
