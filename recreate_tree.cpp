BNode* CreateNode(int val)
{
    BNode* tmp = (BNode*)malloc(sizeof(BNode));
    if(tmp==NULL)
    {
        perror("no mem");
        return;
    }
    tmp->val = val;
    tmp->left=tmp->right->NULL;
    return tmp;
    
}
BNode* ReCreateTree(BNode* preorder,BNode* inorder,int size)
{
    //终止条件,该节点为叶子结点
    if(size<=0)
        return NULL;
    
    int root_val = preorder[0];
    int i,in_root;
    for(int i=0;i<size;++i)
    {
        if(inorder[i]==root_val)
        {
            in_root = i;
            break;
        }
    }        
    
    BNode* root = CreateNode(root_val);
    root->left = ReCreateTree(preorder+1,inorder,in_root);
    root->right = ReCreateTree(preorder+in_root+1,inorder,size-in_root-1);
    
    return root;
} 
