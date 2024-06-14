struct Solution;

impl Solution {
    pub fn make_good(s: String) -> String {
        let diff_cases = |c1: char, c2: char| c1.to_ascii_lowercase() == c2.to_ascii_lowercase() && c1 != c2;
        s.chars().into_iter().fold(Vec::with_capacity(s.len()), |mut v: Vec<char>, c| {
            match v.last() {
                Some(prev_c) if diff_cases(c, *prev_c) => {
                    v.pop();
                }
                _ => v.push(c)
            }
            v
        }).iter().collect()
    }
}

fn main() {
    let s = "leEeetcode".to_string();
    print!("{}", Solution::make_good(s));
}
