class Solution {
public:
    //无进位直接返回
    //不是9直接+1返回,是9就该位置0进位,如果都是9,最后出来进位1
    vector<int> plusOne(vector<int>& digits) {
       
        int len = digits.size();
        for(int i = len - 1; i >= 0; i--) {
            if(digits[i]==9)
                digits[i] = 0;
            else{
               digits[i]++;
               return digits;
            }
        }
        auto it = digits.begin();
        digits.insert(it,1);
        
        return digits;
    }
};
