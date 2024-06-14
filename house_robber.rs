struct Solution;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let (mut prev, mut prev2) = (0,0);
        for n in nums {
            let curr = std::cmp::max(n + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        prev
    }
}

fn main() {
    let nums = vec![1,2,3,1];
    print!("{}", Solution::rob(nums)); //expect 4
}
