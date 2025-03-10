// 73. Set Matrix Zeroes
// given an 'm x n' integer matrix 'matrix', if an element is 0,
// set its entire row and column to 0's. must be done in place
// (https://en.wikipedia.org/wiki/In-place_algorithm)

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let n_rows = matrix.len();
        let n_cols = matrix[0].len();
        let mut first_row = false;
        let mut first_col = false;
        for row in 0..n_rows {
            for col in 0..n_cols {
                if matrix[row][col] == 0 {
                    if row == 0 {
                        first_row = true;
                    }
                    if col == 0 {
                        first_col = true;
                    }
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for row in 1..n_rows {
            for col in 1..n_cols {
                if matrix[row][0] == 0 || matrix[0][col] == 0 {
                    matrix[row][col] = 0
                }
            }
        }
        if first_row {
            for col in 0..n_cols {
                matrix[0][col] = 0;
            }
        }
        if first_col {
            for row in 0..n_rows {
                matrix[row][0] = 0;
            }
        }
    }
}
