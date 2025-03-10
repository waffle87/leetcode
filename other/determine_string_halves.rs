use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let vowels: HashSet<char> = HashSet::from(['a','e','i','o','u','A','E','I','O','U']);
        s.chars()
        .enumerate()
        .filter(|(_, c)| vowels.contains(c))
        .map(|(i, _)| (s.len() as i32 - 2 * (i as i32) - 1).signum())
        .sum::<i32>() == 0
    }
}

fn main() {
    let s = String::from("book");
    print!("{}", Solution::halves_are_alike(s));
}
