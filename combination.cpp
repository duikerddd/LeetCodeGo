//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 //target 的组合。

//解题思路: dfs 组合.
//         if sum==target 加入组合; sum>target 剪枝后面的
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> stack;

    void dfs(vector<int>& candidates,int begin,int sum,int target)
    {
        //终止条件
        if(sum==target)
        {
            ret.push_back(stack);
            return ;
        }
        else if(sum > target)
        {
            return ;
        }
        //遍历所有情况
        for(int i=begin;i<candidates.size();++i)
        {
            sum+=candidates[i];
            stack.push_back(candidates[i]); 

            dfs(candidates,i,sum,target); //可重复,所以i不变
            sum-=candidates[i];
            stack.pop_back();
        }
        return;
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        dfs(candidates,0,0,target);
        return ret;
    }
};
