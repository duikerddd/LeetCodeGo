/*解决: 画图
  过程:  (1)交换左右子结点	
         (2)交换左子结点的左右结点
         (3)交换右结点的左右结点
*/         
void Mirror(BTNode* root)
{
    //终止条件: 该结点为空
    if(root == NULL)
        return;
    
    //交换
    BTNode* tmp = root->left;
    root->left = root->right;
    root->right = root->left;
    
    //交换左右子树
     return Mirror(root->left) && Mirror(root->right);        
}
