// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
#include "leetcode.h"

/*
 * you are given an array of integers 'arr' and an integer 'target'. you have to
 * find two non overlapping subarrays of 'arr' each with a sum equal to
 * 'target'. there can be multiple answers so you have to finmd an answer where
 * the sum of the lengths of the two subarrays is minimum. return the minimum
 * sum of the lengths of the two required subarrays or return -1 if you cannot
 * find such two subarrays.
 */

const int INT_NONE = 0x0BADC0DE;

struct window {
  int *ptr;
  size_t len;
  int target;
  size_t ptr_frnt;
  size_t ptr_back;
  int window_sum;
  int *res_ptr;
  size_t res_size;
};

struct window create_window(int *ptr, size_t len, int target) {
  size_t ptr_frnt = 0, ptr_back = 0, res_size = len + 1;
  int window_sum = 0, *res_ptr = (int *)calloc(res_size, sizeof(int));
  for (size_t i = 0; i < res_size; i++)
    res_ptr[i] = INT_NONE;
  struct window res = {
      .ptr = ptr,
      .len = len,
      .target = target,
      .ptr_frnt = ptr_frnt,
      .ptr_back = ptr_back,
      .window_sum = window_sum,
      .res_ptr = res_ptr,
      .res_size = res_size,
  };
  return res;
}

bool next_window(struct window *self) {
  if (self->ptr_frnt >= self->len)
    return false;
  if (self->window_sum > self->target) {
    int token_frnt = self->ptr[self->ptr_frnt];
    self->ptr_frnt += 1;
    self->window_sum -= token_frnt;
    return true;
  }
  if (self->ptr_back >= self->len)
    return false;
  int token_back = self->ptr[self->ptr_back];
  self->ptr_back += 1;
  self->window_sum += token_back;
  return true;
}

void log_window(struct window *self) {
  if (self->window_sum != self->target)
    return;
  self->res_ptr[self->ptr_back] = self->ptr_back - self->ptr_frnt;
}

void to_pref_min_vec(int *ptr, size_t len) {
  int pref_min = INT_NONE;
  for (size_t i = 0; i < len; i++) {
    if (ptr[i] < pref_min)
      pref_min = ptr[i];
    ptr[i] = pref_min;
  }
}

void to_rev_vec(int *ptr, size_t len) {
  for (size_t i = 0; i < len / 2; i++) {
    int t0 = ptr[i];
    ptr[i] = ptr[len - i - 1];
    ptr[len - i - 1] = t0;
  }
}

int minSumOfLengths(int *vec_ptr, int vec_len, int target) {
  struct window window_0 = create_window(vec_ptr, vec_len, target);
  while (next_window(&window_0))
    log_window(&window_0);
  int *res_0_ptr = window_0.res_ptr;
  size_t res_0_len = window_0.res_size;
  to_pref_min_vec(res_0_ptr, res_0_len);
  to_rev_vec(vec_ptr, vec_len);
  struct window window_1 = create_window(vec_ptr, vec_len, target);
  while (next_window(&window_1))
    log_window(&window_1);
  int *res_1_ptr = window_1.res_ptr;
  size_t res_1_len = window_1.res_size;
  to_pref_min_vec(res_1_ptr, res_1_len);
  to_rev_vec(res_1_ptr, res_1_len);
  int ans = INT_NONE;
  for (size_t bound = 0; bound < res_0_len; bound++) {
    int tmp = res_0_ptr[bound] + res_1_ptr[bound];
    if (tmp < ans)
      ans = tmp;
  }
  if (ans == INT_NONE)
    return -1;
  return ans;
}

int main() {
  int a1[] = {3, 2, 2, 4, 3}, a2[] = {7, 3, 4, 7}, a3[] = {4, 3, 2, 6, 2, 3, 4};
  printf("%d\n", minSumOfLengths(a1, ARRAY_SIZE(a1), 3)); // expect: 2
  printf("%d\n", minSumOfLengths(a2, ARRAY_SIZE(a2), 7)); // expect: 2
  printf("%d\n", minSumOfLengths(a3, ARRAY_SIZE(a3), 6)); // expect: -1
}
