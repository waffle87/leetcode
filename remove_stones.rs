use std::collections::BinaryHeap;
struct Solution;

impl Solution {
    pub fn min_stone_sum(piles: Vec<i32>, mut k: i32) -> i32 {
        let mut max_heap = BinaryHeap::<i32>::new();
        for i in piles {
            max_heap.push(i);
        }
        while k > 0 {
            if let Some(top) = max_heap.pop() {
                let removed = top - top / 2;
                max_heap.push(removed);
            }
            k -= 1;
        }
        max_heap.iter().sum()
    }
}

fn main() {
    let piles1 = vec![5,4,9];
    let piles2 = vec![4,3,6,7];
    println!("{}", Solution::min_stone_sum(piles1, 2)); //expect: 12
    println!("{}", Solution::min_stone_sum(piles2, 3)); //expect: 12
}
