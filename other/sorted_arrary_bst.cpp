#include "leetcode.h"

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    TreeNode *root = helper(start, end, nums);
    return root;
  }

private:
  TreeNode *helper(int start, int end, vector<int> &nums) {
    if (start > end)
      return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(start, mid - 1, nums);
    node->right = helper(mid + 1, end, nums);
    return node;
  }
};
