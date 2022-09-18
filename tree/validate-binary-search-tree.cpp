// https://leetcode.com/problems/validate-binary-search-tree

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
    bool isValidBST(TreeNode* root) {
        // 思路：利用 inorder traversal 如果下一個遇到的點比上一個遇到的點小，就不是 BST
        
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node = s.top();
        
        while(!s.empty()) {
            if(node -> left) {
                s.push(node -> left);
                node = node -> left;
            } else {
                TreeNode* top = s.top();
                
                if(res.size() > 0 && top -> val <= res.back()) {
                    return false;
                }
                
                res.push_back(top -> val);
                s.pop();
                
                if(top -> right) {
                    s.push(top -> right);
                    node = top -> right;
                }
            }
         }

      return true;
    }
};