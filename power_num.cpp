//实现数值的整数次方

//解法1: 直接计算
//   ps : 浮点数比较,用差值范围,因为计算机表示不完全
double Power(double base,int exponent)
{
    //base==0 || exponent==0
    if(exponent==0 || (base-0.0<0.000001 && base-0.0>-0.000001)) return 1;
    
    double ret = 1;
    //标记指数的正负
    int flag = exponent;
    
    //取绝对值
    exponent = abs(exponent);
    //幂运算
    while(exponent--)
      ret*=base;
      
    if(flag<0)
      ret = 1.0/ret;
      
    return ret;   
}

//解法2: 位运算 快速幂
// n^7 = n^4 * n^2 *n^1
 //        1    1   1
double Power(double base,int exponet)
{
    //base==0
    if(base-0.0<0.000001 && base-0.0>-0.000001) return 1;
   
    int flag = abs(exponet);
    double ret = 1;
    //指数不为0
    while(exponet)
    {
        if(exponet&1)
          ret*=base;
        base*=base;
        exponet>>=1;
    }
    
    return flag>=0?ret:1.0/ret;
}
