class Solution {
public:
    //双指针,index负责返回数组下标
    //不同: index++ , i++   
    //相同: index   , i++  记录该位置,遇到不同的直接覆盖
    int removeElement(vector<int>& nums, int val) {
            int index = 0;  
            for(int i=0;i<nums.size();++i)
            {
                if(nums[i]!=val)
                {
                    nums[index++]=nums[i];
                }
            }
        
            return index;
    }
};
