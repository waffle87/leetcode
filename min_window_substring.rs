struct Solution;

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let mut state = [0 as isize; (b'z' - b'A' + 1) as usize];
        let mut target = [0 as isize; (b'z' - b'A' + 1) as usize];
        for b in t.bytes() {
            target[(b - b'A') as usize] += 1;
        }
        let (target, string, mut best_from, mut best_to, mut from, mut to, mut chars_found, chars_expected) =
            (target, s.as_bytes(), 0, 0, 0, 0, 0, target.iter().filter(|&&ch| ch > 0).count());
        while to < string.len() {
            let ch = (string[to] - b'A') as usize;
            if target[ch] > 0 {
                if state[ch] + 1 == target[ch] {
                    chars_found += 1;
                }
                state[ch] += 1;
            }
            if chars_found == chars_expected {
                let mut fch = (string[from] - b'A') as usize;
                while target[fch] == 0 || state[fch] > target[fch] {
                    if state[fch] > 0 {
                        state[fch] -= 1;
                    }
                    from += 1;
                    fch = (string[from] - b'A') as usize;
                }
                if to - from < best_to - best_from || best_to == 0 {
                    best_from = from;
                    best_to = to + 1;
                }
            }
            to += 1;
        }
        s[best_from..best_to].to_string()
    }
}

fn main() {
    let (s, t) = (String::from("ADOBECODEBANC"), String::from("ABC"));
    print!("{}", Solution::min_window(s, t));
}
