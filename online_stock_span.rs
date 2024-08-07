// 901. Online Stock Span

/*
 * design an algorithm that collects daily price quotes for some stock and
 * returns the span of that stock's price for the current day. the span of the
 * stock's price in one day is the maximum number of consecutive days (starting
 * from that day and going backward) for which the stock price was less than or
 * equal to the price of that day. if the prices of the stock in the last four
 * days is '[7,34,1,2]' and the price of the stock today is 8, then the span of
 * today is 3 because starting from today, the price of the stock was less than
 * or equal 8 for 3 consecutive days.
 */

struct Span {
    price: i32,
    days: i32,
}

struct StockSpanner {
    spans: Vec<Span>,
}

impl StockSpanner {
    fn new() -> Self {
        StockSpanner { spans: Vec::new() }
    }
    fn next(&mut self, price: i32) -> i32 {
        let mut days = 1;
        while let Some(span) = self.spans.last() {
            if span.price <= price {
                days += span.days;
                self.spans.pop();
            } else {
                break;
            }
        }
        self.spans.push(Span { price, days });
        days
    }
}

fn main() {
    let mut obj = StockSpanner::new();
    println!("{}", obj.next(100));
    println!("{}", obj.next(80));
    println!("{}", obj.next(60));
    println!("{}", obj.next(70));
    println!("{}", obj.next(60));
    println!("{}", obj.next(75));
    println!("{}", obj.next(85));
}
