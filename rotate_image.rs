struct Solution;

impl Solution {
    pub fn rotate(mut matrix: Vec<Vec<i32>>) {
        let n = matrix.len();
        let depth = n / 2;
        for  i in 0..depth {
            let (len, opp) = (n - 2 * i - 1, n - 1 - i);
            for j in 0..len {
                let tmp = matrix[i][i + j];
                matrix[i][i + j] = matrix[opp - j][i];
                matrix[opp - j][i] = matrix[opp][opp - j];
                matrix[opp][opp - j] = matrix[i + j][opp];
                matrix[i + j][opp] = tmp;
            }
        }
    }
}

fn main() {
    let matrix = vec![
        vec![1,2,3],
        vec![4,5,6],
        vec![7,8,9]
    ];
    print!("{:?}", Solution::rotate(matrix));
}
