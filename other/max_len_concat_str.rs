struct Solution;

impl Solution {
    pub fn max_length(arr: Vec<String>) -> i32 {
        let mut ans: u32 = 0;
        let mut unique: Vec<u32> = Vec::new();
        for s in arr {
            let bin: u32 = s.bytes().map(|c| 1 << (c - b'a')).sum();
            if bin.count_ones() == s.len() as u32 {
                unique.push(bin);
            }
        }
        let mut concat: Vec<u32> = vec![0];
        for u in unique {
            for i in 0..concat.len() {
                if (concat[i] & u).count_ones() == 0 {
                    concat.push(concat[i] | u);
                    ans = ans.max(concat[i].count_ones() + u.count_ones());
                }
            }
        }
        ans as i32
    }
}

fn main() {
    let arr = vec!["un".to_string(),"iq".to_string(),"ue".to_string()];
    print!("{}", Solution::max_length(arr));
}
