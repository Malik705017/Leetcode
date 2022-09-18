// https://leetcode.com/problems/longest-repeating-character-replacement

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        
        int left = 0, right = 0, maxCharCount = 0;
        
        while(right < s.size()) {
            char rightChar = s[right];
            window[rightChar]++;
            
            if(window[rightChar] > maxCharCount) {
                maxCharCount = window[rightChar];
            }
            
            right++;
            
            if(right - left - maxCharCount > k) {
                char leftChar = s[left];
                if(window.count(leftChar) == maxCharCount){
                    maxCharCount--;
                }
                window[leftChar]--;
                left++;
            }
        }
        
        return right - left;
    }
};