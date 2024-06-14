struct Solution;

impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let (mut x, mut y, mut z) = (-1, 0, 1);
        for _ in 1..=n {
            let curr = (2 * z % MOD + x) % MOD;
            x = y;
            y = z;
            z = curr;
        }
        z
    }
}

fn main() {
    println!("{}", Solution::num_tilings(3)); // 5
    println!("{}", Solution::num_tilings(1)); // 1
}
