struct Solution;

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n == 1 {
            return "1".to_string();
        }
        let mut output: Vec<char> = vec![];
        let mut last_char = ' ';
        let mut count: u8 = '0' as u8;
        for char in Solution::count_and_say(n - 1).chars().into_iter() {
            if last_char == ' ' {
                last_char = char;
                count = '1' as u8;
            } else if char == last_char {
                count += 1;
            } else {
                output.push(count as char);
                output.push(last_char);
                last_char = char;
                count = '1' as u8;
            }
        }
        output.push(count as char);
        output.push(last_char);
        output.into_iter().collect()
    }
}

fn main() {
    print!("{}", Solution::count_and_say(4));
}
