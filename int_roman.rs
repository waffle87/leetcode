struct Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let (mut ans, mut curr) = ("".to_owned(), num);
        let val_sym: Vec<(i32, &str)> = vec![
            (1000, "M"), (900, "CM"), (500, "D"),
            (400, "CD"), (100, "C"),  (90, "XC"),
            (50, "L"),   (40, "XL"),  (10, "X"),
            (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
        ];
        for &(v, s) in val_sym.iter() {
            let count = curr / v;
            if count > 0 {
                let mult_str = s.repeat(count as usize);
                ans.push_str(&mult_str);
                curr %= v;
            }
        }
        ans
    }
}

fn main() {
    print!("{}", Solution::int_to_roman(1994));
}
