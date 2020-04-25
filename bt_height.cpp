int BTHeight(BTNode* root)
{
    //终止条件
    if(root->NULL)
        return 0;
        
    int leftHeight = BTHeight(root->left);
    int rightHeight = BTHeight(root->right);
    
     return leftHeight>rightHeight?leftHeight+1:rightHeight+1; 
}
