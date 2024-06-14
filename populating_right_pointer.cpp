#include "leetcode.h"

class Solution {
public:
  Node *connect(Node *root) {
    Node *currParent = root, *baseChild, *currChild, *nextChild;
    while (currParent) {
      while (currParent->next && !currParent->left && !currParent->right)
        currParent = currParent->next;
      currChild = baseChild =
          currParent->left ? currParent->left : currParent->right;
      while (currChild) {
        if (currParent->right && currChild != currParent->right)
          nextChild = currParent->right;
        else {
          currParent = currParent->next;
          while (currParent && !currParent->left && !currParent->right)
            currParent = currParent->next;
          nextChild = currParent ? currParent->left ? currParent->left
                                                    : currParent->right
                                 : currParent;
        }
        currChild->next = nextChild;
        currChild = nextChild;
      }
      currParent = baseChild;
    }
    return root;
  }
};

int main() {}
