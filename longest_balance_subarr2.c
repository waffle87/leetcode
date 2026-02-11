// 3721. Longest Balanced Subarray II
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a subarray is called balance if the
 * number of distinct even numbers in the subarray is equal to the number of
 * distinct odd numbers. return the legnth of the longest balance subarray.
 */

struct list {
  struct ListNode *head;
  int size;
};

struct hash_item {
  int key;
  struct list *val;
  UT_hash_handle hh;
};

struct list *list_init(void) {
  struct list *obj = (struct list *)malloc(sizeof(struct list));
  obj->head = NULL;
  obj->size = 0;
  return obj;
}

void list_push(struct list *obj, int val) {
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = obj->head;
  obj->head = node;
  obj->size++;
}

void list_pop(struct list *obj) {
  if (!obj->head)
    return;
  struct ListNode *tmp = obj->head;
  obj->head = obj->head->next;
  free(tmp);
  obj->size--;
}

int list_at(struct list *obj, int idx) {
  struct ListNode *curr = obj->head;
  for (int i = 0; i < idx && curr; i++)
    curr = curr->next;
  return curr ? curr->val : -1;
}

void list_reverse(struct list *obj) {
  struct ListNode *prev = NULL, *curr = obj->head, *next = NULL;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  obj->head = prev;
}

void list_free(struct list *obj) {
  while (obj->head)
    list_pop(obj);
  free(obj);
}

struct hash_item *hash_find_item(struct hash_item **obj, int key) {
  struct hash_item *p = NULL;
  HASH_FIND_INT(*obj, &key, p);
  return p;
}

void hash_add_item(struct hash_item **obj, int key, struct list *val) {
  if (hash_find_item(obj, key))
    return;
  struct hash_item *p = (struct hash_item *)malloc(sizeof(struct hash_item));
  p->key = key;
  p->val = val;
  HASH_ADD_INT(*obj, key, p);
}

struct list *hash_get_item(struct hash_item **obj, int key) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p) {
    struct list *new_list = list_init();
    hash_add_item(obj, key, new_list);
    return new_list;
  }
  return p->val;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    list_free(curr->val);
    free(curr);
  }
}

void hash_iterate(struct hash_item **obj,
                  void (*callback)(struct hash_item *item)) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) { callback(curr); }
}

struct lazy_tag {
  int to_add;
};

void lazy_tag_add(struct lazy_tag *tag, struct lazy_tag *other) {
  tag->to_add += other->to_add;
}

bool lazy_tag_has_tag(struct lazy_tag *tag) { return tag->to_add != 0; }

void lazy_tag_clear(struct lazy_tag *tag) { tag->to_add = 0; }

struct segment_tree_node {
  int min_val;
  int max_val;
  struct lazy_tag l_tag;
};

struct segment_tree {
  int n;
  struct segment_tree_node *tree;
};

void segment_tree_apply_tag(struct segment_tree *seg, int i,
                            struct lazy_tag *tag) {
  seg->tree[i].min_val += tag->to_add;
  seg->tree[i].max_val += tag->to_add;
  lazy_tag_add(&seg->tree[i].l_tag, tag);
}

void segment_tree_pushdown(struct segment_tree *seg, int i) {
  if (lazy_tag_has_tag(&seg->tree[i].l_tag)) {
    struct lazy_tag tag = {seg->tree[i].l_tag.to_add};
    segment_tree_apply_tag(seg, i << 1, &tag);
    segment_tree_apply_tag(seg, (i << 1) | 1, &tag);
    lazy_tag_clear(&seg->tree[i].l_tag);
  }
}

void segment_tree_pushup(struct segment_tree *seg, int i) {
  seg->tree[i].min_val =
      fmin(seg->tree[i << 1].min_val, seg->tree[(i << 1) | 1].min_val);
  seg->tree[i].max_val =
      fmax(seg->tree[i << 1].max_val, seg->tree[(i << 1) | 1].max_val);
}

void segment_tree_build(struct segment_tree *seg, int *data, int l, int r,
                        int i) {
  if (l == r) {
    seg->tree[i].min_val = seg->tree[i].max_val = data[l - 1];
    return;
  }
  int mid = l + ((r - l) >> 1);
  segment_tree_build(seg, data, l, mid, i << 1);
  segment_tree_build(seg, data, mid + 1, r, (i << 1) | 1);
  segment_tree_pushup(seg, i);
}

void segment_tree_update(struct segment_tree *seg, int target_left,
                         int target_right, struct lazy_tag *tag, int l, int r,
                         int i) {
  if (target_left <= l && r <= target_right) {
    segment_tree_apply_tag(seg, i, tag);
    return;
  }
  segment_tree_pushdown(seg, i);
  int mid = l + ((r - l) >> 1);
  if (target_left <= mid)
    segment_tree_update(seg, target_left, target_right, tag, l, mid, i << 1);
  if (target_right > mid)
    segment_tree_update(seg, target_left, target_right, tag, mid + 1, r,
                        (i << 1) | 1);
  segment_tree_pushup(seg, i);
}

int segment_tree_find(struct segment_tree *seg, int target_left,
                      int target_right, int val, int l, int r, int i) {
  if (seg->tree[i].min_val > val || seg->tree[i].max_val < val)
    return -1;
  if (l == r)
    return l;
  segment_tree_pushdown(seg, i);
  int mid = l + ((r - l) >> 1);
  if (target_right >= mid + 1) {
    int res = segment_tree_find(seg, target_left, target_right, val, mid + 1, r,
                                (i << 1) | 1);
    if (res != -1)
      return res;
  }
  if (target_left <= mid)
    return segment_tree_find(seg, target_left, target_right, val, l, mid,
                             i << 1);
  return -1;
}

struct segment_tree *segment_tree_init(int *data, int n) {
  struct segment_tree *seg =
      (struct segment_tree *)malloc(sizeof(struct segment_tree));
  seg->n = n;
  seg->tree = (struct segment_tree_node *)calloc(
      n * 4 + 1, sizeof(struct segment_tree_node));
  segment_tree_build(seg, data, 1, n, 1);
  return seg;
}

void segment_tree_add(struct segment_tree *seg, int l, int r, int val) {
  struct lazy_tag tag = {val};
  segment_tree_update(seg, l, r, &tag, 1, seg->n, 1);
}

int segment_tree_find_last(struct segment_tree *seg, int start, int val) {
  if (start > seg->n)
    return -1;
  return segment_tree_find(seg, start, seg->n, val, 1, seg->n, 1);
}

void segment_tree_free(struct segment_tree *seg) {
  free(seg->tree);
  free(seg);
}

int sgn(int x) { return (x % 2 == 0) ? 1 : -1; }

void reverse_list(struct hash_item *item) { list_reverse(item->val); }

int longestBalanced(int *nums, int numsSize) {
  struct hash_item *occurrences = NULL;
  int len = 0, *prefix_sum = (int *)calloc(numsSize, sizeof(int));
  prefix_sum[0] = sgn(nums[0]);
  struct list *list0 = hash_get_item(&occurrences, nums[0]);
  list_push(list0, 1);
  for (int i = 1; i < numsSize; i++) {
    prefix_sum[i] = prefix_sum[i - 1];
    struct list *occ = hash_get_item(&occurrences, nums[i]);
    if (!occ->size)
      prefix_sum[i] += sgn(nums[i]);
    list_push(occ, i + 1);
  }
  hash_iterate(&occurrences, reverse_list);
  struct segment_tree *seg = segment_tree_init(prefix_sum, numsSize);
  for (int i = 0; i < numsSize; i++) {
    int find_res = segment_tree_find_last(seg, i + len, 0);
    int new_len = find_res - i;
    len = fmax(len, new_len);
    int next_pos = numsSize + 1;
    struct list *occ = hash_get_item(&occurrences, nums[i]);
    list_pop(occ);
    if (occ->size > 0)
      next_pos = list_at(occ, 0);
    segment_tree_add(seg, i + 1, next_pos - 1, -sgn(nums[i]));
  }
  segment_tree_free(seg);
  free(prefix_sum);
  hash_free(&occurrences);
  return len;
}

int main() {
  int n1[] = {2, 5, 4, 3}, n2[] = {3, 2, 2, 5, 4}, n3[] = {1, 2, 3, 2};
  int r1 = longestBalanced(n1, ARRAY_SIZE(n1));
  int r2 = longestBalanced(n2, ARRAY_SIZE(n2));
  int r3 = longestBalanced(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1); // expect: 4
  assert(r1 == 4);
  printf("%d\n", r3); // expect: 5
  assert(r2 == 5);
  printf("%d\n", r3); // expect: 3
  assert(r3 == 3);
}
