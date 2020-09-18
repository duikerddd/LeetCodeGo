
//此题简单,使用to_string把数字转换为string
class Solution {
public:

    vector<string> fizzBuzz(int n) {
        vector<string> vecS;
        for(int i=1;i<=n;++i)
        {
            if(i%15==0)
            {
                vecS.push_back("FizzBuzz");  
            }
            else if(i%3==0)
            {
                vecS.push_back("Fizz");
            }
            else if(i%5==0)
            {
                vecS.push_back("Buzz");      
            }
            else
            {   
                vecS.push_back(to_string(i));
            }
        }
        return vecS;
    }
};
