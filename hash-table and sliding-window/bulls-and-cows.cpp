// https://leetcode.com/problems/bulls-and-cows

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, vector<int>> need;
        vector<int> usedIndex;
        usedIndex.resize(1000,0);
        int a = 0, b = 0;
        
        for(int i = 0; i < secret.length(); i++) {
            char c = secret[i];
            char g = guess[i];
            if(c == g){
                a++;   
                usedIndex[i] = 1;
            } else {
                if(need[g].empty()) {
                    vector<int> v;
                    v.push_back(i);
                    need[g] = v;
                } else {
                    need[g].push_back(i);
                }
            }
        }
        
        for(int i = 0; i < secret.length(); i++) {
            if(usedIndex[i] == 1) continue;
            
            char c = secret[i];
            if(!need[c].empty()) {
                b++;
                need[c].pop_back();
            }
        }
        
        return to_string(a)+'A'+to_string(b)+'B';
    }
};