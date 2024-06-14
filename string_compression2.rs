struct Solution;

impl Solution {
    pub fn get_length_of_optimal_compression(s: String, k: i32) -> i32 {
        #[inline]
        fn len_of_chars(n: i32) -> i32 {
            match n {
                1 => 1,
                2..=9 => 2,
                10..=99 => 3,
                _ => 4,
            }
        }
        fn dfs(v: &[u8], dp: &mut [[i32; 101]; 101], left: i32, k_s: i32) -> i32 {
            let mut k = k_s;
            if v.len() as i32 - left <= k {
                return 0;
            }
            if dp[left as usize][k as usize] >= 0 {
                return dp[left as usize][k as usize];
            }
            let mut ans = if k > 0 {
                dfs(v, dp, left + 1, k - 1)
            } else {
                std::i32::MAX
            };
            let mut c = 1;
            for i in left + 1..=v.len() as i32 {
                ans = ans.min(dfs(v, dp, i, k) + len_of_chars(c));
                if i == v.len() as i32 {
                    break;
                }
                if v[i as usize] == v[left as usize] {
                    c += 1;
                } else {
                    k -= 1;
                    if k < 0 {
                        break;
                    }
                }
            }
            dp[left as usize][k_s as usize] = ans;
            ans
        }
        let mut dp = [[-1; 101]; 101];
        let v = s.as_bytes();
        dfs(v, &mut dp, 0, k)
    }
}

fn main() {
    let s = String::from("aaabcccd");
    print!("{}", Solution::get_length_of_optimal_compression(s, 2));
}
