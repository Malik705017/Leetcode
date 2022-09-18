// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;
        
        unordered_map<char, int> need, window;
        for (char c: p) need[c]++;
        
        int left = 0, right = 0;
        
        while(right < s.size()) {
            char rightChar = s[right];
            right++;
            
            if(need.count(rightChar)) {
                window[rightChar]++;
                
                if(window == need) {
                    res.push_back(left);
                }
            }
            
            if(right-left == p.size()) {
                char leftChar = s[left];
                left++;
                
                if(need.count(leftChar)) {
                    window[leftChar]--;
                }
            }
        }
        
        return res;
    }
};