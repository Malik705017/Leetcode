// https://leetcode.com/problems/first-bad-version

#include <iostream>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int m = l + (r-l) / 2;
        
        while(l <= r) {
            m = l + (r-l) / 2;
            
            if(isBadVersion(m) && !isBadVersion(m-1) ) return m;
            // 往右搜尋
            else if(!isBadVersion(m)) {
                l = m+1;
            }
            // 往左搜尋
            else if(isBadVersion(m)) {
                r = m-1;
            }
        }
        
        return m;  
    }
};