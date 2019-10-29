/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归解决: 递归终止条件:递归到空
//         递归公式: 左节点==右节点&&左子树的左=右子树的右&&左子树的右=右子树的左
bool isMirror(TreeNode* left,TreeNode* right)
{
    if(left == NULL && right==NULL)
    {
        return true;
    }
    if(left == NULL || right==NULL )
    {
        return false;
    }        
    return (left->val == right->val)
            && isMirror(left->right, right->left)
            && isMirror(left->left, right->right);

}

class Solution {
public:
    
    
    bool isSymmetric(TreeNode* root) {
            return isMirror(root,root);    
        }
};
