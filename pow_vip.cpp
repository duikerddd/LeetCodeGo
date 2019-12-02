//终极解法: 位运算 --- 将指数分解成二进制,底数指数递推,指数位为1,乘相应的底数值
class Solution {
public:
    double Power(double base, int exponent) 
    {
        int flag=abs(exponent);   //取指数绝对值
        double result=1.0;
        while(flag)               //指数不为0
        {
            if(flag & 1)
                result=result*base;         //结果x 2^n幂值
            base=base*base;                //相应的指数对应值
            flag>>=1;                      //指数递推
        }
        return(exponent>0)?result:1.0/result;
    }
};
