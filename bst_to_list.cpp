ListNode* BSTTODoubleList(ListNode* root)
{
    //无效输入
    if(root == NULL)
        return NULL;
    vector<ListNode*> list;    
    //中序遍历    
    InOrder(root,list);
    //连接
    for(int i=0;i<list.size()-1;i++)
    {
        list[i]->right = list[i+1];
        list[i+1]->left = list[i];
    }
    return list[i];
}
//中序遍历
void InOrder(ListNode* root,vector<ListNode*>& list)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    list.push_back(root);
    InOrder(root->right);
}
