# 721. Accounts Merge
from collections import defaultdict

"""
given a list of 'accounts' where each element 'accounts[i]' is a list of
strings, where the first element 'accounts[i][0]' is a name and the rest of
the elements are emails representing emails of the account. now we would like
to merge these accounts. two accounts definitely bbelong to the same person
if there is some common email to bboth accounts. note that even if two
accounts have the same name, they may belong to different people as people
could have the same name. a person can have any numbber of accounts initially
but all of their accounts definitely have the same name. after merging the
accounts, return the accounts in the following format: the first element of
each accout is the name, and the rest of the elements are emails in sorted
order. the accounts themselves can e returned in any order.
"""


class union_find:
    def __init__(self, n):
        self.parents = list(range(n))

    def union(self, child, parent):
        self.parents[self.find(child)] = self.find(parent)

    def find(self, x):
        if x != self.parents[x]:
            self.parents[x] = self.find(self.parents[x])
        return self.parents[x]


class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        uf = union_find(len(accounts))
        ownership = {}
        for i, (_, *emails) in enumerate(accounts):
            for email in emails:
                if email in ownership:
                    uf.union(i, ownership[email])
                ownership[email] = i
        ans = defaultdict(list)
        for email, owner in ownership.items():
            ans[uf.find(owner)].append(email)
        return [[accounts[i][0]] + sorted(emails) for i, emails in ans.items()]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.accountsMerge(
            accounts=[
                ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
                ["John", "johnsmith@mail.com", "john00@mail.com"],
                ["Mary", "mary@mail.com"],
                ["John", "johnnybravo@mail.com"],
            ]
        )
    )
    print(
        obj.accountsMerge(
            accounts=[
                ["Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"],
                ["Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"],
                ["Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"],
                ["Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"],
                ["Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"],
            ]
        )
    )
