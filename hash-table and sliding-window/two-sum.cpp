// https://leetcode.com/problems/two-sum

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> need;
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; i++){
            if(need.count(target-nums[i]) > 0){
                res.push_back(need[target-nums[i]]);
                res.push_back(i);
                break;
            }
            need[nums[i]] = i;
        }
        
        return res;
    }
};