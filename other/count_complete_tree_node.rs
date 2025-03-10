#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<RC<RefCell<TreeNode>>>,
    pub right: Option<RC<RefCell<TreeNode>>>
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
    pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(r) = root {
            let ld = {
                let mut h = 1;
                let mut node = r.borrow().left.clone();
                while let Some(n) = node {
                    h += 1;
                    node = n.borrow().left.clone();
                }
                h
            };
            let rd = {
                let mut h = 1;
                let mut node = r.borrow().right.clone();
                while let Some(n) = node {
                    h += 1;
                    node = n.borrow().right.clone();
                }
                h
            };
            if ld == rd {
                2i32.pow(ld) - 1
            } else {
                1 + Solution::count_nodes(r.borrow().left.clone()) + Solution::count_nodes(r.borrow().right.clone())
            }
        } else {
            0
        }
    }
}
