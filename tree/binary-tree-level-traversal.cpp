// https://leetcode.com/problems/binary-tree-level-order-traversal

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int curLevel = 0;
        vector<vector<int>> res;
        if(!root) return res;
        
        stack<pair<TreeNode*, int>> s;
        s.push({root,0});
            
        // DFS
        while(!s.empty()) {
            pair p = s.top();
            TreeNode* curNode = p.first;
            int level = p.second;
            s.pop();
            
            // 是新的 level，要建立新的 vector
            if(level == res.size()) {
                vector<int> v;
                v.push_back(curNode -> val);
                res.push_back(v);
            } else {
                res[level].push_back(curNode -> val);
            }
            
            // 判斷是否有 child
            if(curNode -> left || curNode -> right) {
                
                if(curNode -> right){
                    s.push({curNode -> right, level+1});
                }
                
                if(curNode -> left) {
                    s.push({curNode -> left, level+1});
                }
            }
        }
     
        return res;
    }
};