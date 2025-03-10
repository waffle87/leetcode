use std::convert::TryInto;
struct Solution;

impl Solution {
    pub fn remove_element(mut nums: Vec<i32>, val: i32) -> i32 {
        let (mut idx, mut k) = (0, nums.len());
        while idx < k {
            if nums[idx] == val {
                nums[idx] = nums[k - 1];
                k -= 1;
            } else {
                idx += 1;
            }
        }
        k.try_into().unwrap()
    }
}

fn main() {
    let nums = vec![0,1,2,2,3,0,4,2];
    print!("{}", Solution::remove_element(nums, 2));
}
