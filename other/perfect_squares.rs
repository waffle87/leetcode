use std::cmp::min;
struct Solution;

impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut dp: Vec<i32> = vec![std::i32::MAX; n as usize + 1];
        dp[0] = 0;
        for i in 1..(n as usize + 1) {
            let mut j: usize = 1;
            while j * j <= i {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
                j += 1;
            }
        }
        dp[n as usize]
    }
}

fn main() {
    print!("{}", Solution::num_squares(12));
}
