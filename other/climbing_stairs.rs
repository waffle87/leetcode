struct Solution;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let (mut ans, mut i) = ([2, 1], 3);
        while i <= n as usize {
            ans[i & 0b01] = ans[0] + ans[1];
            i += 1;
        }
        ans[n as usize & 0b01]
    }
}

fn main() {
    print!("{}", Solution::climb_stairs(2));
}
