//INCOMPLETE
struct Solution;

impl Solution {
    pub fn is_power_of_four(num: i32) -> bool {
        if num < 0 {
            return false;
        }
        let (ans, pos, ones) = (0, 1, 0);
        while num {
            if num & 1 {
                ans += 1;
                ones = pos;
            }
            num >>= 1;
            pos += 1;
        }
        ans == 1 && ones & 1
    }
}

fn main() {
    print!("{}", Solution::is_power_of_four(16));
}
