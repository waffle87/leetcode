use std::collections::BinaryHeap;
use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let mut word_to_freq = HashMap::<String, i32>::new();
        for w in words {
            *word_to_freq.entry(w).or_default() += 1;
        }
        let mut heap = BinaryHeap::<(i32, String)>::new();
        for (word, freq) in word_to_freq {
            heap.push((-freq, word));
            if heap.len() > k as usize {
                heap.pop();
            }
        }
        let mut ans: Vec<String> = vec![];
        while let Some((_freq, word)) = heap.pop() {
            ans.push(word);
        }
        ans.reverse();
        ans
    }
}
