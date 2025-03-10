struct Solution;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows: [u16; 9] = [0; 9];
        let mut cols: [u16; 9] = [0; 9];
        let mut blck: [u16; 9] = [0; 9];
        for i in 0..9 {
            for j in 0..9 {
                match board[i][j] {
                    '.' => continue,
                    c => {
                        let b: usize = (i / 3) * 3 + (j / 3);
                        let curr = 1 << (c.to_digit(10).unwrap());
                        if rows[i] & curr != 0 || cols[j] & curr != 0 || blck[b] & curr != 0 {
                            return false;
                        }
                        rows[i] |= curr;
                        cols[j] |= curr;
                        blck[b] |= curr;
                    }
                }
            }
        }
        true
    }
}
