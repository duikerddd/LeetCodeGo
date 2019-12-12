//数组特点计 ---> 循环,遇见相同time++,不同time--(抵消),如果time==0,替换成下一个数
int MoreTimesNum(vector<int>& arr)
{
    if(arr.size()==0)
        return 0;
    int time = 1;
    int ret = arr[0];
    for(int i=0;i<arr.size();++i)
    {
        if(time == 0)
        {
            ret = arr[i];
        }
        else if(ret==arr[i])
        {
            time++;
        }
        else
        {
            time--;
        }
    }        
    
    return ret;
}
