//数组中超过一半的数

//算法: 计数器
//      记录一个数字的次数,遇到不同--,相容++,如果count==0,将下一个数作为ret
//数据结构: int

//     1 3 2 5 2
//count
//ret   

int MoreTimesNum(vector<int>& arr)
{
      if(arr.empty()) return 0;
      
      int count = 1;
      int ret = arr[0];
      for(int i=1;i<arr.size();++i)
      {
          if(count==0)
            ret = arr[i];
          else if(ret == arr[i])
            count++;
          else
            count--;
          }
      }
      return ret;
}
