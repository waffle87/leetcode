struct Solution;

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let (mut i, mut j) = (0, s.len().checked_sub(1).unwrap_or(0));
        let mut cs = s.chars().collect::<Vec<char>>();
        while i < j {
            if !Self::is_vowel(cs[i].to_ascii_lowercase()) {
                i += 1;
                continue
            }
            if !Self::is_vowel(cs[j].to_ascii_lowercase()) {
                j -= 1;
                continue
            }
            cs.swap(i, j);
            i += 1;
            j -= 1;
        }
        cs.iter().collect()
    }
    fn is_vowel(c: char) -> bool {
        match c {
            'a' | 'e' | 'i' | 'o' | 'u' => true,
            _ => false
        }
    }
}

fn main() {
    let s = "hello".to_string();
    print!("{}", Solution::reverse_vowels(s));
}
