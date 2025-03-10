use std::collections::VecDeque;
struct Solution;

impl Solution {
    pub fn possible_bipartition(n: i32, dislikes: Vec<Vec<i32>>) -> bool {
        let mut dmap: Vec<Vec<usize>> = vec![vec![]; n as usize];
        for d in dislikes.iter() {
            dmap[d[0] as usize - 1].push(d[1] as usize - 1);
            dmap[d[1] as usize - 1].push(d[0] as usize - 1);
        }
        let mut v: Vec<Option<bool>> = vec![None; n as usize];
        for i in 0..n as usize {
            if v[i].is_some() {
                continue;
            }
            let mut vd: VecDeque<(usize, bool)> = VecDeque::new();
            vd.push_back((i, true));
            while let Some(last) = vd.pop_front() {
                if let Some(b) = v[last.0] {
                    if b != last.1 {
                        return false;
                    }
                    continue;
                }
                v[last.0] = Some(last.1);
                for j in dmap[last.0].iter() {
                    if v[*j].is_none() {
                        vd.push_back((*j, !last.1));
                    }
                }
            }
        }
        true
    }
}

fn main() {
    let dislikes = vec![vec![1,2], vec![1,3], vec![2,4]];
    print!("{}", Solution::possible_bipartition(4, dislikes));
}
