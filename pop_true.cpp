class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //无效输入
        if(pushV.empty() || pushV.size() == 0) 
            return false;
            
        vector<int> stack;
        for(int i = 0,j = 0 ;i < pushV.size();){
            stack.push_back(pushV[i++]);
            //相等则弹出
            while(j < popV.size() && stack.back() == popV[j]){
                stack.pop_back();
                j++;
            }      
        }
        //返回是否为空
        return stack.empty();
    }
};
