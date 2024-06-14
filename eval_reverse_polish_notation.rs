struct Solution;

impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        tokens.iter().fold(Vec::new(), |mut stack, x| {
            if let Ok(x) = x.parse() {
                stack.push(x);
            } else if let (Some(rhs), Some(lhs)) = (stack.pop(), stack.pop()) {
                stack.push(match x.as_str() {
                    "+" => lhs + rhs,
                    "-" => lhs - rhs,
                    "*" => lhs * rhs,
                    "/" => lhs / rhs,
                    _   => unreachable!()
                })
            }
            stack
        }) [0]
    }
}

fn main() {
    let tokens1 = ["2","1","+","3","*"];
    let tokens2 = ["4","13","5","/","+"];
    let tokens3 = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"];
    println!("{}", Solution::eval_rpn(tokens1));
    println!("{}", Solution::eval_rpn(tokens2));
    println!("{}", Solution::eval_rpn(tokens3));
}
