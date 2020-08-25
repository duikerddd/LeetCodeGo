//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//解题思路: dfs全排列

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums,int begin)
    {
        //终止条件: 一条路走到黑
        if(begin == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        //遍历所有情况
        for(int i=begin;i<nums.size();++i)
        {
            //选择一条合适的路线
            swap(nums[begin],nums[i]);
            //递归
            dfs(nums,begin+1);
            //回溯
            swap(nums[begin],nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};
