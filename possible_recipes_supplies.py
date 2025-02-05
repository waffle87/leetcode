# 2115. Find All Possible Recipes from Given Supplies
from collections import defaultdict, Counter

"""
you have information about 'n' different recipes. you are given a string
array 'recipes' and a 2d string array 'ingredients'. the i'th recipe has the
name 'recipes[i]', and you can create it is you have all the needed
ingredients from 'ingredients[i]'. ingredients to a recipe may need to be
created from other recipes, ie. 'ingredients[i]' may contain a string that is
in 'recipes'. you are also given a string array 'supplies' containing all the
ingredients that you initially have, and you have an infinite supply of all
of them. return a list of all the recipes that you can create. you may return
the answer in any order.
"""


class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """
        to_recipe, in_deg = defaultdict(set), Counter()
        for i, j in zip(recipes, ingredients):
            for k in j:
                to_recipe[k].add(i)
            in_deg[i] = len(j)
        ans = []
        for i in supplies:
            for j in to_recipe.pop(i, set()):
                in_deg[j] -= 1
                if in_deg[j] == 0:
                    supplies.append(j)
                    ans.append(j)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findAllRecipes(
            recipes=["bread"],
            ingredients=[["yeast", "flour"]],
            supplies=["yeast", "flour", "corn"],
        )
    )
    print(
        obj.findAllRecipes(
            recipes=["bread", "sandwich"],
            ingredients=[["yeast", "flour"], ["bread", "meat"]],
            supplies=["yeast", "flour", "meat"],
        )
    )
    print(
        obj.findAllRecipes(
            recipes=["bread", "sandwich", "burger"],
            ingredients=[
                ["yeast", "flour"],
                ["bread", "meat"],
                ["sandwich", "meat", "bread"],
            ],
            supplies=["yeast", "flour", "meat"],
        )
    )
