# 2043. Simple Bank System
from collections import Counter

"""
you have been tasked with writing a program for a popular bank that will
automate all its incoming transactions (transfer, deposit, and withdraw). the
bank has 'n' accounts numbered from 1 to 'n'. the initial balance of each
account is stored in a 0-indexed integer array 'balance' with the '(i + 1)'th
account having an initial balance of 'balance[i]'.
"""


class Bank(object):
    def __init__(self, balance):
        """
        :type balance: List[int]
        """
        self.balance = Counter(dict(enumerate([0] + balance)))

    def transfer(self, account1, account2, money):
        """
        :type account1: int
        :type account2: int
        :type money: int
        :rtype: bool
        """
        return self.withdraw(account1, money) and (
            self.deposit(account2, money) or not self.deposit(account1, money)
        )

    def deposit(self, account, money):
        """
        :type account: int
        :type money: int
        :rtype: bool
        """
        return account < len(self.balance) and not self.balance.update({account: money})

    def withdraw(self, account, money):
        """
        :type account: int
        :type money: int
        :rtype: bool
        """
        return (
            account < len(self.balance)
            and self.balance[account] >= money
            and not self.balance.update({account: -money})
        )


if __name__ == "__main__":
    obj = Bank(balance=[10, 100, 20, 50, 30])
    print(obj.withdraw(3, 10))
    print(obj.transfer(5, 1, 20))
    print(obj.deposit(5, 20))
    print(obj.transfer(3, 4, 15))
    print(obj.withdraw(10, 50))
