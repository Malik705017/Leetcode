// https://leetcode.com/problems/unique-paths

#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        if (m == 1 || n == 1) {
            return 1;
        }
        
        // declare a 2D array
        int** map = new int*[m];
        for(int i = 0 ; i < m ; i++) {
            map[i] = new int[n]; 
        }
        // initialize value with 0 or 1;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                map[i][j] = 0;
                if(i == 0 || j == 0) {
                    map[i][j] = 1;
                }
            }
        } 
        
        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                map[i][j] = map[i-1][j] + map[i][j-1];
            }
        }
        
        return map[m-1][n-1];
    }
};