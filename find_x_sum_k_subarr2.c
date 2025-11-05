// 3321. Find X-Sum of All K-Long Subarrays II
#include "leetcode.h"

/*
 * you are given the array 'nums' of 'n' integers and two integers 'k' and 'x'.
 * the x-sum of an array is calcluated by the following procedure: count the
 * occurences of all elements in the array, keep only the occurences of the top
 * 'x' most frequent elements. if two elements have the same number of
 * occurences, the element with the bigger value is considered more frequent.
 * calcluate the sum of the resulting array. note t hat if an array has less
 * than 'x' distinct elements, its x-sum is the sum of the array. return an
 * integer array 'answer' of length 'n - k + 1' where 'answer[i]' is the x-sum
 * of the subarray 'nums[i .. i + k - 1]'
 */

struct item {
  int id;
  int freq;
  long long val;
};

static inline int top_priority(const struct item *a, const struct item *b) {
  if (a->freq != b->freq)
    return a->freq < b->freq;
  return a->val < b->val;
}

static inline int rest_priority(const struct item *a, const struct item *b) {
  if (a->freq != b->freq)
    return a->freq > b->freq;
  return a->val > b->val;
}

struct heap {
  struct item *a;
  int size;
  int capacity;
  int (*priority)(const struct item *, const struct item *);
};

static void heap_init(struct heap *obj, int capacity,
                      int (*priority)(const struct item *,
                                      const struct item *)) {
  obj->capacity = capacity < 16 ? 16 : capacity;
  obj->a = (struct item *)malloc(obj->capacity * sizeof(struct item));
  obj->size = 0;
  obj->priority = priority;
}

static void heap_free(struct heap *obj) {
  free(obj->a);
  obj->a = NULL;
  obj->size = obj->capacity = 0;
}

static void heap_grow(struct heap *obj) {
  if (obj->size + 4 >= obj->capacity) {
    obj->capacity *= 2;
    obj->a =
        (struct item *)realloc(obj->a, obj->capacity * sizeof(struct item));
  }
}

static void heap_push(struct heap *obj, struct item it) {
  heap_grow(obj);
  int i = obj->size++;
  obj->a[i] = it;
  while (i > 0) {
    int p = (i - 1) >> 1;
    if (obj->priority(&obj->a[i], &obj->a[p])) {
      struct item tmp = obj->a[i];
      obj->a[i] = obj->a[p];
      obj->a[p] = tmp;
      i = p;
    } else
      break;
  }
}

static struct item heap_top(const struct heap *obj) { return obj->a[0]; }

static int heap_empty(const struct heap *obj) { return !obj->size; }

static void heap_pop(struct heap *obj) {
  if (!obj->size)
    return;
  obj->a[0] = obj->a[--obj->size];
  int i = 0;
  while (true) {
    int l = i * 2 + 1, r = l + 1, best = i;
    if (l < obj->size && obj->priority(&obj->a[l], &obj->a[best]))
      best = l;
    if (r < obj->size && obj->priority(&obj->a[r], &obj->a[best]))
      best = r;
    if (best == i)
      break;
    struct item tmp = obj->a[i];
    obj->a[i] = obj->a[best];
    obj->a[best] = tmp;
    i = best;
  }
}

static int cmp(const void *a, const void *b) {
  long long aa = *(const long long *)a, bb = *(const long long *)b;
  if (aa < bb)
    return -1;
  if (aa > bb)
    return 1;
  return 0;
}

static int val_to_id(long long *unique, int m, long long val) {
  int l = 0, r = m - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (unique[mid] == val)
      return mid;
    if (unique[mid] < val)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}

long long *findXSum(int *nums, int numsSize, int k, int x, int *returnSize) {
  if (!numsSize) {
    *returnSize = 0;
    return NULL;
  }
  *returnSize = numsSize - k + 1;
  long long *ans = (long long *)malloc(*returnSize * sizeof(long long));
  if (k == x) {
    long long s = 0;
    for (int i = 0; i < k; ++i)
      s += nums[i];
    ans[0] = s;
    for (int i = k; i < numsSize; ++i) {
      s += nums[i] - nums[i - k];
      ans[i - k + 1] = s;
    }
    return ans;
  }
  long long *tmp = (long long *)malloc(numsSize * sizeof(long long));
  for (int i = 0; i < numsSize; ++i)
    tmp[i] = (long long)nums[i];
  qsort(tmp, numsSize, sizeof(long long), cmp);
  int m = 0;
  for (int i = 0; i < numsSize; ++i)
    if (!i || tmp[i] != tmp[i - 1])
      tmp[m++] = tmp[i];
  long long *unique = tmp;
  int *freq = (int *)calloc(m, sizeof(int));
  char *in_top = (char *)calloc(m, sizeof(char));
  struct heap top, rest;
  heap_init(&top, m * 2 + 16, top_priority);
  heap_init(&rest, m * 2 + 16, rest_priority);
  for (int i = 0; i < k; ++i) {
    int id = val_to_id(unique, m, nums[i]);
    freq[id]++;
  }
  for (int i = 0; i < m; ++i)
    if (freq[i] > 0) {
      struct item it = {i, freq[i], unique[i]};
      heap_push(&rest, it);
    }
  long long x_sum = 0;
  int in_top_cnt = 0;
  while (in_top_cnt < x) {
    while (!heap_empty(&rest)) {
      struct item it = heap_top(&rest);
      int id = it.id;
      if (it.freq != freq[id] || it.freq <= 0 || in_top[id]) {
        heap_pop(&rest);
        continue;
      }
      heap_pop(&rest);
      in_top[id] = 1;
      ++in_top_cnt;
      x_sum += (long long)freq[id] * unique[id];
      struct item new_it = {id, freq[id], unique[id]};
      heap_push(&top, new_it);
      break;
    }
    if (heap_empty(&rest))
      break;
  }
  while (true) {
    while (!heap_empty(&top)) {
      struct item it = heap_top(&top);
      int id = it.id;
      if (it.freq != freq[id] || it.freq <= 0 || !in_top[id]) {
        heap_pop(&top);
        continue;
      }
      break;
    }
    while (!heap_empty(&rest)) {
      struct item it = heap_top(&rest);
      int id = it.id;
      if (it.freq != freq[id] || it.freq <= 0 || in_top[id]) {
        heap_pop(&rest);
        continue;
      }
      break;
    }
    if (heap_empty(&top) || heap_empty(&rest))
      break;
    struct item worst = heap_top(&top);
    struct item best = heap_top(&rest);
    int worst_id = worst.id, best_id = best.id;
    if (!(worst.freq == freq[worst_id] && in_top[worst_id] &&
          best.freq == freq[best_id] && !in_top[best_id])) {
      if (!(worst.freq == freq[worst_id] && in_top[worst_id]))
        heap_pop(&top);
      if (!(best.freq == freq[best_id] && !in_top[best_id]))
        heap_pop(&rest);
      continue;
    }
    int do_swap = 0;
    if (best.freq > worst.freq)
      do_swap = 1;
    else if (best.freq == worst.freq && unique[best_id] > unique[worst_id])
      do_swap = 0;
    if (!do_swap)
      break;
    heap_pop(&top);
    heap_pop(&rest);
    in_top[worst_id] = 0;
    in_top[best_id] = 1;
    x_sum -= (long long)worst.freq * unique[worst_id];
    x_sum += (long long)best.freq * unique[best_id];
    struct item new_worst = {worst_id, freq[worst_id], unique[worst_id]};
    struct item new_best = {best_id, freq[best_id], unique[best_id]};
    heap_push(&rest, new_worst);
    heap_push(&top, new_best);
  }
  ans[0] = x_sum;
  for (int i = k; i < numsSize; ++i) {
    long long out_val = nums[i - k];
    long long in_val = nums[i];
    int out_id = val_to_id(unique, m, out_val);
    int in_id = val_to_id(unique, m, in_val);
    if (in_top[out_id])
      x_sum -= unique[out_id];
    freq[out_id]--;
    if (freq[out_id] > 0) {
      struct item new_it = {out_id, freq[out_id], unique[out_id]};
      heap_push(&rest, new_it);
      heap_push(&top, new_it);
    } else {
      if (in_top[out_id]) {
        in_top[out_id] = 0;
        --in_top_cnt;
      }
    }
    freq[in_id]++;
    if (in_top[in_id])
      x_sum += unique[in_id];
    struct item in_it = {in_id, freq[in_id], unique[in_id]};
    heap_push(&rest, in_it);
    heap_push(&top, in_it);
    while (in_top_cnt < x) {
      while (!heap_empty(&rest)) {
        struct item it = heap_top(&rest);
        int id = it.id;
        if (it.freq != freq[id] || it.freq <= 0 || in_top[id]) {
          heap_pop(&rest);
          continue;
        }
        heap_pop(&rest);
        in_top[id] = 1;
        ++in_top_cnt;
        x_sum += (long long)freq[id] * unique[id];
        struct item new_it = {id, freq[id], unique[id]};
        heap_push(&top, new_it);
        break;
      }
      if (heap_empty(&rest))
        break;
    }
    while (true) {
      while (!heap_empty(&top)) {
        struct item it = heap_top(&top);
        int id = it.id;
        if (it.freq != freq[id] || it.freq <= 0 || !in_top[id]) {
          heap_pop(&top);
          continue;
        }
        break;
      }
      while (!heap_empty(&rest)) {
        struct item it = heap_top(&rest);
        int id = it.id;
        if (it.freq != freq[id] || it.freq <= 0 || in_top[id]) {
          heap_pop(&rest);
          continue;
        }
        break;
      }
      if (heap_empty(&top) || heap_empty(&rest))
        break;
      struct item worst = heap_top(&top);
      struct item best = heap_top(&rest);
      int worst_id = worst.id, best_id = best.id;
      if (!(worst.freq == freq[worst_id] && in_top[worst_id] &&
            best.freq == freq[best_id] && !in_top[best_id])) {
        if (!(worst.freq == freq[worst_id] && in_top[worst_id]))
          heap_pop(&top);
        if (!(best.freq == freq[best_id] && !in_top[best_id]))
          heap_pop(&rest);
        continue;
      }
      int do_swap = 0;
      if (best.freq > worst.freq)
        do_swap = 1;
      else if (best.freq == worst.freq && unique[best_id] > unique[worst_id])
        do_swap = 1;
      if (!do_swap)
        break;
      heap_pop(&top);
      heap_pop(&rest);
      in_top[worst_id] = 0;
      in_top[best_id] = 1;
      x_sum -= (long long)worst.freq * unique[worst_id];
      x_sum += (long long)best.freq * unique[best_id];
      struct item new_worst = {worst_id, freq[worst_id], unique[worst_id]};
      struct item new_best = {best_id, freq[best_id], unique[best_id]};
      heap_push(&rest, new_worst);
      heap_push(&top, new_best);
    }
    if (in_top_cnt > x) {
      while (in_top_cnt > x) {
        while (!heap_empty(&top)) {
          struct item it = heap_top(&top);
          int id = it.id;
          if (it.freq != freq[id] || it.freq <= 0 || !in_top[id]) {
            heap_pop(&top);
            continue;
          }
          heap_pop(&top);
          in_top[id] = 0;
          --in_top_cnt;
          x_sum -= (long long)it.freq * unique[id];
          struct item new_it = {id, freq[id], unique[id]};
          heap_push(&rest, new_it);
          break;
        }
        if (heap_empty(&top))
          break;
      }
    }
    ans[i - k + 1] = x_sum;
  }
  free(freq);
  free(in_top);
  free(unique);
  heap_free(&top);
  heap_free(&rest);
  return ans;
}

int main() {
  int n1[] = {1, 1, 2, 2, 3, 4, 2, 3}, rs1;
  int n2[] = {3, 8, 7, 8, 7, 5}, rs2;
  long long *fxs1 = findXSum(n1, ARRAY_SIZE(n1), 6, 2, &rs1);
  long long *fxs2 = findXSum(n2, ARRAY_SIZE(n2), 2, 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%lld ", fxs1[i]); // expect: 6 10 12
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%lld ", fxs2[i]); // expect: 11 15 15 15 12
  printf("\n");
  free(fxs1);
  free(fxs2);
}
