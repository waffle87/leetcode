//347. Top K Frequent Elements
struct Solution;

/*
* given an integer array 'nums' and an integer 'k', return the 'k' most frequent elements. you may
* return the answer in any order.
*/

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::new();
        for x in nums {
            *map.entry(x).or_insert(0) += 1;
        }
        let mut arr = map.into_iter().collect::<Vec<(i32,i32)>>();
        arr.sort_by(|a,b| 1.1.cmp(&b.1));
        arr.reverse();
        let k = k as usize;
        let mut ans = vec![0;k];
        for i in 0..k {
            ans[i] = arr[i].0;
        }
        ans
    }
}

fn main() {
    let n1 = vec![1,1,1,2,2,3];
    let n2 = vec![1];
    print!("{}", Solution::top_k_frequent(n1, 2)); //expect: [1,2]
    print!("{}", Solution::top_k_frequent(n2, 1)); //expect: [1]
}
