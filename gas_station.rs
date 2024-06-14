struct Solution;

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let (mut sum, mut idx, mut min) = (0, 0, 0);
        for i in 0..gas.len() {
            sum += gas[i] - cost[i];
            if sum < min {
                min = sum;
                idx = i + 1;
            }
        }
        if sum < 0 {
            -1
        } else {
            idx as i32
        }
    }
}

fn main() {
    let (gas1, gas2) = (vec![1,2,3,4,5], vec![2,3,4]);
    let (cost1, cost2) = (vec![3,4,5,1,2], vec![3,4,3]);
    println!("{}", Solution::can_complete_circuit(gas1, cost1)); //expect: 3
    println!("{}", Solution::can_complete_circuit(gas2, cost2)); //expect: -1
}
