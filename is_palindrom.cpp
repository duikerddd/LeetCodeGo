class Solution {
public:
    bool isPalindrome(int x) {
        //负数肯定不是回文,0结尾并且不是0的数也不是回文
        if(x<0)
        {
            return false;
        }
        if(x%10==0 && x!=0)
        {
            return false;
        }
      
        //rev存储反转的数,当x<rev时就可以不比较了,因为超过了中间
        int rev=0;
        while(x!=0)
        {
            //反转数计算
            rev =rev*10 + x%10;
            //比较奇数位   ||    比较偶数位,因为x后面才/10,所以肯定>=rev   
            if(x == rev || x/10 == rev)
            {
                return true;
            }
            //x<rev就没机会再相等了
            x=x/10;
            if(x < rev)
            {
                return false;
            }
        }
        return true;
    }
};
