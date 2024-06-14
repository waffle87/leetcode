struct Solution;

impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut map = std::collections::HashMap::with_capacity(26 * 2);
        s.chars().for_each(|b| * map.entry(b).or_insert(0) += 1);
        let mut v = map.into_iter().map(|(c, n)| (c, n)).collect::<Vec<_>>();
        v.sort_unstable_by_key(|pair| - pair.1);
        v.into_iter().flat_map(|(c, n)| vec![c; n as usize]).collect()
    }
}

fn main() {
    let s = String::from("tree");
    print!("{}", Solution::frequency_sort(s));
}
