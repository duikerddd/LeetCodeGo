//给定一个可包含重复数字的序列，返回所有不重复的全排列。
/*
    输入: [1,1,2]
    输出:
    [
     [1,1,2],
     [1,2,1],
     [2,1,1]
    ]
*/

//解题思路: dfs全排列 + 结果find去重(find时间复杂度爆炸)x
//解题思路: dfs全排列 + 枚举时set去重

class Solution {
public:
    
    vector<vector<int>> ans;
   
    void dfs(vector<int>& nums,int cur)
    {
        //终止条件: 一次排列完成,放入ans
        if(cur == nums.size())
        {
                ans.push_back(nums);
                return;
        }
    
        //枚举时去重，每个位置的数字，只使用一次
        unordered_set<int> unique;
        //遍历所有情况
        for(int i=cur;i<nums.size();++i)
        {
            if(unique.count(nums[i])){
                continue;
            }
            
            //处理当前: 放入当前位置的数字
            swap(nums[cur],nums[i]); 
            //深入
            dfs(nums,cur+1);
            //回溯
            swap(nums[cur],nums[i]);
            //标记
            unique.insert(nums[i]);
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        dfs(nums,0);
        return ans;
    }

    
   

};
