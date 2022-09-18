// https://leetcode.com/problems/min-cost-climbing-stairs

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int totalFloors = cost.size();
        
        vector<int> minCostToReachEveryFloor;
        minCostToReachEveryFloor.resize(totalFloors, 0);
        
        // base case, the cost to reach floor 2
        minCostToReachEveryFloor[1] = min(cost[0], cost[1]); 
        
        // cost to floor i =  min(cost to floor i-2 + cost[i-1], cost to floor i-1 + cost[i])
        
        for (int i = 2 ; i < totalFloors ; i++) {
            minCostToReachEveryFloor[i] = min(minCostToReachEveryFloor[i-2] + cost[i-1], minCostToReachEveryFloor[i-1] + cost[i]); 
        }
        
        return minCostToReachEveryFloor[totalFloors - 1];
    }
};