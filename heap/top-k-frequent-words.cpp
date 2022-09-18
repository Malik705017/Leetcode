// https://leetcode.com/problems/top-k-frequent-words

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> stringMap;
        for(auto s: words) {
            stringMap[s]++;
        }
        
        priority_queue< pair<string,int>, vector<pair<string,int>>,Comp> max_heap;
        vector<string> res;
        
        for(const auto& m : stringMap) {
            pair<string, int> p = {m.first, m.second};
            max_heap.push(p);
        }
        
        for(int i = 0; i < k; i++) {
            pair<string, int> p = max_heap.top();
            string s = p.first;
            res.push_back(s);
            max_heap.pop();
        }
        
        return res;
    }
private:
    struct Comp {
        Comp() {}
        ~Comp() {}
        bool operator() (const pair<string,int>& a, const pair<string,int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        }
    };
};