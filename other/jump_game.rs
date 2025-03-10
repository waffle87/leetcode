struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut n = 1;
        for i in (0..nums.len() - 1).rev() {
            n = if nums[i] < n { n + 1 } else { 1 };
        }
        n == 1
    }
}

fn main() {
    let nums1 = vec![2,3,1,1,4];
    let nums2 = vec![3,2,1,0,4];
    println!("{}", Solution::can_jump(nums1));
    println!("{}", Solution::can_jump(nums2));
}
