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
    //递归终止条件 : 空
    //递推公式 : 是否相同
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //都为空
        if(p == NULL && q==NULL)
        {
            return true;
        }
        //有一个为空
        if(p == NULL || q==NULL)
        {
            return false;
        }
        
        //两个都不为空,相等继续递归,不相等直接退出
        if(p->val == q->val){
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        else
        {
            return false;
        }
    }
};
