pub struct Solution;
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> self {
        ListNode {
            next: None,
            val
        }
    }
}

impl Solution {
    pub fn delete_middle(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut slowPtr = &head;
        let mut fastPtr = &head;
        let mut fakeHead = Box::new(ListNode::new(-1));
        let mut fakeTmp = &mut *fakeHead as *mut ListNode;
        let mut slowPrevPtr = &mut *fakeHead as *mut ListNode;
        while fastPtr.is_some() && (fastPtr).as_ref().unwrap().next.is_some() {
            unsafe {
                let mut next = Box::new(ListNode::new((slowPtr).as_ref().unwrap().val));
                let nextPtr = &mut *next as *mut ListNode;
                (*fakeTmp).next = Some(next);
                slowPrevPtr = fakeTmp;
                fakeTmp = nextPtr;
                slowPtr = &(slowPtr).as_ref().unwrap().next;
                fastPtr = &(fastPtr).as_ref().unwrap().next;
                if fastPtr.is_some() {
                    fastPtr = &(fastPtr).as_ref().unwrap().next;
                }
            }
        }
        slowPtr = &(slowPtr).as_ref().unwrap().next;
        while slowPtr.is_some() {
            unsafe {
                let mut next = Box::new(ListNode::new((slowPtr).as_ref().unwrap().val));
                let nextPtr = &mut *next as *mut ListNode;
                (*fakeTmp).next = Some(next);
                fakeTmp = nextPtr;
                slowPtr = &(slowPtr).as_ref().unwrap().next;
            }
        }
        fakeHead.next
    }
}

fn main() {}
