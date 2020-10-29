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
    //解题思路
    //stack 
    //递归 root->left  cout 
    //回溯 root  && root->right(left到头)  
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
        while(root!=nullptr)
        {
            s.push(root);   
            root=root->left;
        }

        while(!s.empty())
        {
            root = s.top();s.pop();
            ret.push_back(root->val);
            
            if(root->right!=nullptr)
            {
                 s.push(root->right);
                 root = root->right->left;
                 while(root!=nullptr)
                 {
                    s.push(root);
                    root = root->left;
                 }   
            }
        }
        return ret;
    }
    
};
