struct Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut sp: Vec<i32> = Vec::new();
        let (mut ans, mut num, mut sign) = (0, 0, 1);
        sp.push(sign);
        for ch in s.chars() {
            match ch {
                ' ' => {}
                '+' | '-' => {
                    ans += num * sign;
                    sign = sp.last().unwrap() * if ch == '+' {1} else {-1};
                    num = 0;
                }
                '(' => {sp.push(sign);}
                ')' => {sp.pop();}
                _ => {num * 10 + (ch as i32 - '0' as i32)}
            };
        }
        ans += num * sign;
        ans
    }
}

fn main() {
    let s = String::from("1 + 1");
    print!("{}", Solution::calculate(s));
}
