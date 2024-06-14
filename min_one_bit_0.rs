struct Solution;

impl Solution {
    pub fn minimum_one_bit_operations(n: i32) -> i32 {
        if n <= 1 {
            return n;
        }
        let mut max = 1usize;
        while max < n as usize {
            max += max;
        }
        let mut dp = vec![0; max as usize + 1];
        dp[1] = 1;
        let (mut start, mut _i) = (2usize, 1);
        while start < max as usize {
            for i in 0..start / 2 {
                dp[start + i] = dp[start / 2 + i] + start;
                dp[start * 3 / 2 + i] = dp[i] + start;
            }
            start *= 2;
        }
        dp[max] = max * 2 - 1;
        dp[n as usize] as i32
    }
}

fn main() {
    print!("{}", Solution::minimum_one_bit_operations(39769175));
}
