struct Solution;

impl Solution {
    pub fn orderly_queue(s: String, k: i32) -> String {
        if k == 1 {
            let ss = s.chars().chain(s.chars()).collect::<Vec<_>>();
            let mut v = ss.windows(s.len()).collect::<Vec<_>>();
            v.sort();
            v[0].iter().copied().collect()
        } else {
            let mut v = s.chars().collect::<Vec<_>>();
            v.sort();
            v.iter().collect()
        }
    }
}

fn main() {
    let s = String::from("cba");
    let k = 1;
    print!("{}", Solution::orderly_queue(s, k));
}
