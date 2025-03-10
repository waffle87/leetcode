use std::collections::VecDeque;
use std::collections::HashSet;
struct Solution;

impl Solution {
    pub fn nearest_exit(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let (mut dq, mut visited) = (VecDeque::new(), HashSet::new());
        dq.push_back((entrance[0] as usize, entrance[1] as usize, 0));
        while !dq.is_empty() {
            while let Some((i, j, c)) = dq.pop_front() {
                if !visited.insert((i, j)) {
                    continue;
                }
                if i == 0 || i == maze.len() - 1 || j == 0 || j == maze[0].len() - 1 {
                    if i != entrance[0] as usize || j != entrance[1] as usize {
                        return c;
                    }
                }
                if maze[i][j] == '.' {
                    if i > 0 && maze[i - 1][j] == '.' {
                        dq.push_back((i - 1, j, c + 1));
                    }
                    if i < maze.len() - 1 && maze[i + 1][j] == '.' {
                        dq.push_back((i + 1, j, c + 1));
                    }
                    if j > 0 && maze[i][j - 1] == '.' {
                        dq.push_back((i, j - 1, c + 1));
                    }
                    if j < maze[0].len() - 1 && maze[i][j + 1] == '.' {
                        dq.push_back((i, j + 1, c + 1));
                    }
                }
            }
        }
        -1
    }
}
