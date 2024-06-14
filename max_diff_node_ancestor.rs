use std::cmp;
use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>
}

struct MinMax {
    min: i32,
    max: i32,
    ans: i32
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

impl Solution {
    fn minMax(node_ref: Rc<RefCell<TreeNode>>) -> MinMax {
        let node = node_ref.borrow();
        let mut a = MinMax {
            min: node.val,
            max: node.val,
            ans: 0
        };
        if node.left.is_none() && node.right.is_none() {
            a
        }  else {
            let children = vec![&node.left, &node.right];
            for child_option in children.iter() {
                if let Some(child) = child_option {
                    let c = Self::minMax(Rc::clone(&child));
                    a.ans = cmp::max(a.ans, c.ans);
                    a.ans = cmp::max(a.ans, (node.val - c.min).abs());
                    a.ans = cmp::max(a.ans, (node.val - c.max).abs());
                    a.min = cmp::min(a.min, c.min);
                    a.max = cmp::max(a.max, c.max);
                }
            }
            a
        }
    }
    pub fn max_ancestor_diff(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(node_ref) = root {
            Self::minMax(Rc::clone(&node_ref)).ans
        } else {
            panic!("bad input");
        }
    }
}
