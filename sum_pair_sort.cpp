//求逆序对总数
//逆序对: 前一个数字>后一个数字

//7  5  6  4

//解法: 归并排序

//    7564
//  75     64
// 7  5   6   4

//  57      46      count+=2
//  01      23
//  p1=1 mid=1 p2=3
//          7          count+=3-1
//        6 7          count+=0
//      5 6 7          count+=2-1
//    4 5 6 7          count+=0

void SumReversePair(int *v,int left , int right , int sum,int *tmp)
{
    //终止条件
    if(left<=right) return;
    
    //归并排序 --- 分
    int mid = (left+right)/2;
    SumReversePair(v,left,mid,sum,tmp);
    SumReversePair(v,mid+1,right,sum,tmp);
    
    //排序 --- 合
    //Merge(v,left,mid,right,sum);
    int p1 = mid;   
    int p2 = right;
    int p3 = right; //tmp下标
    
    //比较两数组,选择排序
    while(p1>=left && p2>=mid+1)
    {
        //左边大,插入空数组,计数迭代
        if(v[p1]>v[p2])
        {
            tmp[p3--] = v[p1--];
            
            sum += p2-mid;
        }
        //右边大/等于,插入空数组,迭代
        else
        {
            tmp[p3--] = v[p2--];
        }
    }
    
    //剩余排序
    while(p1>=left) tmp[p3--] = v[p1--];
    while(p2>=mid+1) tmp[p3--] = v[p2--];
    
    //拷贝到原数组
    while (left<=right){
	  	v[right] = tmp[right];
		  right--;
	  }
}
