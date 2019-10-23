class Solution {
public:
    //此题可以用新的数组只push单一元素,但是要原地修改
    //所以用数组题的法宝: 指针和临时变量
    int removeDuplicates(vector<int>& nums) {
        //排除特殊条件: 空
        if(nums.size()==0) return 0; 
        //快慢指针, 记录不相同元素所处下标,只有不同时才向后一个位置
        int pos = 0;
        //寻找不相同元素,并赋值于nums[pos]中
        for(int i=1;i<nums.size();++i)
        {
            if(nums[pos] != nums[i])
            {
                //这里注意先+,要不然会覆盖
                 ++pos;
                nums[pos]=nums[i];  
            }
        }
         return pos+1;
    }
   
};
