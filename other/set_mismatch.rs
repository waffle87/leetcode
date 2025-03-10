struct Solution;

impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut xor = nums.iter().zip(1..=nums.len() as i32).fold(0, |acc, (&num, i)| acc ^ num ^ i);
        xor &= -xor;
        let (mut n0, mut n1) = (0, 0);
        for &n in &nums {
            if n & xor == 0 {
                n0 ^= n;
            } else {
                n1 ^= n;
            }
        }
        for i in 1..=nums.len() as i32 {
            if i & xor == 0 {
                n0 ^= i;
            } else {
                n1 ^= i;
            }
        }
        for &n in &nums {
            if n == n0 {
                return vec![n0, n1];
            }
            if n == n1 {
                return vec![n1, n0];
            }
        }
        unreachable!()
    }
}

fn main() {
    let nums = vec![1,2,2,4];
    print!("{:?}", Solution::find_error_nums(nums));
}
