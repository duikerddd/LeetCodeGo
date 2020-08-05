//奇数位于前面,偶数位于后面,保持原有顺序

//解题思路: 插入排序
//解法: 找到奇数,前面的数(一定是偶数)后移,插入

void ReOrderArr(vector<int> arr)
{
    if(arr.empty()) return;
    
    int odd = 0;
    for(int i=0;i<arr.size();++i)
    {
        //找到奇数,后移插入
        if(arr[i]%2==1)
        {
             int tmp = arr[i];
             int j = odd;
             while(j<i)
             {
                arr[j+1] = arr[j];
                j++;
             }
             arr[odd++] = tmp;
        }
    }
}
