// 951. Flip Equivalent Binary Trees
#include "leetcode.h"

/*
 * for a binarytree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees. a binary tree X is flip
 * equivalent to a binary tree Y if and only if we can make X equal to Y after
 * some number of flip operations. given the roots of two binary trees 'root1'
 * and 'root2', return 'true' if the two trees are flip equivalent.
 */

//__attribute((naked))
bool flipEquiv(struct TreeNode *root1, struct TreeNode *root2) {
  /*
    __asm("push %rbp;"
          "mov %rsp,%rbp;"
          "push %rbx;"
          "push %r8;"
          "push %r9;"
          "xor %eax,%eax;"
          "test %rdi,%rdi;"
          "jnz l1;"
          "test %rsi,%rsi;"
          "jnz l0;"
          "add $0x1,%eax;"
          "jmp l0;"
          "l1:;"
          "test %rsi,%rsi;"
          "jz l0;"
          "mov (%rdi),%ecx;"
          "cmp %ecx,(%rsi);"
          "jne l0;"
          "mov %rdi,%r8;"
          "mov %rsi,%r9;"
          "mov 0x8(%r8),%rdi;"
          "mov 0x8(%r9),%rsi;"
          "call flipEquiv;"
          "xchg %eax,%ebx;"
          "mov 0x10(%r8),%rdi;"
          "mov 0x10(%r9),%rsi;"
          "call flipEquiv;"
          "and %ebx,%eax;"
          "jnz l0;"
          "mov 0x8(%r8),%rdi;"
          "mov 0x10(%r9),%rsi;"
          "call flipEquiv;"
          "xchg %eax,%ebx;"
          "mov 0x10(%r8),%rdi;"
          "mov 0x8(%r9),%rsi;"
          "call flipEquiv;"
          "and %ebx,%eax;"
          "l0:;"
          "pop %r9;"
          "pop %r8;"
          "pop %rbx;"
          "mov %rbp,%rsp;"
          "pop %rbp;"
          "pop %rcx;"
          "jmp %rcx;");
  */
  if (!root1 || !root2)
    return root1 == root2;
  if (root1->val == root2->val) {
    return (flipEquiv(root1->left, root2->right) &
            flipEquiv(root1->right, root2->left)) ||
           (flipEquiv(root1->left, root2->left) &
            flipEquiv(root1->right, root2->right));
  }
  return false;
}

int main() {
  struct TreeNode *r1 = treenode_create(1);
  r1->left = treenode_create(2);
  r1->right = treenode_create(3);
  r1->left->left = treenode_create(4);
  r1->left->right = treenode_create(5);
  r1->right->left = treenode_create(6);
  r1->right->right = NULL;
  r1->left->right->left = treenode_create(7);
  r1->left->right->right = treenode_create(8);
  struct TreeNode *r2 = treenode_create(1);
  r2->left = treenode_create(3);
  r2->right = treenode_create(2);
  r2->left->left = NULL;
  r2->left->right = treenode_create(6);
  r2->right->left = treenode_create(4);
  r2->right->right = treenode_create(5);
  r2->right->right->left = treenode_create(8);
  r2->right->right->right = treenode_create(7);
  printf("%d\n", flipEquiv(r1, r2)); // expect: 1
  treenode_free(r1);
  treenode_free(r2);
}
