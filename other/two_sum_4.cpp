#include "leetcode.h"

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> nums;
    order(root, nums);
    for (int i = 0, j = nums.size() - 1; i < j;) {
      if (nums[i] + nums[j] == k)
        return true;
      (nums[i] + nums[j] < k) ? i++ : j--;
    }
    return false;
  }

private:
  void order(TreeNode *root, vector<int> &nums) {
    if (root == NULL)
      return;
    order(root->left, nums);
    nums.push_back(root->val);
    order(root->right, nums);
  }
};
