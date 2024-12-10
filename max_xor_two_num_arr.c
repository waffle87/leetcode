// 421. Maximum XOR of Two Numbers in an Array
#include "leetcode.h"

/*
 * given an integer array 'nums', return the maximum result of 'nums[i] ^
 * nums[j]' where '0 <= i <= j < n'
 */

struct tree {
  struct tree *left;
  struct tree *right;
};

static int ans;
struct tree *root;

struct tree *new_node(void) {
  struct tree *obj = (struct tree *)malloc(sizeof(struct tree));
  obj->left = NULL;
  obj->right = NULL;
  return obj;
}

void trie_create(struct tree *r, int n, int width) {
  if (width <= 0 || !r)
    return;
  if (n & (1 << (width - 1))) {
    if (!r->right)
      r->right = new_node();
    trie_create(r->right, n, width - 1);
  } else {
    if (!r->left)
      r->left = new_node();
    trie_create(r->left, n, width - 1);
  }
  return;
}

void max_xor(struct tree *high, struct tree *low, int xor, int bit_pos) {
  bool skip = false;
  if (!low) {
    ans = ans < xor ? xor : ans;
    return;
  }
  if (high->right && low->left) {
    xor |= 1 << (bit_pos - 1);
    max_xor(high->right, low->left, xor, bit_pos - 1);
    xor &= ~(1 << (bit_pos - 1));
    skip = true;
  }
  if (high->left && low->right) {
    xor |= 1 << (bit_pos - 1);
    max_xor(high->left, low->right, xor, bit_pos - 1);
    xor &= ~(1 << (bit_pos - 1));
    skip = true;
  }
  if (!skip) {
    max_xor(high->left, low->left, xor, bit_pos - 1);
    max_xor(high->right, high->right, xor, bit_pos - 1);
  }
}

int findMaximumXOR(int *nums, int numsSize) {
  struct tree *node = root;
  int num, max = -1, bit_pos = 0, xor = 0;
  for (int i = 0; i < numsSize; i++)
    max = max < nums[i] ? nums[i] : max;
  while (max) {
    bit_pos++;
    max >>= 1;
  }
  root = new_node();
  for (int i = 0; i < numsSize; i++)
    trie_create(root, nums[i], bit_pos);
  struct tree *high, *low;
  high = low = root;
  ans = 0;
  max_xor(root, root, 0, bit_pos);
  return ans;
}

int main() {
  int n1[] = {3, 10, 5, 25, 2, 8},
      n2[] = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
  printf("%d\n", findMaximumXOR(n1, ARRAY_SIZE(n1))); // expect: 28
  printf("%d\n", findMaximumXOR(n2, ARRAY_SIZE(n2))); // expect: 127
}
