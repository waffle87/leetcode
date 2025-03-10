use std::collections::VecDeque;
type Tree = Vec<i32>;
struct Solution;

impl Solution {
    pub fn outer_trees(mut trees: Vec<Tree>) -> Vec<Tree> {
        fn cross(a: &Tree, b: &Tree, c: &Tree) -> i32 {
            return (c[1] - a[1]) * (a[0] - b[0]) - (a[1] - b[1]) * (c[0] - a[0])
        }
        trees.sort();
        let mut dv: VecDeque<Tree> = VecDeque::new();
        for t in trees {
            while dv.len() >= 2 && cross(&dv[dv.len() - 1], &dv[dv.len() - 2], &t) < 0 {
                dv.pop_back();
            }
            dv.push_back(t.clone());
            while dv.len() >= 2 && cross(&dv[0], &dv[1], &t) > 0 {
                dv.pop_front();
            }
            dv.push_front(t.clone());
        }
        let mut fence = Vec::from(dv);
        fence.sort_unstable();
        fence.dedup();
        fence
    }
}
