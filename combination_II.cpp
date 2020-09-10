//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用一次。

//解题思路: dfs+剪枝, 和昨天不一样的是,有重复元素,选择标记或者剪枝

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;

    void dfs(vector<int>& num,int target,int begin,int sum)
    {
        //终止条件找到了
        if(sum==target)
        {
            ret.push_back(tmp);
            return;
        }
       

        //< 正常遍历
        for(int i=begin;i<num.size();++i)
        {
             //大剪枝: 后面元素均不考虑
            if(sum>target)
            {
                return;
            }

            //小剪枝: 去重
            if(i>begin && num[i-1]==num[i])
                    continue;
            
            sum+=num[i];
            tmp.push_back(num[i]);
            
            //i+1 i前面的元素都是使用过的
            dfs(num,target,i+1,sum);

            sum-=num[i];
            tmp.pop_back();
        
        }
        return;

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0);
      
        return ret;    
    }
};
