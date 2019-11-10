class Solution {
public:
    //字符串转数字
    //无效输入: 没有数字
    //错误输入: 数字不合法(有字母)
    //推导: 首位判断正负,剩下的位之间测试
    int StrToInt(string str) {
        
       //记录数字个数
		int value_count = 0;
        //返回值
		long val = 0;

		for (int i=0; i<str.size(); ++i)
		{
            //是数字
			if (str[i] >= '0' && str[i] <= '9')
			{
				val = str[i]-'0' +val * 10;
				++value_count;
				continue;
			}
            //是空格或者正负号
			if (str[i] == ' ' || str[0] == '+' || str[0] == '-')
			{
				continue;
			}
            //其他字符直接当做非法输入
			return 0;
		}
        //没有数字情况
		if (value_count == 0)
		{
			return 0;
		}
        //正负数情况
		if (str[0]=='-')
		{
			val = 0 - val;
		}
		
		return val;
    }
};
