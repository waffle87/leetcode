//2442. Count Number of Distinct Integers After Reverse Operations
use std::collections::HashSet;
struct Solution;

/*
 * array nums contains positive integers
 * take each integer in array and reverse its digits (eg. 13 -> 31)
 * then *add* it to end of array. return number of distinct integers.
 * [1,13,10,12,31] becomes [1,13,10,12,31,1,31,1,21,13]
 * and total num of distinct ints = 6
 */

impl Solution {
    pub fn count_distinct_integers(nums: Vec<i32>) -> i32 {
        let mut hs: HashSet<i32> = nums.iter().map(|&n| Self::reverse(n)).collect();
        hs.extend(nums.iter());
        hs.len() as i32
    }
    fn reverse(mut n: i32) -> i32 {
        let mut rev: i32 = 0;
        while n > 0 {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        rev
    }
}

fn main() {
    let nums1 = vec![1,13,10,12,31];
    let nums2 = vec![2,2,2];
    println!("{}", Solution::count_distinct_integers(nums1)); //expect: 6
    println!("{}", Solution::count_distinct_integers(nums2)); //expect: 1
}
