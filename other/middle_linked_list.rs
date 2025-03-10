#[derive(PartialEq, Eq, Clone, Debug)]
struct Solution;
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val
        }
    }
}

impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut curr = &head;
        let mut node_vec: Vec<Option<Box<ListNode>>> = vec![];
        while let Some(node) = curr.as_ref() {
            node_vec.push(Some(node.clone()));
            curr = &curr.as_ref().unwrap().next;
        }
        node_vec[node_vec.len() / 2].clone()
    }
}
