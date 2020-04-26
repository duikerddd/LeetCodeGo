bool IsBalanceBT(BTNode* root)
{
    //终止条件
    if(root==NULL)
        return true;
        
    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);
    int dif =  leftHeight - rightHeight;
    if(dif>1 || dif<-1)
        return false;
        
    return IsBalanceBT(root->left)&&IsBalanceBT(root->right); 
}
