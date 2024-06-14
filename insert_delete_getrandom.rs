extern crate rand;
use rand::{Rng, thread_rng, rngs::ThreadRng};
use std::collections::HashMap;

struct RandomizedSet {
    rng: ThreadRng,
    data: Vec<i32>,
    idx_map: HashMap<i32, usize>
}

impl RandomizedSet {
    fn new() -> Self {
        Self {
            rng: thread_rng(),
            data: vec![],
            idx_map: HashMap::new()
        }
    }
    fn insert(&mut self, val: i32) -> bool {
        if self.idx_map.contains_key(&val) {
            return false;
        }
        self.idx_map.insert(val, self.data.len());
        self.data.push(val);
        true
    }
    fn remove(&mut self, val: i32) -> bool {
        if self.idx_map.contains_key(&val) == false {
            return false;
        }
        let i = self.idx_map.remove(&val).unwrap();
        if i != self.data.len() - 1 {
            self.data[i] = self.data[self.data.len() - 1];
            (*self.idx_map.get_mut(&self.data[i]).unwrap()) = i;
        }
        self.data.pop();
        true
    }
    fn get_random(&mut self) -> i32 {
        if self.data.len() == 0 {
            panic!(":P")
        }
        self.data[self.rng.gen_range(0, self.data.len())]
    }
}

fn main() {
    let obj = RandomizedSet::new();
    let ret_1: bool = obj.insert(2);
    let ret_2: bool = obj.remove(1);
    let ret_3: i32  = obj.get_random();
    println!("param_1 (insert 2): {}", ret_1);
    println!("param_2 (remove 1): {}", ret_2);
    print!("param_3 (get_random): {}", ret_3);
}
