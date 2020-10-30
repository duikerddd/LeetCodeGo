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
        TreeNode* rp = nullptr;

        while(!s.empty()||root)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }

            root = s.top();
            //结束的条件即右节点返回. 记录每次返回的右节点就知道根什么时候能输出了
            if(root->right==nullptr || rp==root->right)
            {
                  ret.push_back(root->val);
                  rp = root;
                  s.pop();
                  root=nullptr;
            }
            else
            {
                root = root->right;
            }

        }
        
        
        return ret;
    }
};
