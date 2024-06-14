struct Solution;

impl Solution {
    pub fn unique_paths_iii(mut grid: Vec<Vec<i32>>) -> i32 {
        let (start_x, start_y) = (0..grid.len())
            .flat_map(|y| (0..grid[0].len()).map(move |x| (x, y)))
            .find(|&(x, y)| grid[y][x] == 1)
            .expect("grid does not have starting square!");
        let num_empty = grid.iter()
            .flat_map(|r| r.iter().filter(|&&c| c != -1)).count();
        Self::dfs(&mut grid, start_x, start_y, num_empty - 1) as _
    }
    fn dfs(grid: &mut Vec<Vec<i32>>, x: usize, y: usize, num_empty: usize) -> usize {
        if x >= grid[0].len() || y >= grid.len() {
            return 0;
        }
        match grid[y][x] {
            0 | 1 => {
                grid[y][x] = -1;
                let curr_paths = [(0,1),(1,0),(0,-1),(-1,0)]
                    .iter()
                    .map(|&(dx, dy)| ((x as isize + dx) as _, (y as isize + dy) as _))
                    .map(|(nx, ny)| Self::dfs(grid, nx, ny, num_empty - 1)).sum();
                grid[y][x] = 0;
                curr_paths
            }
            2 if num_empty == 0 => 1,
            _ => 0
        }
    }
}

fn main() {
    let grid = vec![
        vec![1,0,0,0],
        vec![0,0,0,0],
        vec![0,0,2,-1]
    ];
    print!("{}", Solution::unique_paths_iii(grid));
}
