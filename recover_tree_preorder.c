// 1028. Recover a Tree From Preorder Traversal
#include "leetcode.h"

/*
 * we run a preorder depth-first search (dfs) on the 'root' of a binary tree. at
 * each node in this traversal, we output 'D' dashes (where 'D' is the depth of
 * this node), then we output the value of this node. if the depth of a node is
 * 'D' the depth of its immediate child is 'D + 1'. the depth of the 'root' node
 * is '0'. if a node has only one child, that child is guaranteed to be the left
 * child. given the output 'traversal' of this traversal, recover the tree and
 * return its root.
 */

struct TreeNode *recoverFromPreorder(char *traversal) {
  int vals[1000] = {0}, depths[1000] = {0}, n = 0;
  for (int i = 0; i < strlen(traversal);) {
    while (traversal[i] == '-') {
      depths[n]++;
      i++;
    }
    while (traversal[i] >= '0' && traversal[i] <= '9') {
      vals[n] = vals[n] * 10 + traversal[i] - '0'; // fix
      i++;
    }
    n++;
  }
  struct TreeNode *ans = (struct TreeNode *)calloc(n, sizeof(struct TreeNode));
  for (int i = 0; i < n; i++) {
    ans[i].val = vals[i];
    for (int j = i; j >= 0; j--)
      if (depths[j] < depths[i]) {
        if (!ans[j].left)
          ans[j].left = &ans[i];
        else
          ans[j].right = &ans[i];
        break;
      }
  }
  return ans;
}

int main() {
  char *t1 = "1-2--3--4-5--6--7";
  char *t2 = "1-2--3---4-5--6---7";
  char *t3 = "1-401--349---90--88";
  struct TreeNode *rfp1 = recoverFromPreorder(t1);
  struct TreeNode *rfp2 = recoverFromPreorder(t2);
  struct TreeNode *rfp3 = recoverFromPreorder(t3);
  treenode_print(rfp1); // expect: [1,2,5,3,4,6,7]
  treenode_print(rfp2); // expect: [1,2,5,3,null,6,null,4,null,7]
  treenode_print(rfp3); // expect: [1,401,null,349,88,90]
  treenode_free(rfp1);
  treenode_free(rfp2);
  treenode_free(rfp3);
}
