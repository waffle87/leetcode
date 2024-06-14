struct Solution;

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut ans = String::new();
        for c in s.chars() {
            if ans.len() > 0 && ans.chars().last() == Some(c) {
                ans.pop();
            } else {
                ans.push(c);
            }
        }
        ans
    }
}

fn main() {
    let s = "abbaca".to_string();
    print!("{}", Solution::remove_duplicates(s));
}
