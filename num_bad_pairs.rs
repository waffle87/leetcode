use std::collections::HashMap;
struct Solution;

/*
 * given: 0-indexed integer array
 * bad pair: (i, j) if
 * i < j && j - i != nums[j] - nums[i]
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
    let nums1 = vec![4,1,3,3];
    let nums2 = vec![1,2,3,4,5];
    println!("{}", Solution::count_bad_pairs(nums1)); //expect: 5
    println!("{}", Solution::count_bad_pairs(nums2)); //expect: 0
}
