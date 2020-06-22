//最小的k个数

//解法: 1.将数据放入容器 2.满了之后插入数据,与第一个最大数比较
//数据结构: multiset,容器固定,适用于海量数据处理. 

multiset<int>& GetLeastNumofArr(const vector<int>& data,int k)
{
    //multiset, 从小到大
    multiset<int,greater<int>> set_top;

    if(data.empty() || k>data.size() || k<1) return set_top;
    
    //放入数据
    for(int i=0;i<data.size();++i)
    {
        //未满直接放
        if(set_top.size() < k)
        {
            set_top.insert(data[i]);
        }
        //满了,比较插入(第一个最大)
        else
        {
            auto it = set_top.begin();
            if(*it < data[i])
            {
                set_top.erase(it);
                set_top.insert(data[i]);
            }
        }
    }
    
    return set_top;
}
