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
    pub fn leaf_similar(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut leaves1 = Vec::<i32>::new();
        Solution::get_leaves(root1, &mut leaves1);
        let mut leaves2 = Vec::<i32>::new();
        Solution::get_leaves(root2, &mut leaves2);
        leaves1 == leaves2
    }
    fn get_leaves(node: Option<Rc<RefCell<TreeNode>>>, leaves: &mut Vec<i32>) {
        if let Some(node) = node {
            let node = node.borrow();
            if node.left == None && node.right == None {
                leaves.push(node.val);
            } else {
                if let Some(ref left_node) = node.left {
                    Solution::get_leaves(Some(Rc::clone(left_node)), leaves);
                }
                if let Some(ref right_node) = node.right {
                    Solution::get_leaves(Some(Rc::clone(right_node)), leaves);
                }
            }
        }
    }
}
