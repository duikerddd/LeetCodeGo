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
    //stack
    // 根右左->左右根 
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ret;
       
        while(!s.empty() || root)
        {
            if(root!=nullptr)
            {
                s.push(root);
                ret.push_back(root->val);
                root=root->right;
            }
            else
            {
                root = s.top();
                s.pop();
                if(root->left)
                {
                    root = root->left;
                }
                else
                {
                    root=nullptr;
                }
            }
        }
        reverse(ret.begin(),ret.end());
      
        
        return ret;
    }
};
