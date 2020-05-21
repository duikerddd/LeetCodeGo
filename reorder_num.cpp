//调整数组顺序,奇数放在偶数前面

//双指针: p1走到偶数. p2走到奇数, 交换
// 1 2 3 4 5
// p1      p2
// 1 2 3 4 5
//   p1    p2
// 1 5 3 4 2
//   p1    p2
// 1 5 3 4 2
//   p1p2
// 1 3 5 4 2
//     p1
//     p2

void ReOrder(vector<int> arr)
{
    if(arr.empty() || arr.size()==1) return;
    
    int size = arr.size();
    int p1 = 0,p2 = size-1;
    while(p1<p2)
    {
        //p1走到偶数
        while(p1<p2 && arr[p1]%2!=0) p1++;
        
        //p2走到奇数
        while(p1<p2 && arr[p1]%2==0) p2++;
        
        //交换两数
        if(p1<p2)
        {
            int tmp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = tmp;
        }
    }
}
