struct Solution;

impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let (mut c1, mut c2) = ([0; 26], [0; 26]);
        for &b in word1.as_bytes() {
            c1[(b - b'a') as usize] += 1;
        }
        for &b in word2.as_bytes() {
            c2[(b - b'a') as usize] += 1;
        }
        if (0..26).any(|i| (c1[i] > 0) != (c2[i] > 0)) {
            return false;
        }
        c1.sort_unstable();
        c2.sort_unstable();
        c1 == c2
    }
}

fn main() {
    let word1 = String::from("abc");
    let word2 = String::from("bca");
    print!("{}", Solution::close_strings(word1, word2));
}
