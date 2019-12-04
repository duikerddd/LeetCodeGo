void Reorder(vector<int> arr)
{
    //无效输入
    if(arr.empty()||arr.size()==0)
        return;
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    while(start<end)
    {
        //p1向后,遇到偶数
        while(start<end && start&1==1)
            p1++;
        //p2向前,遇到奇数
        while(start<end && end&1==0)
            p2--;
        //交换两数
        if(start<end)
        {
            int tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
        }
    }
}
