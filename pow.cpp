//1.指数==0,无意义输入
//2.底数==0,无意义输入
//2.指数<0,取绝对值求倒数
class Solution {
public:
    //判断浮点数相等,在一定精度内相等即可
    bool IsZero(double n1,double n2)
    {
        if(n2-n1<0.000001 && n2-n1>-0.00001)
            return true;
       return false;     
    }
    
    double Power(double base, int exponent) 
    {
        if(exponent==0 || IsZero(base,0.0))
            return 1;
        double tmp=base;
        int flag=exponent;

        exponent=abs(exponent);        //取绝对值
        for(int i=1;i<exponent;i++)    //幂运算
            base=base*tmp;
        if(flag<0)                      
            base=1.0/base;
        return base;
    }
};
