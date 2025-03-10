use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn minimum_rounds(tasks: Vec<i32>) -> i32 {
        let (mut map, mut ans) = (HashMap::new(), 0);
        for t in tasks {
            let val = map.get_mut(&t);
            if let Some(v) = val {
                *v += 1;
            } else {
                map.insert(t, 1);
            }
        }
        for c in map.into_values() {
            if c == 1 {
                return -1;
            }
            ans += (c + 2) / 3;
        }
        ans
    }
}

fn main() {
    let tasks1 = vec![2,2,3,3,2,4,4,4,4,4];
    let tasks2 = vec![2,3,3];
    println!("{}", Solution::minimum_rounds(tasks1));
    println!("{}", Solution::minimum_rounds(tasks2));
}
