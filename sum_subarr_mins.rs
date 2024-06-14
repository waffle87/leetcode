use std::collections::VecDeque;
struct Solution;

impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        const MOD: i32 = 1e9 as i32 + 7;
        let n: usize = arr.len();
        let mut stk: VecDeque<isize> = {
            let mut stk: VecDeque<isize> = VecDeque::with_capacity(n);
            stk.push_back(-1);
            stk
        };
        let mut ans: i32 = 0;
        let mut dp: Vec<i32> = vec![0; n + 1];
        for i in 0..n {
            while let Some(&top) = stk.back() {
                if top != -1 && arr[i] <= arr[top as usize] {
                    stk.pop_back();
                } else {
                    break;
                }
            }
            if let Some(&top) = stk.back() {
                dp[i + 1] = (dp[top as usize + 1] + (i as i32 - top as i32) * arr[i]) % MOD;
            }
            stk.push_back(i as isize);
            ans += dp[i + 1];
            ans %= MOD;
        }
        ans
    }
}

fn main() {
    let arr = vec![3,1,2,4];
    print!("{}", Solution::sum_subarray_mins(arr));
}
