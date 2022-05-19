// Source : https://leetcode.com/problems/prison-cells-after-n-days/
// Date   : 20-05-2022

/********************************************************************************** 

There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.

Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]


Intuition

Here's a generalizable way to approach this problem w/o having to have a ton of insight:

there are 8 cells so there are 2 ^ 8 = 256 possible cell configurations
therefore, after 256 transformations you are guaranteed to observe a cycle by the pigeonhole principle
In the future when you see questions where you have to make a large amount of state transitions over a state space that seems small, 
just compare the size of the state space to the # of transitions to determine if there's a cycle 
so you can bound complexity to the size of the state space.


Since you only have 6 bits that are changing (first and last bit changes to 0 and stays 0). Total max possible distinct states are 2 ^ 6 = 64.

Let's take an example. Assume you are asked the state after 10 ^ 9 days.
You store the state in the map the first time you see a new state. Then when you see the same state again, you know that you have passed (lastSeen - currVal) state in between. So now you know your states repeat every (lastSeen - currVal) times. So finally you can mod the current N with that value to not repeat the same steps. Below is an example for 10^9 days.
[0,1,0,1,1,0,0,1]
1000000000

N -> N % (last_seen - curr_val) ==> result
999999985 -> 999999985 % (999999999 - 999999985) ==> 5
4 -> 4 % (999999998 - 4) ==> 4
3 -> 3 % (999999997 - 3) ==> 3
2 -> 2 % (999999996 - 2) ==> 2
1 -> 1 % (999999995 - 1) ==> 1
0 -> 0 % (999999994 - 0) ==> 0

**********************************************************************************/

class Solution {
public:
    string vecToString(vector<int> &cells) {
        string result = "";
        for(auto cell: cells) {
            char tempCell = cell-'0';
            result.push_back(tempCell);
        }
        
        return result;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<string, int> hashMap;
        
        while(n) {
            string cellString = vecToString(cells);
            hashMap[cellString] = n--;
            vector<int> cells2(8, 0);
            
            for(int i=1; i<7; i++) {
                cells2[i] = cells[i-1] == cells[i+1] ? 1 : 0;
            }
            
            swap(cells, cells2);
            cellString = vecToString(cells);
            
            if(hashMap.find(cellString) != hashMap.end()) {
                n = n%(hashMap[cellString]-n);
            }
        }
        
        return cells;
    }
};