//判断是否为平衡二叉树

//   1
// 2   3
//4 5  

//解题思路: 平衡二叉树性质: 左右子树高度差不超过1 
//解法:  a.前序遍历     1.计算左右子树高度,比较差值.看是否满足平衡二叉树 2.左右子树递归.
 //      b.后序遍历     1.左右子树递归                                  2.回溯记录长度,比较高度差,看是否满足平衡二叉树.

//前序遍历
bool IsBalnaceTree(Node* root)
{
    //终止条件
    if(root==NULL) return true;
    
    int left = Height(root->left);
    int right = Height(root->right);
    
    int dif = left-right;
    if(dif<=1 || dif>=-1) return true;
    
    return false;
 }

bool IsBalanceTree(Node* root,int* depth){
    //终止条件
    if(root==NULL)
    {
        *depth = 0;
        return true;
    }
    
    //1.后序遍历
    int left,right;
    if(IsBalanceTree(root->left,&left) && IsBalanceTree(root->right,&right))
    {
          int dif = left - right;
          if(dif>=-1 || dif<=1) 
          {
              *depth = 1+(left>right?left:right);
              return true;
          }
    }
    
    return false;  
    
}
