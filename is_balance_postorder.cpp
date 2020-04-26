bool IsBalanceBT(BTNode* root,int* depth)
 {
     //终止条件
     if(root==NULL)
     {
         *depth = 0;
         return true;
      }
     
     int left,right;
     if(IsBalanceBT(root->left,&left) && IsBalanceBT(root->left,&right))
     {
         int dif = left - right;
         if(dif>=-1 || dif<=1)
         {
             *depth = 1 + (left>right?left:right);
             return true;
         }
     }
     
     return false;
 }
