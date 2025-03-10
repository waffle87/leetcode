use std::cmp::Reverse;
use std::collections::BinaryHeap;
#[derive(Default)]
struct MedianFinder {
    small: BinaryHeap<i32>,
    large: BinaryHeap<Reverse<i32>>,
    odd: bool
}

impl MedianFinder {
    fn new() -> Self {
        Default::default()
    }
    fn add_num(&mut self, num: i32) {
        if self.odd {
            self.small.push(num);
            if let Some(max) = self.small.pop() {
                self.large.push(Reverse(max));
            }
        } else {
            self.large.push(Reverse(num));
            if let Some(Reverse(min)) = self.large.pop() {
                self.small.push(min);;
            }
        }
        self.odd = !self.odd;
    }
    fn find_median(&self) -> f64 {
        if self.odd {
            *self.small.peek().unwrap() as f64
        } else {
            (self.small.peek().unwrap() + self.large.peek().unwrap().0) as f64 / 2.0
        }
    }
}

fn main() {
    let obj = MedianFinder::new();
    obj.add_num(num);
    let ret_2: f64 = obj.find_median();
}
