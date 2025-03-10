struct Solution;

impl Solution {
    pub fn maximum_bags(capacity: Vec<i32>, rocks: Vec<i32>, mut additional_rocks: i32) -> i32 {
        let mut bag_space = (0..rocks.len()).map(|i| capacity[i] - rocks[i])
                                            .filter(|&d| d > 0)
                                            .collect::<Vec<_>>();
        let bag_full = rocks.len() - bag_space.len();
        bag_space.sort_unstable();
        bag_space.into_iter()
                 .take_while(|&n| { additional_rocks -= n; additional_rocks >= 0 })
                 .count() as i32 + bag_full as i32
    }
}

fn main() {
    let capacity = vec![2,3,4,5];
    let rocks = vec![1,2,4,4];
    print!("{}", Solution::maximum_bags(capacity, rocks, 2)); //expect: 3
}
