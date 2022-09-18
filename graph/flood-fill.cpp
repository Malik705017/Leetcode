// https://leetcode.com/problems/flood-fill

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    int x;
    int y;
    int color;
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color) return image;
        
        queue<Vertex> q;
        Vertex startVertex = {
            .y = sr,
            .x = sc,
            .color = image[sr][sc]
        };
        q.push(startVertex);
        
        while(!q.empty()){
            Vertex curVertex = q.front();
            
            int leftColor = -1, rightColor = -1, upColor = -1, downColor = -1;
            
            // not down
            if(curVertex.y > 0) {
                downColor = image[curVertex.y-1][curVertex.x];
            }
            
            // not up
            if(curVertex.y < image.size() - 1){
                upColor = image[curVertex.y + 1][curVertex.x];
            }
            
            // not left
            if(curVertex.x > 0){
                leftColor = image[curVertex.y][curVertex.x-1];
            }
            
            // not right
            if(curVertex.x < image[0].size() - 1){
                rightColor = image[curVertex.y][curVertex.x+1];
            }
            
                
            if(leftColor == curVertex.color){
                Vertex leftVertex = {
                    .y = curVertex.y,
                    .x = curVertex.x-1,
                    .color = curVertex.color
                };
                q.push(leftVertex);
            }
            
            if(rightColor == curVertex.color){
                Vertex rightVertex = {
                    .y = curVertex.y,
                    .x = curVertex.x+1,
                    .color = curVertex.color
                };
                q.push(rightVertex);
            }
            
            if(downColor == curVertex.color){
                Vertex downVertex = {
                    .y = curVertex.y-1,
                    .x = curVertex.x,
                    .color = curVertex.color
                };
                q.push(downVertex);
            }
            
            if(upColor == curVertex.color){
                Vertex upVertex = {
                    .y = curVertex.y+1,
                    .x = curVertex.x,
                    .color = curVertex.color
                };
                q.push(upVertex);
            }
                 
            // pop, and draw color
            image[curVertex.y][curVertex.x] = color;
            q.pop();
        }
        
        return image;
    }
};