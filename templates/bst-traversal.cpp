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

// 中 -> 左 -> 右，與 DFS 概念類似
vector<int> preorderTraversal(TreeNode *root) {
  vector<int> res;
  if (!root) return res;

  stack<TreeNode*> s;
  s.push(root);
  while (!s.empty()) {
    TreeNode *node = s.top();
    s.pop();
    res.push_back(node->val);
    if (node->right) s.push(node->right);
    if (node->left) s.push(node->left);
  }

  return res;
}

// 左 -> 中 -> 右，在 BST 中有從小到大走一遍的效果
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  if (!root) return res;

  stack<TreeNode*> s;
  s.push(root);
  TreeNode* node = root;
  
  while(!s.empty() || node) {
    while(node) {
        // 持續往左走
        s.push(node -> left);
    }
    
    // 左邊沒東西了，把自己丟到 res，pop 出 stack，看右邊可否走
    TreeNode* curNode = s.top();
    res.push_back(curNode -> val);
    s.pop();
    s.push(curNode -> right);
    node = curNode -> right;
  }

  return res;
}