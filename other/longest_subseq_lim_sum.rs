struct Solution;

impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>, queries: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable();
        nums.iter_mut().fold(0, |acc, x| { *x += acc; *x});
        queries.iter().map(|x|
            nums.binary_search(x).unwrap_or_else(|i| i - 1) as i32 + 1
        ).collect()
    }
}

fn main() {
    let nums = vec![4,5,2,1];
    let queries = vec![3,10,21];
    print!("{:?}", Solution::answer_queries(nums, queries));
}
