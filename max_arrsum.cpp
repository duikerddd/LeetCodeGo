//求一个数组中连续和的最大值
//动态规划
//F(i): 以i结尾的最大和
//递推公式: F(i) = max(F(i-1)+arr[i],arr[i])
//初始值: F(0) = arr[0];
//结果: F(i)中的最大值
#include<vector>
#include<algorithm>
using namespace std;

class Soultion{
    public:
      int FindGreatestSumofArray(vector<int> array)
      {
           int size = array.size();
           vector<int> ret_sum(size,0);
           ret_sum[0] = array[0];
           int max = ret_sum[0];
           
           for(int i=1;i<size;++i)
           {
                ret_sum[i] = max(ret_sum[i-1]+array[i],array[i]);
                max = (max<ret_sum[i]?ret_sum[i]:max);
           }
           
          /* 取最大值在上面简化了
           for(int i=0;i<size;++i)
           {
                 if(max<ret_sum[i])
                    max = ret_sum[i];
           }
           */
           
           return max;
      }
};
