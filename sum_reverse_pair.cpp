
void SumReversePair(int *v,int left , int right , int sum,int *tmp)
{
	//终止条件
	if (left >= right)
	{
		return;
	}

	//分
	int mid = (left + right) / 2;
	SumReversePair(v,left,mid,sum,tmp);
	SumReversePair(v,mid+1,right,sum,tmp);
	
	//合
	//Merge(v,left,mid,right,sum);
	int p1 = mid;     //数组一尾部下标
	int p2 = right;   //数组二尾部下标
	int p3 = right;   //tmp排序尾部下标
	//两数组比较(二者下标都有数字)
	while (p1 >= left && p2 >= mid + 1)
	{
		//将大数移入tmp尾部,tmp与大数下标--
		//
		if (v[p1] > v[p2])
		{
			tmp[p3--] = v[p1--];
			//  5 7     4 6
			//  0 1     2 3
			//    mid     right
			//     p1      p2    p2 - mid = 2
			//  p1 mid   p2      p2 - mid = 1
			// p2 - mid :  右边数组还有多少个比左边当前数小的
			sum = sum + p2 - mid;
		}
		else 
		{ 
			tmp[p3--] = v[p2--];
		}
	}
	//剩余插入
	while (p1 >= left)
		tmp[p3--] = v[p1--];
	while (p2 >= mid+1)
		tmp[p3--] = v[p2--];
		
	//拷贝到原数组
 	while (left<=right)
	{
		v[right] = tmp[right];
		right--;
	}

}

