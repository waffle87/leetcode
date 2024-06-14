struct Solution;

impl Solution {
    pub fn max_ice_cream(costs: Vec<i32>, coins: i32) -> i32 {
        let (mut bars, mut coins, mut price, mut count) =
            ([0_u32; 100_001], coins, 1, 0);
        costs.into_iter().for_each(|c| bars[c as usize] += 1);
        while coins >= price && price <= 100_000 {
            while bars[price as usize] > 0 && coins >= price {
                bars[price as usize] -= 1;
                coins -= price;
                count += 1;
            }
            price += 1;
        }
        count
    }
}

fn main() {
    let costs1 = vec![1,3,2,4,1];
    let costs2 = vec![10,6,8,7,7,8];
    let costs3 = vec![1,6,3,1,2,5];
    println!("{}", Solution::max_ice_cream(costs1, 7)); //expect: 4
    println!("{}", Solution::max_ice_cream(costs2, 5)); //expect: 0
    println!("{}", Solution::max_ice_cream(costs3, 20)); //expect: 6
}
