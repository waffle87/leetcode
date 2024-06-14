struct Solution;

impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut bit_mask: u32 = 0;
        let mut count = 0;
        for c in sentence.chars() {
            let idx = c as usize - 'a' as usize;
            if bit_mask & (1 << idx) == 0 {
                count += 1;
            }
            bit_mask |= 1 << idx;
        }
        count == 26
    }
}

fn main() {
    let sentence = String::from("thequickbrownfoxjumpsoverthelazydog");
    print!("{}", Solution::check_if_pangram(sentence));
}
