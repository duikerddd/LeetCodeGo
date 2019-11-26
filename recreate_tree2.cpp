BNode* ReCreateTree(int* postorder,int* inorder,int size)
{
    //终止条件,该节点为叶子结点
    if(size<=0)
        return NULL;
    
    int root_val = postorder[size-1];
    int i,in_root;  //in_root为中序的根节点
   
    for(int i=0;i<size;++i)
    {
        if(inorder[i]==root_val)
        {
            in_root = i;
            break;
        }
    }        
    
    BNode* root = CreateNode(root_val);
    root->left = ReCreateTree(postorder,inorder,in_root);
    root->right = ReCreateTree(postorder+in_root+1,inorder,.size-in_root-1);
    
    return root;
} 
