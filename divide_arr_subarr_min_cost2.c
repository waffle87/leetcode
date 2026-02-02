// 3013. Divide an Array Into Subarrays With Minimum Cost II
#include "leetcode.h"

/*
 * you are given a 0 indexed array of integers 'nums' of length 'n', and two
 positive integers 'k' and 'dist'. the cost of an array is the value of its
 first element. for example, the cost of '1,2,3' is 1. you need to divide 'nums'
 into 'k' disjoint contiguous subarrays, such that the difference between the
 starting index of the second subarray and the starting index of the k'th
 subarray should be less than or equal to 'dist'. in other words, if you divide
 'nums' into the subarrays, then 'i_k-1 - i_1 <= dist'. return the minimum
 possible sum of the cost of these subarrays.
 */

struct element {
  int val;
};

int cmp(const void *a, const void *b) {
  return ((struct element *)a)->val - ((struct element *)b)->val;
}

void update(int *bit_cnt, long long *bit_sum, int max_rank, int idx, int cnt,
            long long val) {
  while (idx <= max_rank) {
    bit_cnt[idx] += cnt;
    bit_sum[idx] += val;
    idx += idx & (-idx);
  }
}

long long query_k_smallest(int *bit_cnt, long long *bit_sum, int max_rank,
                           int k, int *rank_val) {
  int idx = 0, curr_cnt = 0;
  for (int i = 1 << 17; i > 0; i >>= 1)
    if (idx + i <= max_rank && curr_cnt + bit_cnt[idx + i] < k) {
      idx += i;
      curr_cnt += bit_cnt[idx];
    }
  int target = idx + 1, tmp = target;
  long long sum = 0;
  while (tmp > 0) {
    sum += bit_sum[tmp];
    tmp -= tmp & (-tmp);
  }
  tmp = target;
  int cnt_target = 0;
  while (tmp > 0) {
    cnt_target += bit_cnt[tmp];
    tmp -= tmp & (-tmp);
  }
  int exc = cnt_target - k;
  if (exc > 0)
    sum -= (long long)exc * rank_val[target];
  return sum;
}

int get_rank(int val, int *unique_vals, int unique_size) {
  int l = 0, r = unique_size - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (unique_vals[m] == val)
      return m + 1;
    else if (unique_vals[m] < val)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

long long minimumCost(int *nums, int numsSize, int k, int dist) {
  int target = k - 1;
  struct element *tmp =
      (struct element *)malloc(numsSize * sizeof(struct element));
  for (int i = 1; i < numsSize; i++)
    tmp[i - 1].val = nums[i];
  qsort(tmp, numsSize - 1, sizeof(struct element), cmp);
  int *unique_vals = (int *)malloc(numsSize * sizeof(int));
  int u_ptr = 0;
  if (numsSize > 1) {
    unique_vals[u_ptr++] = tmp[0].val;
    for (int i = 1; i < numsSize - 1; i++)
      if (tmp[i].val != tmp[i - 1].val)
        unique_vals[u_ptr++] = tmp[i].val;
  }
  int max_rank = u_ptr;
  int *rank_lut = (int *)malloc((max_rank + 2) * sizeof(int));
  for (int i = 0; i < max_rank; i++)
    rank_lut[i + 1] = unique_vals[i];
  int *bit_cnt = (int *)calloc(max_rank + 2, sizeof(int));
  long long *bit_sum = (long long *)calloc(max_rank + 2, sizeof(long long));
  int lim = (dist + 1 < numsSize - 1) ? dist + 1 : numsSize - 1;
  int curr_window = 0;
  for (int i = 1; i <= lim; i++) {
    int r = get_rank(nums[i], unique_vals, max_rank);
    update(bit_cnt, bit_sum, max_rank, r, 1, nums[i]);
    curr_window++;
  }
  long long min_cost = -1;
  if (curr_window >= target)
    min_cost = query_k_smallest(bit_cnt, bit_sum, max_rank, target, rank_lut);
  for (int i = 2; i < numsSize; i++) {
    int out_r = get_rank(nums[i - 1], unique_vals, max_rank);
    update(bit_cnt, bit_sum, max_rank, out_r, -1, -nums[i - 1]);
    curr_window--;

    if (i + dist < numsSize) {
      int in_r = get_rank(nums[i - 1], unique_vals, max_rank);
      update(bit_cnt, bit_sum, max_rank, in_r, 1, nums[i + dist]);
      curr_window++;
    }
    if (curr_window >= target) {
      long long curr_k_sum =
          query_k_smallest(bit_cnt, bit_sum, max_rank, target, rank_lut);
      if (min_cost == -1 || curr_k_sum < min_cost)
        min_cost = curr_k_sum;
    }
  }
  free(tmp);
  free(unique_vals);
  free(rank_lut);
  free(bit_cnt);
  free(bit_sum);
  return min_cost + nums[0];
}

int main() {
  int n1[] = {1, 3, 2, 6, 4, 2};
  int n2[] = {10, 1, 2, 2, 2, 1};
  int n3[] = {10, 8, 18, 9};
  long long r1 = minimumCost(n1, ARRAY_SIZE(n1), 3, 3);
  long long r2 = minimumCost(n2, ARRAY_SIZE(n2), 4, 3);
  long long r3 = minimumCost(n3, ARRAY_SIZE(n3), 3, 1);
  printf("%lld\n", r1); // expect: 5
  assert(r1 == 5);
  printf("%lld\n", r2); // expect: 15
  assert(r2 == 15);
  printf("%lld\n", r3); // expect: 36
  assert(r3 == 36);
}
