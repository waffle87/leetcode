use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn min_time(n: i32, edges: Vec<Vec<i32>>, has_apple: Vec<bool>) -> i32 {
        let mut adj_list: Vec<Vec<i32>> = vec![vec![]; n as usize];
        for e in edges {
            adj_list[e[0] as usize].push(e[1]);
            adj_list[e[1] as usize].push(e[0]);
        }
        let mut total = 0i32;
        let mut vis: HashSet<i32> = HashSet::new();
        Self::dfs(0, adj_list, &mut vis, has_apple, &mut total);
        total
    }
    fn dfs(node: i32, adj_list: Vec<Vec<i32>>, vis: &mut HashSet<i32>,
           has_apple: Vec<bool>, total: &mut i32) -> bool {
        let mut res = false;
        if has_apple[node as usize] {
            res = true;
        }
        vis.insert(node);
        for i in &adj_list[node as usize] {
            if !vis.contains(&i) {
                if Self::dfs(*i, adj_list, vis, has_apple, total) {
                    *total += 2;
                    res = true;
                }
            }
        }
        res
    }
}

fn main() {
    let edges = vec![
        vec![0,1], vec![0,2],
        vec![1,4], vec![1,5],
        vec![2,3], vec![2,6]
    ];
    let has_apple1 = vec![false,false,true,false,true,true,false];
    let has_apple2 = vec![false,false,true,false,false,true,false];
    let has_apple3 = vec![false,false,false,false,false,false,false];
    println!("{}", Solution::min_time(7, edges, has_apple1)); //expect: 8
    println!("{}", Solution::min_time(7, edges, has_apple2)); //expect: 6
    println!("{}", Solution::min_time(7, edges, has_apple3)); //expect: 0
}
