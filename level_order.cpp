/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>

class Solution {
public:
    //广度优先遍历 :  队列实现
    //终止条件: 队列为空
    //遍历方式: 计算队列长度,保证取出同一层,  走一个节点,将该结点孩子放进来
    vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> ret;
            if(root == NULL) 
                    return ret;
            
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* node;
            while(!q.empty())
            {
                vector<int> floor;
                int width = q.size();
                for(int i=0;i<width;++i)
                {
                    node = q.front();
                    floor.push_back(node->val);
                    q.pop();
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                ret.push_back(floor);
            }
        
            return ret;
    }
};
