use std::collections::HashMap;
struct Solution;

#[derive(PartialEq, Eq, Hash, Copy, Clone)]
enum Invested {
    Yes, No, Cooldown
}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        Self::dp(&prices, 0, Invested::No, &mut HashMap::new())
    }
    fn dp(prices: &[i32], day: usize, invested: Invested, memo: &mut HashMap<(usize, Invested), i32>) -> i32 {
        if day == prices.len() {
            0
        } else if let Some(profit) = memo.get(&(day, invested)) {
            *profit
        } else {
            let ans = match invested {
                Invested::Yes => Self::dp(prices, day + 1, invested, memo).max(prices[day] + Self::dp(prices, day + 1, Invested::Cooldown, memo)),
                Invested::No => Self::dp(prices, day + 1, invested, memo).max(-prices[day] + Self::dp(prices, day + 1, Invested::Yes, memo)),
                Invested::Cooldown => Self::dp(prices, day + 1, Invested::No, memo)
            };
            memo.insert((day, invested), ans);
            ans
        }
    }
}

fn main() {
    let prices = vec![1,2,3,0,2];
    print!("{}", Solution::max_profit(prices));
}
