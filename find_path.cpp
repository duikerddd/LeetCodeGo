void Find(BTNode* root,int target,vector<int>& path,int& sum)
{
    sum += root->val;
    path.push_back(root->val);
    
    //是叶子节点,比较
    if(root->left==NULL && root->right==NULL){
        if(sum == target)
         {
             for(it:path)
                 cout<<*it<<" ";
             cout<<endl;    
         }   
    }
    //不是叶子节点,压栈
    if(root->left!=NULL)
        Find(root->left,target,path,sum);
    if(root->right!=NULL)
        Find(root->right,target,path,sum);
        
    //在返回父节点之前,减去现在处于的节点值
    sum -= root->val;
    path.pop_back();            
}

void FindPath(BTNode* root,int target)
{
    //无效输入
    if(root==NULL)
        return;
        
    vector<int> path;
    int sum = 0;
    Find(root,target,path,sum);    
}
