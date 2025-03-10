#[derive(PartialEq, Eq, Clone, Debug)]
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
    pub fn odd_even_list(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut odd_dummy_head = ListNode::new(-1);
        let mut even_dummy_head = ListNode::new(-1);
        let mut odd_curr = &mut odd_dummy_head;
        let mut even_curr = &mut even_dummy_head;
        let mut is_even = false;
        while let Some(mut node) = head {
            head = std::mem::replace(&mut node.next, None);
            if is_even {
                even_curr.next = Some(node);
                even_curr = even_curr.next.as_mut().unwrap();
            } else {
                odd_curr.next = Some(node);
                odd_curr = odd_curr.next.as_mut().unwrap();
            }
            is_even = !is_even;
        }
        odd_curr.next = even_dummy_head.next;
        odd_dummy_head.next
    }
}
