//二叉树和为某一值的路径

//   10 
//  5  12
// 4 7

//和为22:  10 5 7;   10 12.
//路径: 从根到叶子

// 深度搜索,前序遍历: 
// 1.确定sum,放入路径. 判断是否到达叶子节点,比较.如果是t,则输出  不是叶子节点,继续向下深度搜索.
// 2.回溯,记得返回状态

void FindPath(BNode* root,int target)
{
    //无效输入
    if(root==NULL) return;
    
    vector<int> path;
    int sum = 0;
    Find(root,target,path,sum);
}

void Find(BNode* root,int target,vector<int>& path,int& sum)
{ 
    //1.确定当前sum和路径
    sum+=root->val;
    path.push_back(root);
    
    //2.到达叶子节点则判断
    if(root->left==NULL && root->right==NULL)
    {
        if(sum == target)
        {
            for(auto& e:path)
                cout<<*e<<" ";
            cout<<endl;
        }
 
    }
    
    //3.不是则继续深入
    if(root->left)
        Find(root->left,target,path,sum);
    if(root->right)
        Find(root->right,target,path,sum);
   
    //4.回溯到上一层
    sum-=root->val;
    path.pop_back();
     
}
