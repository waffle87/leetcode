struct Solution;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let (mut counter, mut set) = ([0; 2001], [false; 1000]);
        arr.iter().for_each(|&x| counter[(x + 1000) as usize] += 1);
        for &x in counter.iter().filter(|&&x| x > 0) {
            match set[x as usize] {
                true => return false,
                false => set[x as usize] = true
            }
        }
        true
    }
}

fn main() {
    let arr = vec![1,2,2,1,1,3];
    print!("{}", Solution::unique_occurrences(arr));
}
