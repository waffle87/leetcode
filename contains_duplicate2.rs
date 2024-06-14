use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut hm = HashMap::new();
        for (i, n) in nums.iter().enumerate() {
            if let Some(j) = hm.insert(n, i) {
                if (i as i32) - (j as i32) <= k {
                    return true;
                }
            }
        }
        false
    }
}

fn main() {
    let nums = vec![1,2,3,1];
    print!("{}", Solution::contains_nearby_duplicate(nums, 3));
}
