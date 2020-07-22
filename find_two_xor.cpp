//一个数组,只有两个数字单独存在,其余都是成对的,求这两个数

//解题思路: 考察位运算^.  只有一个数字的话,直接^就是答案. 两个数字,^结果则显示的两个数字的异同点,从异这块突破
//解法: 1.^出两个数字的结果 2.将结果的一个1拿出来,用这个1在^一遍,可以将数字分为两组. 这两组恰好就是只有一个单独的数字问题.

void FindNumOnce(int *data, int len, int *num1, int* num2)
{
      //无效输入
      if(data==NULL || len<1) return;
      
      //第一次异或求两数的异
      int first_xor = 0;
      for(int i=0;i<len;++i)
          first_xor^=data[i];
          
      //找出一位1(最后一位)
      int end_one = 0;
      for(int i=0;i<32;++i)
      {
          if((first_xor>>i) & 1 ==1)
          {
                end_one = i;
          }
      }
      
      //用这个1切分
      for(int i=0;i<len;++i)
      {
          if((data[i]>>end_one) & 1)
              *num1^=data[i];
          else
              *num2^=data[i];
      }
}
