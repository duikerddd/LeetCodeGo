//求数组中最小的k个数

//解法思路: 使用堆排序,建大堆-->得到降序输出前k个元素
//数据结构: 完全二叉树(完全左对齐,层序遍历可得) --> 数组
//           i->left = 2*i+1 ; i->right = 2*i+2
//           i = (left-1)/2 = (right-2)/2(计算机只会整除,所以right-1也能求结果)  --> parent = (child-1)/2 
//时间复杂度:O(NlogN)

//大根堆: 所有根>=左右孩子
//向下调整: 1.选最好的孩子
//          2.与根比较,如果孩子更好,根与孩子交换,根继续向下调整;否则根满足最好直接退出
void GetLeastNumofArr(const vector<int>& data,int k)
{
    //1.建大堆(所有非叶子节点向下调整,得到大堆)
    int n = data.size()-1;
    for(int i = (n-1)/2;i>=0;--i)
        AdjustDown(data,i,n);
    
    //2.向下调整(堆顶与最后一个节点交换,固定在数组,对新节点进行向下调整,重复直到全部固定完成)
    for(int i= n-1;i>0;--i){
        swap(data[0],data[i]);
        AdjustDown(data,0,i);
        }
    
    //3.输出前k个元素
    for(int i=0;i<n;++i)
        cout<<data[i]<<" ";
    cout<<endl;    
}

//大堆-->降序 
void AdjustDown(vector<int>& arr,int root,int end)
{
    int cur = root;
    int child = 2*root+1;
    
    //左孩子没越界
    while(left<end)
    {
        //找左右孩子中最小的,注意右孩子越界
        if(child+1<end && arr[child]>arr[child+1])
        {
            child++;
        }
        
        //比较,孩子更好则交换,父亲继续向下调整
        if(arr[child] < arr[cur])
        {
            swap(arr[child],arr[cur]);
            cur = child;
            child = cur*2+1;
        }
        else
            break;
    }
}
