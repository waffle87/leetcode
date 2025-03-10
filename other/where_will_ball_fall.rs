struct Solution;

impl Solution {
    pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid[0].len();
        if n == 1 {
            return vec![-1];
        }
        (0..n).map(|i| {Self::exits(&grid, 0, i)}).collect()
    }
    fn exits(grid: &Vec<Vec<i32>>, row: usize, i: usize) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        if i == usize::MAX ||i >= n {
            return -1;
        }
        let i2 = i + grid[row][i] as usize;
        if i2 >= n || i2 == usize::MAX {
            return -1;
        }
        let (dir1, dir2) = (grid[row][i], grid[row][i2]);
        if dir1 != dir2 {
            return -1;
        }
        if row == m - 1 {
            return i2 as i32;
        }
        Self::exits(&grid, row + 1, i2)
    }
}

fn main() {
    let grid = vec![vec![1,1,1,-1,-1],
                    vec![1,1,1,-1,-1],
                    vec![-1,-1,-1,1,1],
                    vec![1,1,1,1,-1],
                    vec![-1,-1,-1,-1,-1]];
    print!("{:?}", Solution::find_ball(grid));
}
