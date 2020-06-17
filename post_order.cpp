//判断是否为二叉搜索树的后序遍历

//    4
//  3   5
// 1  2
// postorder: 2 1 3 5 4 

// 例如: 2 1 3 5 4
// 递归: 1.后序遍历首先确定根, 4 
//       2.由4确定左右子树,第一个大于root的值 213 5
//       3.判断右子树是否满足条件,没有小于root的(因为步骤2找的第一个大于root的,所以左子树肯定都小于root,只有右子树有可能出问题)
//       4.递归判断左右子树
//       终止条件: 左右子树没有元素

bool PostOrder(int* root,int len)
{
    //1.确定根
    int r = len - 1;
    int right = 0;
    
    //2.确定左右子树
    for(int i=0;i<r;++i)
    {
        if(root[i]>root[r]){
            right = i;
            break;    
        }
    }
    
    //3.判断右子树
    for(int i=right;i<r;++i)
    {
         if(root[i]<root[r])
             return false;
    }
    
    //4.递归判断左右子树
    //终止条件: right所处位置有左右子树
    bool left=true,right=true;
    if(right>0)
        bool left = PostOrder(root,right);
    if(right<r)
        bool right = PostOrder(root+right,r-right);
        
    return left && right;
}
