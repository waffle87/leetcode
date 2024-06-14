use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut groups = HashMap::new();
        for s in strs {
            let hash = s.bytes().fold([0;26], |mut h, b| {
                h[(b - b'a') as usize] += 1; h
            });
            groups.entry(hash).or_insert_with(Vec::new).push(s);
        }
        groups.into_values().collect()
    }
}
