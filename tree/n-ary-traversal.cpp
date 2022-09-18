// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()) {
            Node* curNode = s.top();
            s.pop();
            res.push_back(curNode->val);
            
            vector<Node*> children = curNode -> children;
            
            for(int i = children.size() - 1 ; i >= 0 ; i--) {
                s.push(children[i]);
            }
            
        }
        
        return res;
    }
};

// pre-order traversal is like DFS, 左 -> 中 -> 右