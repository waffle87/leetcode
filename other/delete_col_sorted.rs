struct Solution;

impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut new_strs: Vec<Vec<char>> = Vec::new();
        for i in 0..strs.len() {
            new_strs.push(strs[i].chars().collect::<Vec<char>>());
        }
        for i in 0..new_strs[0].len() {
            for j in 1..new_strs.len() {
                if new_strs[j - 1][i] > new_strs[j][i] {
                    ans += 1;
                    break
                }
            }
        }
        ans
    }
}

fn main() {
    let strs = vec![String::from("cba"), String::from("daf"), String::from("ghi")];
    print!("{}", Solution::min_deletion_size(strs));
}
