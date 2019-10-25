
class Solution {
public:
    //暴力解答: 两层循环寻找符合的两个值
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i = 0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i]+nums[j]==target && j!=i) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    //使用map存储每个元素和索引值,用差值寻找到则返回,没找到则插入该元素和索引值
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> record;
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
        {
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                ret.push_back(record[complement]);
                ret.push_back(i);
                break;
            }

            record[nums[i]] = i;

        }
        return ret;
    }
};
