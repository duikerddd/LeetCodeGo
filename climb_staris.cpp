class Solution {
public:
    //动态规划
    //F(i) 到达第i阶方案数
    //递推公式: F(i) = 1*F(i-1) + 1*F(i-2); 
    //初始值: F(1) = 1; F(2) = 2; 
    //返回值 F(i)
    int climbStairs(int n) {
        vector<int> F(n+1,0);
        F[1] = 1;
        //只有一个台阶
        if(n==1)
        {
            return 1;
        }
        F[2] = 2;
        for(int i=3;i<=n;++i)
        {
            F[i] =F[i-1] + F[i-2]; 
        }
        return F[n];
    }
};
