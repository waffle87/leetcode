use std::collections::HashMap;
struct Solution;

/*
* 'Line' is represented as y = m * x + c
* m & c are rational numbers because of integer coordinates,
* but in general floating point numbers can be insufficient to
* guarantee uniqueness as they are still finite precision.
* so for most real irl cases we use numerator and denominator
* to represent m & c. decimal precision!!!
* if m -> +- infinity then use x-int to identify line
* if m == 0           then use y-int to identify line
*/
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
enum Line {
    Inf(i32), //x-int
    MC((i32, i32), (i32, i32)), //numerator, denominator tuples for m & c
    Zero(i32) //y-int
}

impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i32 {
        if points.len() == 1 {
            return 1;
        }
        //y - y0 = (y1 - y0) / (x1 - x0) * (x - x0)
        //y = dy / dx x + (dx * y0 - dy * x0) / dx
        let mut fm: HashMap<Line, i32> = HashMap::new();
        points.iter().enumerate().flat_map(|(i, pt1)| {
            points.iter().skip(i + 1).map(move |pt2| {
                //swap points arounto make sure dy >= 0 since we are storing
                //fraction numerator & denominator separately.
                let (x0, y0, x1, y1) = if pt2[1] > pt1[1] || (pt2[1] == pt1[1] && pt2[0] > pt2[1]) {
                    (pt1[0], pt1[1], pt2[0], pt2[1])
                } else {
                    (pt2[0], pt2[1], pt1[0], pt1[1])
                };
                let mut dy = y1 - y0;
                let mut dx = x1 - x0;
                let g = Self::gcd(dy.abs(), dx.abs());
                if g != 0 {
                    dy /= g;
                    dx /= g;
                }
                if dx != 0 && dy != 0 {
                    /*
                    * slope is non-zero and finite so consistent line representation
                    * can be achieved using numerator & denominator representation
                    * because we have already preprocessed dy & dx for sign consistency
                    * and removed gcd from dy & dx
                    */
                    Line::MC((dy, dx), (dx * y0 - dy * x0, dx))
                } else if dx == 0 {
                    //x-int is enough to identify common lines
                    Line::Inf(x0)
                } else {
                    //y-int is enough to identify common lines
                    Line::Zero(y0)
                }
            })
        }).for_each(|k| {
                *fm.entry(k).or_insert(0) += 1;
        });
        let n = fm.values().max().cloned().unwrap();
        /*
        * if 'm' points lie on a line & all points have been processed pairwise
        * then n = m * (m - 1) / 2 pairs of points would have matched to same
        * line m^2 - m - 2 * n = 0 => m = (1 + sqrt(8 * n + 1)) / 2
        */
        (1 + (8f64 * n as f64 + 1f64).sqrt() as i32) / 2
    }
    fn gcd(a: i32, b: i32) -> i32 {
        if a == 0 || b == 0 {
            return 0;
        }
        let (mut a, mut b) = (a, b);
        while b > 0 {
            let tmp = a % b;
            a = b;
            b = tmp;
        }
        a
    }
}

fn main() {
    let points1 = vec![vec![1,1],vec![2,2],vec![3,3]];
    let points2 = vec![vec![1,1],vec![3,2],vec![5,3],vec![4,1],vec![2,3],vec![1,4]];
    println!("{}", Solution::max_points(points1)); //expect: 3
    println!("{}", Solution::max_points(points2)); //expect: 3
}
