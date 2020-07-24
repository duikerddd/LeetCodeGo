//反转字符串
//i am s
//s ma i

//i am s
//s am i
//s ma i
//思路: 反转算法
//解法: 1.整体反转 2.局部反转

void Reverse(char* begin,char* end)
{
    while(begin<end)
    {
        char tmp=*begin;
        *begin = *end;
        *end = *begin;
        
        begin++;
        end--;
    }
}

char* ReverseSentence(char* s,int len)
{
    if(s==NULL) return "";
    
    Reverse(s,s+len);
    int *begin = 0,*end = 0;
    while(*s!='\0')
    { 
      if(*s==' '){
        end = s;
        end--;
        Reverse(begin,end);
        begin= s;
        begin++;
      }
      s++;
    }
    
    return s;
}
