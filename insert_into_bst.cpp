/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //递归
    // <去左  >去右  找到空插入
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)return new TreeNode(val);
        
        if(root->val > val)
        {
            root->left = insertIntoBST(root->left,val);
        }
        else if(root->val < val)
        {
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};
