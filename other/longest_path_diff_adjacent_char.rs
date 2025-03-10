// 2246. Longest Path With Different Adjacent Characters

/*
 * you are given a tree (ie. a connected undirected graph that has no cycles)
 * rooted at node '0' consisting of 'n' nodes numbered from '0' to 'n - 1'. the
 * tree is represented by a 0-indexed array 'parent' of size 'n' where
 * 'parent[i]' is the parent of node 'i'. since node 0 is the root, 'parent[0] =
 * -1'. you are also given a string 's' of length 'n', where 's[i]' is the
 * character assigned to node 'i'. return the legnth of the longest path in the
 * tree such that no pair of adjacnet nodes on the path have the same character
 * assigned to them.
 */

use std::cmp::max;
use std::collections::HashMap;
struct Solution;

static mut res: i32 = 0;
impl Solution {
    pub fn longest_path(parent: Vec<i32>, s: String) -> i32 {
        unsafe { res = 0 }
        let mut graph = HashMap::new();
        for (i, &u) in parent.iter().enumerate() {
            if u == -1 {
                continue;
            }
            let u = u as usize;
            if !graph.contains_key(&u) {
                graph.insert(u, vec![]);
            }
            graph.entry(u).or_insert(vec![]).push(i);
        }
        let sa: Vec<char> = s.chars().collect();
        Self::dfs(0, &graph, &sa);
        let mut ans: i32 = 0;
        unsafe {
            ans = res;
        }
        ans
    }
    fn dfs(root: usize, graph: &HashMap<usize, Vec<usize>>, s: &Vec<char>) -> i32 {
        if !graph.contains_key(&root) {
            unsafe {
                res = max(res, 1);
            }
            return 1;
        }
        let (mut a1, mut a2) = (0, 0);
        for &v in graph[&root].iter() {
            if s[root] == s[v] {
                Self::dfs(v, graph, s);
                continue;
            }
            let curr = Self::dfs(v, graph, s);
            if curr >= a1 {
                a2 = a1;
                a1 = curr;
            } else if curr > a2 {
                a2 = curr
            }
        }
        unsafe {
            res = max(res, a1 + a2 + 1);
        }
        a1 + 1
    }
}

fn main() {
    let parent1 = vec![-1, 0, 0, 1, 1, 2];
    let parent2 = vec![-1, 0, 0, 0];
    println!(
        "{}",
        Solution::longest_path(parent1, String::from("abacbe"))
    ); //expect: 3
    println!("{}", Solution::longest_path(parent2, String::from("aabc"))); //expect: 3
}
