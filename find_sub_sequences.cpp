//递增子序列
//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

//解题思路: 全排列+去重

class Solution {
public:
    // 判重代码: 判断当前位置的数字 是否与 (stack最后一个数在num的位置,当前数字在num的位置)有相同的,有则表示此组序列已经表示过了
    bool is_first(const vector<int> &num, int last, int pos) {
        for(int i = last+1; i < pos; i++) {
            if(num[i] == num[pos]) {
                return false;
            }
        }
        return true;
    }
    void dfs(const vector<int> &nums, int last, int pos, vector<int> &stack, vector<vector<int>> &anw) {
        //路走到头,返回
        if(nums.size() == pos) { return; } 

        //遍历所有路的可能
        for(int i=pos;i<nums.size();++i){
            //选择一条路: 检查 nums[i] 是否符合要求
            if((stack.empty() || nums[i] >= stack.back()) && is_first(nums, last, i)) {
                stack.push_back(nums[i]);
                //大于 2 了，那就放进去吧
                if(stack.size() >= 2) {  
                       anw.push_back(stack);
                } 
                // 深入: 继续处理下一个
                dfs(nums, i, i+1, stack, anw); 
                // 回溯: 取出当前pos
                stack.pop_back(); 
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> anw;
        vector<int> stack;
        dfs(nums, -1, 0, stack, anw);
        return anw;
    }

};
