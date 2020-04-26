//判断是否为红黑树
bool isRBTree()
{
    pNode root = _header->_parent;
    
    if(root == nullptr) return true;
    //1.根是否黑色
    if(root->_color == RED)
    {
        cout<<"根节点必须是黑色!"<<endl;
        return false;
    }
    //2.每条路径黑色个数相同?
    //可以任意遍历一条(最右)路径获取黑色节点数量
    pNode cur = root;
    int black_count = 0;
    while(cur)
    {
        if(cur->_color == BLACK)
            ++black_count;
        cur = cur->_right;
    }
    int k = 0;
    return _isRBTree(root,k,black_count); 
    
}

//看每一条路径是否和基准值相同
bool _isRBTree(pNode root,int curCount,int count)
{
    //终止条件: 一条路径走完
    if(root==nullptr){
        if(curCount != count)
        {
            cout<<"每个路径黑色节点个数不同"<<endl;
            return false;
        }
        return true;
    }
    
    if(root->_color == BLACK)
        ++curCount;
        
    //3.没有红色连续的?
    pNode parent = root->_parent;
    if(parent && parent->_color == RED && root->_color == RED)
    {
        cout<<"有红色连续的节点"<<endl;
        return fasle;
    }
    
    return _isRBTree(root->_left,curCount,count)
    && _isRBTree(root->_right,curCount,count);
}
