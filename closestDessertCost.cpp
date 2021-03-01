// Source : https://leetcode.com/problems/closest-dessert-cost/
// Date   : 01-03-2020

/********************************************************************************** 

You would like to make dessert and are preparing to buy the ingredients. You have n ice cream base flavors and m types of toppings to choose from. You must follow these rules when making your dessert:

There must be exactly one ice cream base.
You can add one or more types of topping or have no toppings at all.
There are at most two of each type of topping.
You are given three inputs:

baseCosts, an integer array of length n, where each baseCosts[i] represents the price of the ith ice cream base flavor.
toppingCosts, an integer array of length m, where each toppingCosts[i] is the price of one of the ith topping.
target, an integer representing your target price for dessert.
You want to make a dessert with a total cost as close to target as possible.

Return the closest possible cost of the dessert to target. If there are multiple, return the lower one.

Input: baseCosts = [1,7], toppingCosts = [3,4], target = 10
Output: 10
Explanation: Consider the following combination (all 0-indexed):
- Choose base 1: cost 7
- Take 1 of topping 0: cost 1 x 3 = 3
- Take 0 of topping 1: cost 0 x 4 = 0
Total: 7 + 3 + 0 = 10.

**********************************************************************************/

class Solution {
public:
    void backtracking(vector<int> &toppingCosts, int index, int cost, int target, int &closestCost, int &closestCostDiff) {
        int costDiff = abs(target-cost);
        
        if(costDiff < closestCostDiff || (costDiff == closestCostDiff && cost < closestCost)) {
            closestCostDiff = costDiff;
            closestCost = cost;
        }
        
        if(index >= toppingCosts.size() || cost > target) {
            return ;
        }
        
        // no toppings
        backtracking(toppingCosts, index+1, cost, target, closestCost, closestCostDiff);
        
        // single toppings
        backtracking(toppingCosts, index+1, cost+toppingCosts[index], target, closestCost, closestCostDiff);
        
        // double toppings
        backtracking(toppingCosts, index+1, cost+2*toppingCosts[index], target, closestCost, closestCostDiff);
    
    
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int closestCost=INT_MAX, closestCostDiff=INT_MAX;
        
        for(auto base: baseCosts) {
            backtracking(toppingCosts, 0, base, target, closestCost, closestCostDiff);
        }
        
        return closestCost;
    }
};