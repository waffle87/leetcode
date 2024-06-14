struct Solution;

impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable_by(|a, b| a[1].cmp(&b[1]));
        let (mut arrows, mut target) = (0, points[0][1]);
        for p in points {
            if p[0] > target && p[1] > target {
                arrows += 1;
                target = p[1];
            }
        }
        arrows + 1
    }
}

fn main() {
    let points = vec![vec![10,16],vec![2,8],vec![1,6],vec![7,12]];
    println!("{}", Solution::find_min_arrow_shots(points)); //expect: 2
}
