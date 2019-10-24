/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MAX(a,b) ((a)>(b)?(a):(b))

class Solution {
public:
    int maxDepth(TreeNode* root) {
    //结束条件: 走到空结点
    if (root == NULL)
	{
		return 0;
	}
    
	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);

	//注意下,不要多次调用
	return MAX(leftHeight, rightHeight) + 1;
    }
};
