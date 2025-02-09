// 2364. Count Number of Bad Pairs
use std::collections::HashMap;
struct Solution;

/*
 * you are given a 0-indexed integer array 'nums'. a pair of indices '(i, j)' is
 * a bad pair if 'i < j' and 'j - i != nums[j] - nums[i]'. return the total
 * number of bad pairs in 'nums'.
 */

impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut hm: HashMap<i32, i32> = HashMap::with_capacity(nums.len());
        let mut ans = 0;
        nums.iter().zip(0..).for_each(|(&x, i)| {
            let delta = x - i;
            let e = hm.entry(delta).or_default();
            ans += (i - *e) as i64;
            *e += 1;
        });
        ans
    }
}

fn main() {
    let n1 = vec![4, 1, 3, 3];
    let n2 = vec![1, 2, 3, 4, 5];
    println!("{}", Solution::count_bad_pairs(n1)); //expect: 5
    println!("{}", Solution::count_bad_pairs(n2)); //expect: 0
}
