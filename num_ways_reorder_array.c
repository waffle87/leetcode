// 1569. Number of Ways to Reorder Array to Get Same BST
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'nums' that represents a permutation of integers from '1 to
 * n'. we are going to construct a binary search tree (BST) by inserting the
 * elements of 'nums' in order into an initially empty BST. find the number of
 * different ways to reorder 'nums' so that the constructed BST is identical to
 * that formed from the original array 'nums'. for example given 'nums =
 * [2,1,3]', we will have 2 as the root, 1 as a left child, and three as a right
 * child. the array [2,3,1] also yields the same BST, but '[3,2,1]' yields a
 * different BST. return the number of ways to reorder 'nums' such that the BST
 * formed is identical to the original BST formed from 'nums'. since the answer
 * may be large, return it modulo 10^9+7
 */

long long factorial[1024], factorial_inv[1024], inv[1024];
int mod = 1e9 + 7;

typedef struct {
  int val;
  int left_cnt, right_cnt;
  struct node *left, *right;
} node;

void insert(node *root, int val) {
  if (root->val > val) {
    if (root->left == NULL) {
      node *new = (node *)malloc(sizeof(node));
      new->val = val;
      new->left = NULL;
      new->right = NULL;
      new->left_cnt = 0;
      new->right_cnt = 0;
      root->left = new;
      root->left_cnt++;
      return;
    } else {
      root->left_cnt++;
      insert(root->left, val);
    }
  } else if (root->val < val) {
    if (root->right == NULL) {
      node *new = (node *)malloc(sizeof(node));
      new->val = val;
      new->left = NULL;
      new->right = NULL;
      new->left_cnt = 0;
      new->right_cnt = 0;
      root->right = new;
      root->right_cnt++;
      return;
    } else {
      root->right_cnt++;
      insert(root->right, val);
    }
  }
}

void free_node(node *root) {
  if (root->left)
    free_node(root->left);
  if (root->right)
    free_node(root->right);
  free(root);
}

long long ways(node *root) {
  if (!root)
    return 1;
  if (!root->left && !root->right)
    return 1;
  if (!root->left)
    return ways(root->right) % mod;
  if (!root->right)
    return ways(root->left) % mod;
  long long tmp = factorial[root->left_cnt + root->right_cnt];
  tmp = (tmp * factorial_inv[root->left_cnt]) % mod;
  tmp = (tmp * factorial_inv[root->right_cnt]) % mod;
  return ((tmp * ways(root->left) % mod) * ways(root->right)) % mod;
}

int numOfWays(int *nums, int nums_size) {
  factorial[0] = factorial[1] = 1;
  factorial_inv[0] = factorial_inv[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < 1024; i++) {
    factorial[i] = (factorial[i - 1] * i) % mod;
    inv[i] = mod - (mod / i * inv[mod % i]) % mod;
    factorial_inv[i] = (factorial_inv[i - 1] * inv[i]) % mod;
  }
  node *root = (node *)malloc(sizeof(node));
  root->val = nums[0];
  root->left = NULL;
  root->right = NULL;
  root->left_cnt = 0;
  root->right_cnt = 0;
  for (int i = 1; i < nums_size; i++)
    insert(root, nums[i]);
  int ans = (int)ways(root) - 1;
  free_node(root);
  return ans;
}

int main() {
  int n1[] = {2, 1, 3};
  int n2[] = {3, 4, 5, 1, 2};
  int n3[] = {1, 2, 3};
  printf("%d\n", numOfWays(n1, 3)); // expect: 1
  printf("%d\n", numOfWays(n2, 5)); // expect: 5
  printf("%d\n", numOfWays(n3, 3)); // expect: 0
}
