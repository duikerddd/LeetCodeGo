class Solution {
public:
    //1.跳空格 --> 确定正负  --> 计算数字(要有溢出判断)
    int myAtoi(string str) {
        if(str.empty() || str.length()==0)
            return 0;
        //1.跳过空字符
        int i =0;
        while(i<str.length() && str[i]==' '){
            i++;
        }
        //此时,i指向第一个不为空的字符 或者 i越界
        if(i==str.length())
            return 0;

        //2.判断数字的符号
        int flag=1;
        char ch = str[i];
        if(ch=='-')
        {
            flag=-1;
        }
        if(ch=='+' || ch=='-'){
            i++;
        }          

        //3.找出数字部分
        int res = 0;
        for(; i<str.length(); i++){
            ch = str[i];
            if(ch<'0' || ch>'9')
                break;
            
            //溢出判断
            //数字是按*10增长的
             //1.数字/10(溢出前最大值)>最大数/10  
             //2.数字(溢出最大值) == 最大数/10 并且 最后一位数字>7(因为最大数最后一位为7)  
             if(res>INT_MAX/10 ||  res==INT_MAX/10 && (str[i]-'0')>7 )
                         return flag==1?INT_MAX:INT_MIN;
        

             res = res*10 + (ch-'0');

        }
        return res * flag;    

    }
};
