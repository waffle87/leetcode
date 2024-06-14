#include "leetcode.h"

struct segNode {
  int start, end, sum;
  segNode *left, *right;
  segNode(int a, int b)
      : start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};

class NumArray {
public:
  segNode *root;
  NumArray(vector<int> &nums) { root = buildTree(nums, 0, nums.size() - 1); }
  void update(int index, int val) { modifyTree(index, val, root); }
  int sumRange(int left, int right) { return queryTree(left, right, root); }

private:
  segNode *buildTree(vector<int> &nums, int start, int end) {
    if (start > end)
      return nullptr;
    segNode *root = new segNode(start, end);
    if (start == end) {
      root->sum = nums[start];
      return root;
    }
    int mid = start + (end - start) / 2;
    root->left = buildTree(nums, start, mid);
    root->right = buildTree(nums, mid + 1, end);
    root->sum = root->left->sum + root->right->sum;
    return root;
  }
  int modifyTree(int i, int val, segNode *root) {
    if (root == nullptr)
      return 0;
    int diff;
    if (root->start == i && root->end == i) {
      diff = val - root->sum;
      root->sum = val;
      return diff;
    }
    int mid = (root->start + root->end) / 2;
    if (i > mid)
      diff = modifyTree(i, val, root->right);
    else
      diff = modifyTree(i, val, root->left);
    root->sum = root->sum + diff;
    return diff;
  }
  int queryTree(int i, int j, segNode *root) {
    if (root == nullptr)
      return 0;
    if (root->start == i && root->end == j)
      return root->sum;
    int mid = (root->start + root->end) / 2;
    if (i > mid)
      return queryTree(i, j, root->right);
    if (j <= mid)
      return queryTree(i, j, root->left);
    return queryTree(i, mid, root->left) + queryTree(mid + 1, j, root->right);
  }
};
