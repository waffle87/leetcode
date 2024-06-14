struct Solution;

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let n: usize = n as usize;
        let mut roots: Vec<usize> = {
            let mut ans: Vec<usize> = vec![0; n];
            for i in 0..n {
                ans[i] = i;
            }
            ans
        };
        let mut ranks: Vec<usize> = vec![1; n];
        for e in edges {
            let u = e[0] as usize;
            let v = e[1] as usize;
            Self::union(u, v, &mut roots, &mut ranks);
        }
        Self::find(source as usize, &mut roots) == Self::find(destination as usize, &mut roots)
    }
    fn union(x: usize, y: usize, roots: &mut Vec<usize>, ranks: &mut Vec<usize>) {
        let (root_x, root_y) = (Self::find(x, roots), Self::find(y, roots));
        if root_x == root_y {
            return;
        }
        if ranks[x] > ranks[y] {
            roots[root_y] = root_x;
            ranks[root_x] += 1;
        } else {
            roots[root_x] = root_y;
            ranks[root_y] += 1;
        }
    }
    fn find(x: usize, roots: &mut Vec<usize>) -> usize {
        let mut x = x;
        while x != roots[x] {
            roots[x] = roots[roots[x]];
            x = roots[x];
        }
        x
    }
}

fn main() {
    let (n, source, destination) = (3, 0, 2);
    let edges = vec![vec![0,1], vec![1,2], vec![2,0]];
    print!("{}", Solution::valid_path(n, edges, source, destination));
}
