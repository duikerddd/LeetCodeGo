/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

//地形变成二叉树
//线路: 
//dp[i]: 打劫到第i家时候,最大的抢劫数
//dp[i] = max(dp[i->father->father]+vi, dp[i->father])
//init: dp[root] = v0;
//border: i=# return 0;  i<arr.size()

//递归版本: 存在重复子问题

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here
        if(root==NULL) return 0;
       
       //不打劫第i家
        int no_root = houseRobber3(root->left) + houseRobber3(root->right);  
        //打劫第i家 
        int with_root = root->val;
        if(root->left)
        {
            with_root+=houseRobber3(root->left->left);
            with_root+=houseRobber3(root->left->right);
        }
        if(root->right)
        {
            with_root+=houseRobber3(root->right->left);
            with_root+=houseRobber3(root->right->right);
        }
                
        return max(no_root,with_root);
    }
};
