use std::collections::VecDeque;
struct Solution;

impl Solution {
    pub fn can_reach(arr: Vec<i32>, start: i32) -> bool {
        let mut arr = arr;
        let mut vd: VecDeque<i32> = VecDeque::with_capacity(arr.len());
        vd.push_back(start);
        while let Some(front) = vd.pop_front() {
            match arr[front as usize].cmp(&0) {
                std::cmp::Ordering::Less => continue,
                std::cmp::Ordering::Equal => return true,
                std::cmp::Ordering::Greater => {
                    if front - arr[front as usize] >= 0 {
                        vd.push_back(front - arr[front as usize]);
                    }
                    if front + arr[front as usize] < arr.len() as i32 {
                        vd.push_back(front + arr[front as usize]);
                    }
                    arr[front as usize] = -1;
                }
            }
        }
        false
    }
}

fn main() {
    let arr1 = vec![4,2,3,0,3,1,2];
    let arr2 = vec![4,2,3,0,3,1,2];
    let arr3 = vec![3,0,2,1,2];
    println!("{}", Solution::can_reach(arr1, 5)); //true
    println!("{}", Solution::can_reach(arr2, 0)); //true
    println!("{}", Solution::can_reach(arr3, 2)); //false
}
