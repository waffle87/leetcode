struct Solution;

impl Solution {
    fn is_palindrome(mut x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let mut nums = Vec::with_capacity(10);
        while x != 0 {
            nums.push(x % 10);
            x /= 10;
        }
        for i in 0..(nums.len() / 2) {
            if nums[i] != nums[nums.len() - i - 1] {
                return false;
            }
        }
        true
    }
}

fn main() {
    print!("{}", Solution::is_palindrome(121));
}
