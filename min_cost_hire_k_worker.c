// 857. Minimum Cost to Hire K Workers
#include "leetcode.h"

/*
 * there are 'n' workers. you are given two integer arrays 'quality' and 'wage'
 * where 'quality[i]' is the quality of the i'th worker and 'wage[i]' is the
 * minimum wage expectation for the i'th worker. we want to hire exactly 'k'
 * workers to form a paid group. to hire a group of 'k' workers, we must pay
 * them according to the following rules. every worker in the paid group must be
 * paid at least their minimum wage expectation. in the group, each worker's pay
 * must be directly proportional to their quality. this means if a worker's
 * quality is double that of another worker in the group, then they must be paid
 * twice as much as the other worker. given the integer 'k', return the least
 * amount of money needed to form apaid group satisfying the above conditions.
 */

struct workers {
  int q;
  int w;
  double w_p_q;
};

int cmp_work(const void *a, const void *b) {
  double tmp = ((struct workers *)b)->w_p_q - ((struct workers *)a)->w_p_q;
  if (tmp < 0)
    return -1;
  return 1;
}

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

void max_heap_insert(int *heap, int *n, int val) {
  int i = ++(*n), parent = i / 2;
  while (i != 1 && val > heap[parent]) {
    heap[i] = heap[parent];
    i = parent;
    parent /= 2;
  }
  heap[i] = val;
}

int max_heap_delete(int *heap, int *n) {
  int val = heap[1], tmp = heap[*n--], parent = 1, child = parent * 2;
  while (child <= *n) {
    if (child < *n && heap[child] < heap[child + 1])
      child++;
    if (tmp >= heap[child])
      break;
    else {
      heap[parent] = heap[child];
      parent = child;
      child *= 2;
    }
  }
  heap[parent] = tmp;
  return val;
}

void get_dp(struct workers *arr, int size, int num, int *dp) {
  if (!num)
    return;
  int tmp[num + 1], n = 0, sum = 0;
  for (int i = size - num; i < size; i++) {
    max_heap_insert(tmp, &n, arr[i].q);
    sum += arr[i].q;
  }
  dp[size - num] = sum;
  for (int i = size - num - 1; i >= 0; i--) {
    if (arr[i].q < tmp[1]) {
      sum -= max_heap_delete(tmp, &n);
      sum += arr[i].q;
      max_heap_insert(tmp, &n, arr[i].q);
    }
    dp[i] = sum;
  }
}

double mincostToHireWorkers(int *quality, int qualitySize, int *wage,
                            int wageSize, int k) {
  if (qualitySize == 1)
    return wage[0];
  struct workers *member =
      (struct workers *)malloc(qualitySize * sizeof(struct workers));
  for (int i = 0; i < qualitySize; i++) {
    member[i].q = quality[i];
    member[i].w = wage[i];
    member[i].w_p_q = (double)wage[i] / quality[i];
  }
  double ans = 1000000000, cost;
  int max = 0x7fffffff, q_idx = 0, dp[qualitySize];
  qsort(member, qualitySize, sizeof(struct workers), cmp_work);
  get_dp(member, qualitySize, k - 1, dp);
  for (int i = 0; i <= qualitySize - k; i++) {
    int total = member[i].q;
    if (k != 1)
      total += dp[i + 1];
    cost = total * member[i].w_p_q;
    if (cost < ans)
      ans = cost;
  }
  return ans;
}

int main() {
  int q1[] = {10, 20, 5}, w1[] = {70, 50, 30}, q2[] = {3, 1, 10, 10, 1},
      w2[] = {4, 8, 2, 2, 7};
  printf("%f\n", mincostToHireWorkers(q1, ARRAY_SIZE(q1), w1, ARRAY_SIZE(w1),
                                      2)); // expect: 105.0000
  printf("%f\n", mincostToHireWorkers(q2, ARRAY_SIZE(q2), w2, ARRAY_SIZE(w2),
                                      3)); // expect: 30.6667
}
