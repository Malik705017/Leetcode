// https://leetcode.com/problems/climbing-stairs

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* ways = new int[n]{0};
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        ways[0] = 1; // climb to floor 1
        ways[1] = 2; // climb to floor 2
        
        // ways to floot ith = ways[i-1] = ways[i-2] + ways[i-3]
        
        for (int i = 2; i < n ; i++) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        
        return ways[n-1];
    }
};