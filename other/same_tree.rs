use std::rc::Rc;
use std::cell::Ref;
use std::cell::RefCell;
use std::collections::VecDeque;
type NodeRef = Option<Rc<RefCell<TreeNode>>>;
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: NodeRef,
    pub right: NodeRef
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

struct Solution;

impl Solution {
    pub fn is_same_tree(p: NodeRef, q: NodeRef) -> bool {
        //p == q
        let mut dq: VecDeque<(NodeRef, NodeRef)> = VecDeque::new();
        match (p, q) {
            (Some(p), Some(q)) => {
                dq.push_back((Some(Rc::clone(&p)), Some(Rc::clone(&q))));
            }
            (None, None) => return true,
            _ => return false
        }
        while !dq.is_empty() {
            let (p, q) = dq.pop_front().unwrap();
            if !match (&p, &q) {
                (Some(p), Some(q)) => p.borrow().val == q.borrow().val,
                (None, None) => true,
                _ => false
            } {
                return false;
            }
            if let (Some(p), Some(q)) = (p, q) {
                let (p, q) = (
                    Solution::clone_nodes(p.borrow()),
                    Solution::clone_nodes(q.borrow())
                );
                dq.push_back((p.0, q.0));
                dq.push_back((p.1, q.1));
            }
        }
        true
    }
    fn clone_nodes(tree: Ref<TreeNode>) -> (NodeRef, NodeRef) {
        (
        if tree.left.is_some() {
            Some(Rc::clone(tree.left.as_ref().unwrap()))
        } else {
            None
        },
        if tree.right.is_some() {
            Some(Rc::clone(tree.right.as_ref().unwrap()))
        } else {
            None
        }
        )
    }
}
