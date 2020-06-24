//丑数
//只有因子2,3,5
//第一个丑数为1

//求第n个丑数

//解法1: 暴力求解,count计数,从1开始,一直到count为n

//解法2: 1.创建一个只放丑数的数组 2.从1开始,排序丑数(2,3,5形成三个队列,每次挑选其中最小的位第二个丑数,注意去重)
//数据结构: 下标模拟队列
//时间复杂度: O(N)

/* [1] [] [] [] [][]
    0  1   2  3  4  5
t2: 1  
    0  
t3: 1
    0
t5: 1
    0
*/

long GetUN(int index)
{
    if(index<1) return 0;
    
    //1.创建丑数数组
    vector<int> un_arr(index,1);
    
   //初始化三个队列
   int t2 = 0;
   int t3 = 0;
   int t5 = 0;
   
   //2.排序丑数
   for(int i=1;i<index;++i)
   {
      //三数中,选最小的出队
      un_arr[i] = min(un_arr[t2]*2,min(un_arr[t3]*3,un_arr[t5]*5));
      
      //更新队列并去重
      if(un_arr[i] = un_arr[t2]*2)
        t2++;
      if(un_arr[i] = un_arr[t3]*3)
        t3++;
      if(un_arr[i] = un_arr[t5]*5)
        t5++;   
   }
   
   return un_arr[index-1];
}
