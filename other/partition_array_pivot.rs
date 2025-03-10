struct Solution;

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut greater = vec![];
        let mut same = 0;
        let ans = vec![];
        for n in nums {
            if n < pivot {
                ans.push(n);
            } else if n == pivot {
                same += 1;
            } else {
                greater.push(n);
            }
        }
        for _ in 0..same {
            ans.push(pivot);
        }
        for g in greater {
            ans.push(g);
        }
        ans
    }
}

fn main() {
    let s = Solution;
    let nums = vec![9,12,5,10,14,3,10];
    let pivot = 10;
    print!("{}", s.pivot_array(nums, pivot));
}
