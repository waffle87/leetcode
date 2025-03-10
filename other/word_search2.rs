#[derive(Default)]
struct Solution;

struct Trie {
    child: [Option<Box<Trie>>; 26],
    is_end: bool
}

impl Solution {
    pub fn find_words(board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        let mut trie = Trie::default();
        for w in words {
            let mut node = &mut trie;
            for u in w.bytes() {
                node = node.child[(u - b'a') as usize].get_or_insert(Default::default());
            }
            node.is_end = true;
        }
        let (mut board, mut ans) = (board, Vec::new());
        for i in 0..board.len() {
            for j in 0..board[0].len() {
                Self::backtrack(
                    &mut board,
                    &mut trie,
                    (i, j),
                    &mut String::new(),
                    &mut ans
                );
            }
        }
        ans
    }
    fn backtrack(board: &mut Vec<Vec<char>>, trie: &mut Trie, pos: (usize, usize), s: &mut String, ans: &mut Vec<String>) {
        let c = board[pos.0][pos.1];
        if let Some(node) = &mut trie.child[(c as u8 - b'a') as usize] {
            s.push(c);
            if node.is_end {
                ans.push(s.clone());
                node.is_end = false;
            }
            board[pos.0][pos.1] = '*';
            for d in [0,1,0,!0,0].windows(2) {
                let i = pos.0.wrapping_add(d[0]);
                let j = pos.1.wrapping_add(d[1]);
                if (0..board.len()).contains(&i) && (0..board[0].len()).contains(&j) && board[i][j] != '*' {
                    Self::backtrack(board, node, (i, j), s, ans);
                }
            }
            board[pos.0][pos.1] = c;
            s.pop();
        }
    }
}

fn main() {
    let board = vec![vec!['a','b'], vec!['c','d']];
    let words = vec!["abcb".to_string()];
    print!("{:?}", Solution::find_words(board, words));
}
