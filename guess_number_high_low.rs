struct Solution;

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut s, mut n) = (1, n as i64);
        while s <= n {
            let x = (n + s) / 2;
            let g = guess(x as i32);
            match g {
                0 => return x as i32,
                1 => s = x + 1,
                -1 => n = x - 1,
                _ => unreachable!()
            }
        }
        unreachable!()
    }
}

fn main() {
    print!("{}", Solution::guessNumber(10));
}
