# 860. Lemonade Change

"""
at a lemonade stand, each lemonade costs $5. customers are standing in a
queue to buy from you and order one at a time. each customer will only buy
one lemonade and pay with either $5, $10, or $20 bill. you must provide the
correct change to each customer so that the net transaction is that the
customer pays $5. note that you do not have any change in hand at first.
given an integer array 'bills' where 'bills[i]' is the bill the i'th customer
pays, return true if you can provide every customer with the correct change,
or false otherwise
"""


class Solution(object):
    def lemonadeChange(self, bills):
        fives, tens = 0, 0
        for b in bills:
            if b == 5:
                fives += 1
            elif b == 10:
                if fives == 0:
                    return False
                else:
                    fives -= 1
                    tens += 1
            else:
                if tens > 0 and fives > 0:
                    tens -= 1
                    fives -= 1
                elif fives >= 3:
                    fives -= 3
                else:
                    return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.lemonadeChange([5, 5, 5, 10, 20]))  # expect: True
    print(obj.lemonadeChange([5, 5, 10, 10, 20]))  # expect: False
