//数组中出现次数好过一半的数字
//如input" arr =  {1,2,3,2,2,2,5,4,2}  output: 2

//思路: 其实排序后,就可知,中位数就是所求
//算法: 快排寻找中位数的基准值,基准值刚好排到n/2处即为所求
//数据结构:原生变量

int MoreTimesNum(vector<int>& arr)
{
    if(arr.size()==0) return 0;
    
    //快排
    //1.找一个基准值进行partion,分成三部分
    int left = 0;
    int right = arr.size()-1;
    int index = Partion(arr,left,right);
    
    //2.对该基准值左右两部分重复步骤1,直到 排序完成(×) 基准值下标为n/2(√)
    while(index != n/2)
    {
        //小了去右找
        if(index < arr.size()/2)
        {
             index =  Partion(arr,index+1,right);
        }
        //大了去左找
        else
        {
            index = Partion(arr,left,index-1);
        }
    }
    
    return arr[index];
}

//         2 3 2 5 1
//        [] 3 2 5 1
//         [1] 3 2 5 []
//         [1] [] 2 5 [3]
//         [1] [2] 2 5 [3]

//挖坑法
int Partion(vector<int>& arr,int left,int right)
{
    //以第一个值为基准值
    int tmp = arr[left];
    
    //找到合适的位置,将数据一分为三
    //双指针: 右边小数向左填,左边大数向右填,留空给tmp
    while(left<right)
    {
        //找到小数
        while(left<right && arr[right]>=tmp) --right;
        //右边小数向左填
        arr[left] = arr[right];
        
        //找到大数
        while(left<right && arr[left]<=tmp) ++left;
        //左边大数向右填
        arr[right] = arr[left];   
    }
    
    //基准值填坑
    arr[left] = tmp;
    
    return tmp;
}
