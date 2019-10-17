#include<math.h>

bool IsPrimer(int num)
{
    //sqrt能减少判断范围,5*5=25 那么肯定有5-x * 5+x = 25,所以判断一小半就够了
    for(int i=2;i<=sqrt(num);++i)
    {
        if(num%2==0 && num>2)
        {
            return false;
        }
        
        if(num%i==0)
        {
            return false;
        }   
    }  
    return true;
}

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        //循环内判断每个质数
        for(int i=2;i<n;++i)
        {
            if(IsPrimer(i))
            {
                ++count;
            }
        }
        return count;
        
    }
};
