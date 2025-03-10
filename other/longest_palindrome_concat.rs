struct Solution;

impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let (mut hist, mut ans, a_code) = (vec![vec![0; 26];26], 0, 'a' as usize);
        for w in words.iter() {
            if let Some(i) = w.chars().nth(0) {
                if let Some(j) = w.chars().nth(1) {
                    let i = i as usize - a_code;
                    let j = j as usize - a_code;
                    match hist[j][i] {
                        cnt if cnt > 0 => {
                            ans += 4;
                            hist[j][i] -= 1;
                        },
                        _ => {
                            hist[i][j] += 1;
                        }
                    }
                }
            }
        }
        for i in 0..26 {
            match hist[i][i] {
                cnt if cnt > 0 => {
                    ans += 2;
                    break;
                },
                _ => (),
            }
        }
        ans
    }
}

fn main() {
    let words = vec!["lc".to_string(), "cl".to_string(), "gg".to_string()];
    print!("{}", Solution::longest_palindrome(words));
}
