struct Solution;

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut s: Vec<char> = s.trim().chars().rev().collect();
        s.push(' ');
        let mut i: usize = 0;
        for j in 0..s.len() {
            if s[j] == ' ' {
                s[i..j].reverse();
                i = j + 1;
            }
        }
        s.pop();
        let mut i = 1;
        for j in 1..s.len() {
            if s[j] == ' ' && s[j - 1] == ' ' {
                continue;
            }
            s[i] = s[j];
            i += 1;
        }
        s.truncate(i);
        s.into_iter().collect()
    }
}

fn main() {
    let s = "the sky is blue".to_string();
    print!("{}", Solution::reverse_words(s));
}
