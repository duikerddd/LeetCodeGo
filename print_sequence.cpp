void PrintSequence(BTNode* root)
{
    //没有节点
    if(root==NULL)
        return;
            
    queue<BTNode*> q;
    q.push_back(root);
    while(q)
    {
        BTNode* cur = q.front();
        cout<<cur->val;
        q.pop();
        
        if(cur->left)
            q.push_back(cur->left);
        if(cur->right)
            q.push_back(cur->right);    
    }
}
