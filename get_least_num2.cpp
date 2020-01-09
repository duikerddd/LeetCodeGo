//解法二:  建立一个固定大小容器,填满值. 每次插入新值与容器最大值比较,若是小于最大值,交换
//容器选择: multiset,可以自动排序 (红黑树,查找快)
//O(nlgn) ,适合处理海量数据
multiset<int>& GetLeastNumofArr(const vector<int>& data,int k)
{
    //无效输入
    if(k<1 || k>data.size())
        return;
    multiset<int,greater<int>> min_set;  //第二个参数为比较方式
    auto it = data.begin();
    for(it;it!=data.end();++it)
    {
        //容器未满,直接插入
        if(min_set.size()<k)
            min_set.insert(*it);
        else
        {
            //容器已满,比较是否交换
            auto max = min_set.begin();
            if(*max > *it)
            {
                min_set.erase(max);
                min_set.insert(*it);
            }
        }    
    }
    return min_set;
}
