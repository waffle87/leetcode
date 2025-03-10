struct Solution;

impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        num.to_string().replacen("6", "9", 1).parse().unwrap()
    }
}

fn main() {
    print!("{}", Solution::maximum69_number(9669));
}
