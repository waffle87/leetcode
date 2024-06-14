struct Solution;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut n = nums;
        n.sort();
        let mut tmp = vec![n[0]];
        for i in 1..n.len() {
            if tmp.len() == 0 || tmp[tmp.len() - 1] != n[i] {
                tmp.push(n[i]);
            } else {
                tmp.pop();
            }
        }
        tmp[0]
    }
}

fn main() {
    let nums = vec![2,2,1];
    print!("{}", Solution::single_number(nums));
}
