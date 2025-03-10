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
    pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
        if let Some(root) = root {
            let mut sum = 0;
            if low <= root.borrow().val && root.borrow().val <= high {
                sum += root.borrow().val;
            }
            if low < root.borrow().val {
                sum += Self::range_sum_bst(root.borrow().left.clone(), low, high);
            }
            if high > root.borrow().val {
                sum += Self::range_sum_bst(root.borrow().right.clone(), low, high);
            }
            return sum;
        }
        0
    }
}
