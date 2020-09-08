//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

//解题思路: 1.堆排 2.快排变形
//解法: 使用哈希表存储数据和次数,用次数排序
class MyCompare{
public:
    bool operator()(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.second>p2.second;
    }

};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //统计频率
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();++i)
        {
            count[nums[i]]++;
        }

        //排序频率
        priority_queue<pair<int,int>,vector<pair<int,int>>,MyCompare> heap;
        auto it = count.begin();
        while(it!=count.end())
        {
            heap.push(*it);
            if(heap.size()>k)
            {
                heap.pop();
            }
            ++it;
        }

        //因为是小根堆,所以倒叙插入数组
        vector<int> ret(k);
        for(int i=k-1;i>=0;--i)
        {
            ret[i] = heap.top().first;
            heap.pop();
        }

        return ret;
    }   
};
