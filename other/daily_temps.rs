struct Solution;

impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let n = temperatures.len();
        let mut ans: Vec<i32> = vec![0; n];
        let mut stk: Vec<usize> = Vec::new();
        for i in 0..n {
            while stk.last().map_or(false, |&v| { temperatures[v] < temperatures[i]}) {
                match stk.pop() {
                    None => break,
                    Some(idx) => ans[idx] = (i - idx) as i32
                }
            }
            stk.push(i);
        }
        ans
    }
}

fn main() {
    let t1 = vec![73,74,75,71,69,72,76,73];
    let t2 = vec![30,40,50,60];
    let t3 = vec![30,60,90];
    println!("{:?}", Solution::daily_temperatures(t1));
    println!("{:?}", Solution::daily_temperatures(t2));
    println!("{:?}", Solution::daily_temperatures(t3));
}
