// https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> bfs;
        int islandsCount = 0, offsets[] = {0, 1, 0, -1, 0};
        
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0 ; j < grid[0].size(); j++) {
                // starting point
                if(grid[i][j] == '1'){
                    
                    bfs.push({i,j});
                    grid[i][j] = '0';
                    
                    while(!bfs.empty()){
                        
                        pair<int, int> p = bfs.front();
                        bfs.pop();
                        
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                bfs.push({r, c});
                            }
                        }
                        
                    }
                    
                    islandsCount++;
                }   
            }
        }
        
        return islandsCount;
    }
};