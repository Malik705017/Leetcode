#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
            
        while(l <= r) {
            int mid = (l + r) / 2;
            if(target == nums[mid]) return mid;
            // 往右搜尋
            else if(target > nums[mid]) {
                l = mid+1;
            }
            // 往左搜尋
            else if(target < nums[mid]) {
                r = mid-1;
            }
        }
        
        return -1;   
    }
};