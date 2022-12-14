// https://leetcode.com/problems/backspace-string-compare

/*
    Implementation using two pointer: 1st to traverse the string and second to store the character at given position
    Suppose 2 pointer i & k
    Start traversing the by first pointer(i) if it is # then decrease the 2nd pointer(k) (k>=0) .
    And if it is not # then increase the pointer(k) and store the element at k th position. S[k]=S[i]
    Same will be done to 2nd string And suppose its 2nd pointer is p
    If k and p are not equal means the string have differnt length. If same, then compare every element.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0, p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '#')
            {
                k--;
                k = max(0,k);
            } else {
               s[k] = s[i];
               k++;
            }
        }
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == '#')
            {
                p--;
                p = max(0,p);
            } else {
               t[p] = t[i];
               p++;
            }
        }
        // size is different
        if(k != p) return false;
        // or compare every char
        else
        {
            for(int i = 0; i < k; i++) if(s[i]!=t[i]) return false;
            // all chars are same
            return true;
        }
        
    }
};