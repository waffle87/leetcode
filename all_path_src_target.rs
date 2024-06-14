use std::collections::VecDeque;
struct Solution;

impl Solution {
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (src, dst, mut rev) = (0, (graph.len() - 1) as i32, vec![0; graph.len()]);
        for (u, adj) in graph.iter().enumerate() {
            for &v in adj {
                rev[v as usize] += 1;
            }
        }
        let mut top_sort_q = VecDeque::new();
        for v in 0..graph.len() {
            if rev[v] == 0 {
                top_sort_q.push_back(v as i32);
            }
        }
        let mut ans = vec![vec![]; graph.len()];
        while let Some(v) = top_sort_q.pop_front() {
            if v == src {
                ans[src as usize].push(vec![src])
            }
            if v == dst {
                break;
            }
            for &next in graph[v as usize].iter() {
                let (ans_v, ans_next) = {
                    if v < next {
                        let (ans_left, ans_right) = ans.split_at_mut(v as usize + 1);
                        (&ans_left[v as usize], &mut ans_right[(next - v - 1) as usize])
                    } else {
                        let (ans_left, ans_right) = ans.split_at_mut(next as usize + 1);
                        (&ans_right[(v - next - 1) as usize], &mut ans_left[next as usize])
                    }
                };
                for path in ans_v {
                    let mut new_path = path.clone();
                    new_path.push(next);
                    ans_next.push(new_path);
                }
                rev[next as usize] -= 1;
                if rev[next as usize] == 0 {
                    top_sort_q.push_back(next);
                }
            }
        }
        std::mem::take(&mut ans[dst as usize])
    }
}

fn main() {
    let graph = vec![vec![1,2],vec![3],vec![3],vec![]];
    print!("{:?}", Solution::all_paths_source_target(graph));
}
