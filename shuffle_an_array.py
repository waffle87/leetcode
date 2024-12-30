# 384. Shuffle an Array
from random import sample

"""
given an integer array 'nums', design an algorithm to randomly shuffle the
array. all permutations of the array should be equally likely as a result of
the shuffling. implement the 'Solution' class: 'Solution(int[] nums)'
initialises the object with the integer array 'nums' 'int[] reset()' resets
the array to its original configuration and returns it 'int[] shuffle()'
return a random shuffling of the array
"""


class Solution(list):
    reset, shuffle = list, lambda x: sample(x, len(x))


if __name__ == "__main__":
    obj = Solution([1, 2, 3])
    print(obj.shuffle())
    print(obj.reset())
    print(obj.shuffle())
