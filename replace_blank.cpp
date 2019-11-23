void ReplaceBlank(string& str)
{
    //无效输入
    if(str.empty() || str.size()==0)  return;
    
    //计算新长度
    int n = str.size();
    int countBlank = 0;
    for(int i=0;i<n;++i)
    {
        if(str[i] == ' ')
            ++countBlank;
    }
    int newLength = countBlank*2 + n;
    
    //前后指针替换
    str.resize(newLength+1);
    int front = n;   //'\0'位置
    int behind = newLength;  //'最后的位置肯定'\0''
    while(countBlank>0)
    {
        //不是空格,直接覆盖
        if(str[front]!=' ')
        {
            str[behind--] = str[front--];
        }
        //是空格,特殊处理
        else
        {
            //向前一位
            --front;
            //后指针先替换%20, 向前一位继续齐头并进
            str[behind--] = '0';
            str[behind--] = '2';
            str[behind--] = '%';
            //用来计数消灭的空格数
            --countBlank;
        }
    }
    
}
