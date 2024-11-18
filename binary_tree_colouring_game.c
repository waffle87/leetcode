// 1145. Binary Tree Coloring Game
#include "leetcode.h"

/*
 * two players play a turn based game on a binary tree. we are given the 'root'
 * of this binary tree, and the number of nodes 'n' in the tree. 'n' is odd and
 * each node has a distinct value from 1 to 'n'. initially the first player
 * names a value 'x' with '1 <= x <= n' and the second player names a value 'y'
 * with '1 <= y <= n' and 'y != x'. the first player colours the node with value
 * 'x' red and the second player colours the node with value 'y' blue. then the
 * players take turns starting with the first player. in each turn that player
 * chooses a node of their colour and the colours an uncoloured neighbour of the
 * chose node.
 */

static int rc, lc;

int get_rl(struct TreeNode *curr, int x, int found) {
  if (!curr)
    return 0;
  int right, left;
  if (curr->val == x) {
    right = get_rl(curr->right, x, 1);
    left = get_rl(curr->left, x, 1);
    rc = right;
    lc = left;
  }
  right = get_rl(curr->right, x, found);
  left = get_rl(curr->left, x, found);
  return found ? right + left + 1 : 0;
}

bool btreeGameWinningMove(struct TreeNode *root, int n, int x) {
  get_rl(root, x, 0);
  int rem = n - (rc + lc + 1);
  if (rem > rc + lc + 1 || rc > rem + lc + 1 || lc > rem + rc + 1)
    return 1;
  return 0;
}

int main() {
  struct TreeNode *r1 = treenode_create(1);
  r1->left = treenode_create(2);
  r1->right = treenode_create(3);
  r1->left->left = treenode_create(4);
  r1->left->right = treenode_create(5);
  r1->left->left->left = treenode_create(8);
  r1->left->left->right = treenode_create(9);
  r1->right->left = treenode_create(6);
  r1->right->right = treenode_create(7);
  struct TreeNode *r2 = treenode_create(1);
  r2->left = treenode_create(2);
  r2->right = treenode_create(3);
  printf("%d\n", btreeGameWinningMove(r1, 11, 3)); // expect: 1
  printf("%d\n", btreeGameWinningMove(r2, 3, 1));  // expect: 0
  treenode_free(r1), treenode_free(r2);
}
