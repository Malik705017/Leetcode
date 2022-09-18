// https://leetcode.com/problems/longest-palindrome

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> charCount;
        int length = 0;
        int oddCount = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            // not exists:
            if(charCount.find(s[i]) == charCount.end()){
                charCount[s[i]] = 1;
            } else {
                charCount[s[i]]++;
            }
        }
        
        for (const auto& c : charCount) {
            if(c.second % 2 == 0) length += c.second;
            else {
                length += c.second - 1;
                oddCount++;
            }
        }
        
        if(oddCount > 0) length++;
        
        return length;
    }
};