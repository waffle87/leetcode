use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn min_mutation(start: String, end: String, mut bank: Vec<String>) -> i32 {
        match bank.iter().position(|w| end.eq(w)) {
            None => return -1,
            Some(idx) => bank.swap_remove(idx)
        };
        let (mut left, mut right, mut next) = (HashSet::new(), HashSet::new(), HashSet::new());
        left.insert(start);
        right.insert(end);
        let mut len = 0;
        while !left.is_empty() && !right.is_empty() {
            if left.len() > right.len() {
                std::mem::swap(&mut left, &mut right);
            }
            for w in left.drain() {
                let mut idx = 0;
                for word in right.iter() {
                    if Self::is_adjacent(&w, word.as_str()) {
                        return len + 1;
                    }
                }
                while idx < bank.len() {
                    if !is_adjacent(&w, &bank[idx]) {
                        idx += 1;
                        continue;
                    }
                    let neighbor = bank.swap_remove(idx);
                    next.insert(neighbor);
                }
            }
            std::mem::swap(&mut left, &mut next);
            len += 1;
        }
        -1
    }
    fn is_adjacent(a: &str, b: &str) -> bool {
        let (a, b) = (a.as_bytes(), b.as_bytes());
        assert_eq!(a.len(), b.len());
        let mut diff = 0;
        for idx in 0..a.len() {
            if a[idx] != b[idx] {
                diff += 1;
            }
            if diff > 1 {
                break;
            }
        }
        diff == 1
    }
}
