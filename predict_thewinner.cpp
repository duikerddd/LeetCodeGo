/*给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
*/

//解题思路: 拿取限制: 只能从两端拿.     先手加分,后手减分,递归遍历所有可能,先手/后手每次选择最大的结果
//         使用递归,计算差值

//         1 5 233 7 

class Solution {
public:
   
    int total(vector<int>& nums,int left,int right)
    {
        //终止条件: 只剩一个数
        if(left == right)
            return nums[left];

        //遍历所有可能
        //左边拿
        int left_sum = nums[left] - total(nums,left+1,right);
        //右边拿
        int right_sum = nums[right] - total(nums,left,right-1);
        //每次都选最优
        return max(left_sum,right_sum);
       
    }

    bool PredictTheWinner(vector<int>& nums) {
        int sum = total(nums,0,nums.size()-1);
        return sum>=0;
    }
};
