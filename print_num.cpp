//打印1~n位数字
void PrintNumber(int n)
{
    //错误输入
    if(n<0)
         return;
     
    char* number = new char[n+1];    //字符串表示数字
    memset(number,'0',n);           //从0开始
    number[n] = '\0';               //结束标志
    
    //递增和打印,溢出不打印
    while(!Increment(number))
            Print(number);
     
    delete number;        //注意释放空间    
}
 
 //递增
 bool Increment(char* number)
 {
     //初始状态
     bool is_overflow = false;
     int carry = 0;
     int len = strlen(number);
     
     //从个位开始,+1后,观察整个数组是否进位,没有进位直接返回
     for(int i=len-1;i>=0;--i)
     {
         int num = number[i] - '0' + carry;   //该位置数字
         if(i == len - 1)             //个位加1,number完成递增
             num++;
         if(num >= 10)                //进位 or 溢出?
         {
             if(i==0)                 //最高位溢出
                 is_overflow = true;
             else{                    //按正常进位计算
                 carry = 1;
                 number[i] = '0' + num - 10;
             }          
         }    
         else                         //按正常不进位计算
         {
             number[i] = '0' + num;
             break; 
         }
     }
     return is_overflow;
 }
 
//打印,atoi
void PrintNumber(char *number)
{
    bool isBeginning0 = true;    //是否以零作为开头，默认为是
    int len = strlen(number)
    for(int i = 0; i<len-1; i++)
    {
        if(isBeginning0 && number[i] != '0')    //当不等于0时候
            isBeginning0 = false;    //置为0，为了输出
        if(!isBeginning0)
            cout << number[i];
    }
    cout <<"\t";    
}
