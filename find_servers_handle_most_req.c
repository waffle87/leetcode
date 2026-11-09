// 1606. Find Servers That Handled Most Number of Requests
#include "leetcode.h"

struct node {
  long long time;
  int idx;
};

struct min_heap {
  struct node *data;
  int size;
};

static void heap_push(struct min_heap *h, struct node val) {
  int i = h->size++;
  h->data[i] = val;
  while (i > 0) {
    int p = (i - 1) / 2;
    if (h->data[p].time < h->data[i].time ||
        (h->data[p].time == h->data[i].time &&
         h->data[p].idx <= h->data[i].idx))
      break;
    struct node tmp = h->data[i];
    h->data[i] = h->data[p];
    h->data[p] = tmp;
    i = p;
  }
}

static struct node heap_pop(struct min_heap *h) {
  struct node res = h->data[0];
  h->size--;
  if (!h->size)
    return res;
  h->data[0] = h->data[h->size];
  int i = 0;
  while (true) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int best = i;
    if (l < h->size && (h->data[l].time < h->data[best].time ||
                        (h->data[l].time == h->data[best].time &&
                         h->data[l].idx < h->data[best].idx)))
      best = l;
    if (r < h->size && (h->data[r].time < h->data[best].time ||
                        (h->data[r].time == h->data[best].time &&
                         h->data[r].idx < h->data[best].idx)))
      best = r;
    if (best == i)
      break;
    struct node tmp = h->data[i];
    h->data[i] = h->data[best];
    h->data[best] = tmp;
    i = best;
  }
  return res;
}

static int find_next(int *parent, int x) {
  if (parent[x] != x)
    parent[x] = find_next(parent, parent[x]);
  return parent[x];
}

static void update(int *tree, int n, int i, int delta) {
  for (i++; i <= n; i += i & -i)
    tree[i] += delta;
}

static int query(int *tree, int i) {
  int sum = 0;
  for (i++; i > 0; i -= i & -i)
    sum += tree[i];
  return sum;
}

static int kth(int *tree, int n, int k) {
  int idx = 0, bit = 1;
  while ((bit << 1) <= n)
    bit <<= 1;
  for (; bit > 0; bit >>= 1) {
    int next = idx + bit;
    if (next <= n && tree[next] < k) {
      idx = next;
      k -= tree[next];
    }
  }
  return idx;
}

int *busiestServers(int k, int *arrival, int arrivalSize, int *load,
                    int loadSize, int *returnSize) {
  struct min_heap heap = {
      .data = (struct node *)malloc(k * sizeof(struct node)),
      .size = 0,
  };
  int *server = (int *)calloc(k, sizeof(int));
  int *tree = (int *)calloc(k + 1, sizeof(int));
  for (int i = 0; i < k; i++)
    update(tree, k, i, 1);
  int available = k;
  for (int i = 0; i < arrivalSize; i++) {
    long long arr = arrival[i];
    int l = load[i];
    while (heap.size > 0 && heap.data[0].time <= arr) {
      struct node n = heap_pop(&heap);
      update(tree, k, n.idx, 1);
      available++;
    }
    if (!available)
      continue;
    int start = i % k;
    int before = start > 0 ? query(tree, start - 1) : 0;
    int rank = before < available ? before + 1 : 1;
    int s = kth(tree, k, rank);
    update(tree, k, s, -1);
    available--;
    heap_push(&heap, (struct node){arr + l, s});
    server[s]++;
  }
  int max = 0, cnt = 0, pos = 0;
  for (int i = 0; i < k; i++)
    max = fmax(max, server[i]);
  for (int i = 0; i < k; i++)
    if (server[i] == max)
      cnt++;
  int *ans = (int *)malloc(cnt * sizeof(int));
  *returnSize = cnt;
  free(heap.data);
  free(server);
  free(tree);
  return ans;
}

int main() {
  int a1[] = {1, 2, 3, 4, 5}, l1[] = {5, 2, 3, 3, 3};
  int a2[] = {1, 2, 3, 4}, l2[] = {1, 2, 1, 2};
  int a3[] = {1, 2, 3}, l3[] = {10, 12, 11};
  int r1[] = {1}, rs1;
  int r2[] = {0}, rs2;
  int r3[] = {0, 1, 2}, rs3;
  int *bs1 = busiestServers(3, a1, ARRAY_SIZE(a1), l1, ARRAY_SIZE(l1), &rs1);
  int *bs2 = busiestServers(3, a2, ARRAY_SIZE(a2), l2, ARRAY_SIZE(l2), &rs2);
  int *bs3 = busiestServers(3, a3, ARRAY_SIZE(a3), l3, ARRAY_SIZE(l3), &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", bs1[i]);
    assert(bs1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", bs2[i]);
    assert(bs2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", bs3[i]);
    assert(bs3[i] == r3[i]);
  }
  printf("\n");
  free(bs1);
  free(bs2);
  free(bs3);
}
