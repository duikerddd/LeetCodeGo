//输入数字n,按顺序打印1~n位最大数

//解法: 会溢出,用字符串加法
//      比如  n=4  num[4] = {'9','9','9','9'};
//      实际上要解决字符串如何加 和 输出字符串 问题
void PrintNum(int n)
{
    if(n<=0) return;
    
    char* num = new char[n+1];
    memset(num,'0',n);
    num[n] = '\0';            //结束标志
    
    //1.递增
    while(!Increment(num))
    {
      //2.打印
      Print(num);
    }
  
    delete num;
}

bool Increment(char* num)
{
    bool is_overflow = false; //结束标志,即9999溢出
    
    int carry = 0;
    int len = strlen(num);
    
    for(int i=len-1;i>=0;i--)
    {
        //当前数
        int cur = num[i] - '0' + carry;
        //当前数+1,从个位开始
        if(i==len-1) 
          cur++;
        //有进位,改变该位,进位+1,向上递增
        if(cur>=10)
        {
            //溢出,直接退出
            if(i==0)
            {
              is_overflow = true;
              return is_overflow; 
            }
            carry = 1;
            num[i] = cur + '0';
        }
        //无进位,改变该位,加法终止
        else
        {
          num[i] = cur + '0';
          break;
        }   
    }
    return is_overflow;
}

void Print(char* num)
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
