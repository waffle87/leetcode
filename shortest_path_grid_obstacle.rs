use std::collections::VecDeque;
struct Solution;

impl Solution {
    pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let m = grid.len() as i32; let n = grid[0].len() as i32;
        let dir = [-1, 0, 1, 0, -1];
        let mut dq = VecDeque::new();
        let mut visited = vec![vec![0; n as usize]; m as usize];
        let mut ans = 0;
        dq.push_back((0,0,k));
        visited[0][0] = k + 1;
        while !dq.is_empty() {
            for _ in 0..dq.len() {
                let (row, col, left) = dq.pop_front().unwrap();
                if row == m - 1 && col == n - 1 {
                    return ans;
                }
                for (&i, &j) in dir.iter().zip(dir.iter().skip(1)){
                    let (new_row, new_col) = (row + i, col + j);
                    if new_row < 0 || new_row >= m || new_col < 0 || new_col >= n
                    || visited[new_row as usize][new_col as usize] >= left + 1 {
                        continue;
                    }
                    if grid[new_row as usize][new_col as usize] == 0 {
                        dq.push_back((new_row, new_col, left));
                        visited[new_row as usize][new_col as usize] = left + 1;
                    } else if left > 0 {
                        dq.push_back((new_row, new_col, left - 1));
                        visited[new_row as usize][new_col as usize] = left;
                    }
                }
            }
            ans += 1;
        }
        -1
    }
}
