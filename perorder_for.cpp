/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //非递归前序遍历--- 根,左,右 
    //stack r  cout  ->left 
    //left->right 
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;

        if(root==nullptr) return v;
 
        while(!s.empty() || root)
        {
            if(root!=nullptr)
            {
               s.push(root);
               v.push_back(root->val);
               root=root->left;
            }
            else
            {
               root=s.top();
               s.pop();
               root=root->right;
            }
        }

        return v;
    }
};
