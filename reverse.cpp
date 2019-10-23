
class Solution {
public:
    //此题难点是如果防止溢出,因为int占4字节32位，根据二进制编码的规则，INT_MAX = 2^31-1，INT_MIN= -2^31 2^31-1=2147483647,-2^31=-2147483648
    int reverse(int x) {
         int temp=0;
        while(x!=0){
            //pop记录当前反转的数
            int pop=x%10;
            x/=10;
             //反转数是按*10增长的
             //1.反转数/10(溢出前最大值)>最大数/10  
             //2.反转数(溢出最大值) == 最大数/10 并且 当前反转数>7(因为最大数最后一位为7)  
             if(temp>INT_MAX/10 || temp==INT_MAX/10&&pop>7)
                return 0;
             //同理上面
             if(temp<INT_MIN/10 || temp==INT_MIN/10&&pop<-8)
                return 0;
           
            temp=temp*10+pop;           
        }

        return temp;
    }
};
