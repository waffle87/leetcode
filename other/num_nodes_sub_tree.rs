use std::collections::{HashMap, HashSet};
struct Solution;

impl Solution {
    pub fn count_sub_trees(n: i32, edges: Vec<Vec<i32>>, labels: String) -> Vec<i32> {
        let mut map = HashMap::<usize, Vec<usize>>::new();
        for e in &edges {
            map.entry(e[0] as usize).or_default().push(e[1] as usize);
            map.entry(e[1] as usize).or_default().push(e[0] as usize);
        }
        let mut visited = HashSet::<usize>::new();
        let mut ans = vec![0; n as usize];
        Self::dfs(n, &mut map, &labels, 0, &mut visited, &mut ans);
        ans
    }
    fn dfs(n: i32, map: &mut HashMap<usize, Vec<usize>>, labels: &str,
           x: usize, visited: &mut HashSet<usize>, ans: &mut Vec<i32>) -> [i32; 26] {
        let mut vec = [0;26];
        if visited.insert(x) {
            for e in map.entry(x).or_default().clone() {
                let v = Self::dfs(n, map, labels, e, visited, ans);
                for i in 0..26 {
                    vec[i] += v[i]
                }
            }
            let ch = labels.as_bytes()[x];
            vec[(ch - b'a') as usize] += 1;
            ans[x] = vec[(ch - b'a') as usize];
        }
        vec
    }
}

fn main() {
    let edges = vec![vec![0,1],vec![0,2],vec![1,4],
                     vec![1,5],vec![2,3],vec![2,6]];
    print!("{:?}", Solution::count_sub_trees(7, edges, String::from("abaedcd")));
    //expect: [2,1,1,1,1,1,1]
}
