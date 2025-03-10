struct Solution;

impl Solution {
    pub fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {
        matrix.into_iter().reduce(|prev, mut curr| {
            prev.into_iter().chain(std::iter::once(i32::MAX)).scan((i32::MAX, i32::MAX, i32::MAX), |(w1, w2, w3), c| {
                *w1 = *w2;
                *w2 = *w3;
                *w3 = c;
                Some(c.min(*w1).min(*w2))
            }).skip(1).zip(curr.iter_mut()).for_each(|(p, c)| *c += p);
            curr
        }).unwrap().into_iter().min().unwrap()
    }
}

fn main() {
    let matrix = vec![
                 vec![2,1,3],
                 vec![6,5,4],
                 vec![7,8,9]];
    print!("{}", Solution::min_falling_path_sum(matrix));
}
