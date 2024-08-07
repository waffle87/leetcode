# 901. Online Stock Span

"""
design an algorithm that collects daily price quotes for some stock and
from that day and going backward) for which the stock price was less than or
equal to the price of that day. if the prices of the stock in the last four
days is '[7,34,1,2]' and the price of the stock today is 8, then the span of
today is 3 because starting from today, the price of the stock was less than
or equal 8 for 3 consecutive days.
"""


class StockSpanner:
    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        ans = 1
        while self.stack and self.stack[-1][0] <= price:
            ans += self.stack.pop()[1]
        self.stack.append([price, ans])
        return ans


if __name__ == "__main__":
    obj = StockSpanner()
    print(obj.next(100))
    print(obj.next(80))
    print(obj.next(60))
    print(obj.next(70))
    print(obj.next(60))
    print(obj.next(75))
    print(obj.next(85))
