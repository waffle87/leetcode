struct Solution;

impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let (m, n) = (matrix.len(), matrix[0].len());
        for i in 1..m {
            for j in 1..n {
                if matrix[i][j] != matrix[i - 1][j - 1] {
                    return false;
                }
            }
        }
        true
    }
}

fn main() {
    let matrix = vec![vec![1,2,3,4],
                      vec![5,1,2,3],
                      vec![9,5,1,2]];
    print!("{}", Solution::is_toeplitz_matrix(matrix));
}
