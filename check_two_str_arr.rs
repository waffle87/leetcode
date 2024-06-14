struct Solution;

impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let ans: bool;
        if word1.join("") == word2.join("") {
            ans = true;
        } else {
            ans = false;
        }
        return ans;
    }
}

fn main() {
    let word1 = vec!["ab".to_string(), "c".to_string()];
    let word2 = vec!["a".to_string(), "bc".to_string()];
    print!("{}", Solution::array_strings_are_equal(word1, word2));
}
