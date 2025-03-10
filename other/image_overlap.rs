impl Solution {
    pub fn largest_overlap(img1: Vec<Vec<i32>>, img2: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        for i in 0..img1[0].len() {
            for j in 00..img1.len() {
                ans = ans.max(Solution::shift_and_compare(&img1, &img2, j, i));
            }
        }
        ans
    }

    fn shift_and_compare(img1: &[Vec<i32>],img2: &[Vec<i32>], x_shift: usize, y_shift: usize) -> i32 {
        let (mut counter, cols, rows) = ((0,0), img1.len(), img1[0].len());
        for i in 0..cols {
            for j in 0..rows {
                if img1[i][j] == 1 {
                    let ii = i + y_shift;
                    let jj = j + x_shift;
                    if ii < rows && jj < cols && img2[ii][jj] == 1 {
                        counter.0 += 1;
                    }
                }
                if img2[i][j] == 1 {
                    let ii = i + y_shift;
                    let jj = j + x_shift;
                    if ii < rows && jj < cols && img2[ii][jj] == 1 {
                        counter.1 += 1;
                    }
                }
            }
        }
        counter.0.max(counter.1)
    }
}

