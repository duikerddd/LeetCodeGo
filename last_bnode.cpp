 bool IsBalanceBT(BTNode* root,int* depth)
 {
    if(root==NULL)
    {
        *depth = 0;
        return true;
    }
    
    int left=0,right=0;
    if(IsBalanceBT(root->left,&left) && IsBalance(root->right,&right))
    {
         int dif = left - right;
         if(dif>-1 || dif<1)
         {
            *depth = 1 +  (left>right?left:right);
            return true;
         }
    }
    
    return false;
 }
