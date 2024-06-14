struct Solution;

impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        let n = edges.len();
        let (mut d1, mut d2) = (vec![n; n], vec![n; n]);
        d1[node1 as usize] = 0;
        d2[node2 as usize] = 0;
        let mut u = node1 as usize;
        while edges[u] != -1 {
            let v = edges[u] as usize;
            if d1[v] < d1[u] {
                break;
            }
            d1[v] = d1[u] + 1;
            u = v;
        }
        u = node2 as usize;
        while edges[u] != -1 {
            let v = edges[u] as usize;
            if d2[v] < d2[u] {
                break;
            }
            d2[v] = d2[u] + 1;
            u = v;
        }
        let (mut ans, mut mx) = (-1i32, n);
        for i in 0..n {
            let tmp = d1[i].max(d2[i]);
            if tmp >= mx {
                continue;
            }
            ans = i as i32;
            mx = tmp;
        }
        ans
    }
}

fn main() {
    let edges1 = vec![2,2,3,-1];
    let edges2 = vec![1,2,-1];
    println!("{}", Solution::closest_meeting_node(edges1, 0, 1)); //expect: 2
    println!("{}", Solution::closest_meeting_node(edges2, 0, 2)); //expect: 2
}
