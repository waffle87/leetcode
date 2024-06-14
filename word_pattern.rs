struct Solution;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        use std::collections::{HashMap, HashSet};
        if pattern.len() != s.matches(' ').count() + 1 {
            return false;
        }
        let (mut hm, mut word_set) = (HashMap::new(), HashSet::new());
        for (word, c) in s.split_ascii_whitespace().zip(pattern.chars()) {
            if let Some(w) = hm.insert(c, word) {
                if w != word {
                    return false;
                }
            } else if !word_set.insert(word) {
                return false;
            }
        }
        true
    }
}

fn main() {
    let (pattern, s) = (String::from("abba"), String::from("dog cat cat dog"));
    print!("{}", Solution::word_pattern(pattern, s));
}
