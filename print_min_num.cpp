/*自定义排序规则,字符串拼接两数后比较,得到的结果顺序即为最小数
 *{3,32,321}
 *1.332 323 ->  32<3
 *2.3213 3321 -> 321<3
 *3.32132 32321-> 321<32
 *-->{321,32,3}
 */
class Solution {
public:
	//排序规则,字符串表示是为了防止溢出
    static bool cmp(int a, int b)
    {
        string A = "";
        string B = "";
        
        A+=to_string(a);
        A+=to_string(b);
        B+=to_string(b);
        B+=to_string(a); 
        return A<B;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";
        string ret = "";
        sort(numbers.begin(),numbers.end(),cmp);
        for(size_t i = 0; i < numbers.size(); ++i)
            ret += to_string(numbers[i]);
        
        return ret;
    }
};

