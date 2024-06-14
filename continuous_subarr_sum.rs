use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        let mut mod_k_val = HashSet::<i32>::from([0]);
        let mut prefix_sum = nums[0] % k;
        for val in nums.into_iter().skip(1) {
            let tba = prefix_sum;
            prefix_sum = (prefix_sum + val) % k;
            if mod_k_val.contains(&prefix_sum) {
                return true;
            }
            mod_k_val.insert(tba);
        }
        false
    }
}

fn main() {
    let nums = vec![18,84,4,38,11,248];
    let k = 6;
    print!("{}", Solution::check_subarray_sum(nums, k));
}
