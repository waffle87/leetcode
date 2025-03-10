use std::collections::BTreeMap;
struct Solution;

impl Solution {
    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut lost: BTreeMap<i32, i32> = matches.into_iter().fold(BTreeMap::new(), |mut hm, m| {
            hm.entry(m[0]).or_insert(0);
            *hm.entry(m[1]).or_insert(0) += 1;
            hm
        });
        return vec![lost.iter().filter(|(_, l)| **l == 0).map(|(&i, _)| i).collect(),
                    lost.iter().filter(|(_, l)| **l == 1).map(|(&i, _)| i).collect()];
    }
}
