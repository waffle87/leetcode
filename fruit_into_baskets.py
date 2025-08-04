# 904. Fruit Into Baskets

"""
you are visiting a farm that has a single row of fruit trees arranged from
left t oright. the trees are represented by an integer array 'fruits' where
'fruits[i]' is the type of fruit the i'th tree produces. you want to collect
as much fruit as possible. however, the owner has some strict rules that you
must follow: you can only have two baskets and each can only hoold a single
type of fruit (unlimited quantity). starting from any tree, you must pick
exacty one fruit from every tree while moving to the right. once you reach a
tree with fruit that cannot fit in your baskets, you must stop. given the int
array 'fruits', return the maximum number of fruits you can pick
"""


class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        cnt, i = {}, 0
        for j, v in enumerate(fruits):
            cnt[v] = cnt.get(v, 0) + 1
            if len(cnt) > 2:
                cnt[fruits[i]] -= 1
                if cnt[fruits[i]] == 0:
                    del cnt[fruits[i]]
                i += 1
        return j - i + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalFruit(fruits=[1, 2, 1]))
    print(obj.totalFruit(fruits=[0, 1, 2, 2]))
    print(obj.totalFruit(fruits=[1, 2, 3, 2, 2]))
