// 947. Most Stones Removed with Same Row or Column

/*
 * on a 2d plane, we place 'n' stones at some integer coordinate points. each
 * coordinate point may have at most one stone. a stone can be removed if it
 * shares either the same row or the same column as another stone that has not
 * been removed. given an array 'stones' of length 'n' where 'stones[i] = [x_i,
 * y_i]' represents the location of the i'th stone, return the largest possible
 * number of stones that can be removed
 */

use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn remove_stones(stones: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let mut parent: Vec<usize> = (0..stones.len()).collect();
        let mut rows: HashMap<i32, usize> = HashMap::new();
        let mut cols: HashMap<i32, usize> = HashMap::new();
        for (i, v) in stones.iter().enumerate() {
            match rows.get(&v[0]) {
                Some(&j) => {
                    if Self::union_stone(i, j, &mut parent) {
                        ans += 1;
                    }
                }
                None => {
                    rows.insert(v[0], i);
                }
            }
            match cols.get(&v[1]) {
                Some(&j) => {
                    if Self::union_stone(i, j, &mut parent) {
                        ans += 1;
                    }
                }
                None => {
                    cols.insert(v[1], i);
                }
            }
        }
        ans
    }
    fn union_stone(i: usize, j: usize, parent: &mut Vec<usize>) -> bool {
        let i_root = Self::find_set(i, parent);
        let j_root = Self::find_set(j, parent);
        parent[i_root] = j_root;
        i_root != j_root
    }
    fn find_set(x: usize, parent: &mut Vec<usize>) -> usize {
        if x != parent[x] {
            parent[x] = Self::find_set(parent[x], parent);
        }
        parent[x]
    }
}

fn main() {
    let stones = vec![
        vec![0, 0],
        vec![0, 1],
        vec![1, 0],
        vec![1, 2],
        vec![2, 1],
        vec![2, 2],
    ];
    print!("{}", Solution::remove_stones(stones));
}
