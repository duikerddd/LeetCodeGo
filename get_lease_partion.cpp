//最小的k个数

//解法: 利用快排,将基准数的左边保证到k个数 
//数据结构: vector
//时间复杂度: O(n) --- 前提改变数组

vector<int>& GetLeasetNum(vector<int>&arr,int k)
{
      vector<int> top_k(k,0);
      
      if(arr.size()==0 || k<1 || k>arr.size()) return top_k;
      
      //1.用基准数分成三部分
      int left = 0;
      int right = arr.size()-1;
      int mid = Partion(arr,left,right);
      //2.判断基准数左边是否到达k个数,到达放数据结束,未到达,看实际情况确定变小范围小还是变大
      while(mid+1!=k)
      {
          //范围大了,向左缩小范围
          if(mid+1 > k)
              mid = Partion(arr,left,mid-1);
          else
          //范围小了,向右扩大范围
              mid = Partion(arr,mid+1,right);
      }
      //组织返回值
      for(int i=0;i<k;++i)
          top_k[i] = arr[i];
      return top_k;
}

//挖坑法
int Partion(vector<int>& arr,int begin,int end)
{
      int tmp = arr[begin];
      
      while(begin<end)
      {
          //右边找小数向左填
          while(begin<end && tmp<arr[end]) end--;
          arr[begin] = arr[end];
          
          //左边找大数向右填
          while(begin<end && tmp>arr[end]) begin++;
          arr[end] = arr[begin];
          
      }
      //填入tmp
      arr[begin] = tmp;
      
      return begin;
}
