struct Solution;

impl Solution {
    pub fn minimum_average_difference(nums: Vec<i32>) -> i32 {
        let (mut left, mut ans, mut min) = (0, 0, i64::MAX);
        let mut right = nums.iter().map(|&x| x as i64).sum::<i64>();
        for i in 0..nums.len() {
            left += nums[i] as i64;
            right -= nums[i] as i64;
            let diff = (left / (i + 1) as i64 - right / 1i64.max((nums.len() - i - 1) as i64)).abs();
            if diff < min {
                ans = i as i32;
                min = diff;
            }
        }
        ans
    }
}

fn main() {
    let nums = vec![2,5,3,9,5,3];
    print!("{}", Solution::minimum_average_difference(nums));
}
