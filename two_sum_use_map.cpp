class Solution {
public:
    //解题思路: map存储<num,inx>,找到差值则返回,没找到则插入
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    map<int,int> m;

    for(int i=0;i<nums.size();i++)
    {
        int dif = target - nums[i];
        if(m.find(dif)!=m.end())
        {
            ret.push_back(m[dif]);
            ret.push_back(i);
            break;
        }

        m[nums[i]] = i;
    }
   
    return ret;
    }

};
