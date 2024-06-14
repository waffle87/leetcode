use std::collections::BinaryHeap;
use std::cmp::Ordering;
struct Solution;
#[derive(PartialEq, Eq, Copy, Clone)]
struct Task {
    pub enqueue_time: i32,
    pub processing_time: i32,
    pub initial_idx: usize
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if other.processing_time == self.processing_time {
            return Some(other.initial_idx.cmp(&self.initial_idx));
        }
        Some(other.processing_time.cmp(&self.processing_time))
    }
}

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if other.processing_time == self.processing_time {
            return other.initial_idx.cmp(&self.initial_idx);
        }
        other.processing_time.cmp(&self.processing_time)
    }
}

impl Solution {
    pub fn get_order(tasks: Vec<Vec<i32>>) -> Vec<i32> {
        let mut tasks = tasks.into_iter().enumerate().map(|(idx, task)| {
            Task {
                enqueue_time: task[0],
                processing_time: task[1],
                initial_idx: idx
            }
        }).collect::<Vec<Task>>();
        let (mut output, mut current_time) = (vec![], 0);
        let mut available_tasks: BinaryHeap<Task> = BinaryHeap::new();
        while tasks.len() > 0 || available_tasks.len() > 0 {
            while tasks.len() > 0 && tasks[tasks.len() - 1].enqueue_time <= current_time {
                let task = tasks.pop().unwrap();
                available_tasks.push(task);
            }
            if let Some(task) = available_tasks.pop() {
                output.push(task.initial_idx as i32);
                current_time += task.processing_time;
            } else {
                current_time = tasks[tasks.len() - 1].enqueue_time;
            }
        }
        output
    }
}

fn main() {
    let tasks = vec![vec![1,2],vec![2,4],vec![3,2],vec![4,1]];
    print!("{:?}", Solution::get_order(tasks));
}
