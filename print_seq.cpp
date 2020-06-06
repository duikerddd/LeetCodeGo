//层次遍历打印二叉树
// 队列
// 1.压入root,打印
// 2.弹出队首,将其孩子压入
// 3.重复1.2直到空

void PrintSequeue(BNode* root)
{
    //没有节点
    if(root == NULL) 
    return;
    
    //辅助队列
    queue<BNode*> q;
    q.push_back(root);
    
    while(!q.empty())
    {
       //打印
       cout<< q.front()->val <<endl;
    
        //删除
        BNode* tmp = q.front();
        q.pop();
        
        //压入孩子
        if(tmp->left)
        q.push_back(tmp->left);
        if(tmp->right)
        q.push_back(tmp->right);
    }
}
