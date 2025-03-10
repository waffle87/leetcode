#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = std::i32::MIN;
        Solution::dfs(&root, &mut ans);
        ans
    }
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, ans: &mut i32) -> i32 {
        if let Some(n) = node {
            let val = n.borrow().val;
            let l = std::cmp::max(0, Solution::dfs(&n.borrow().left, ans));
            let r = std::cmp::max(0, Solution::dfs(&n.borrow().right, ans));
            *ans = std::cmp::max(*ans, val + l + r);
            val + std::cmp::max(l, r)
        } else {
            0
        }
    }
}
