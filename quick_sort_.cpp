//快排复习
//挖坑法
//选出一个分界值,划分三部分.
int Partion(vector<int>& arr,int left,int right)
{
      //将第一个值作为分界值
      int tmp = arr[left];
      while(left<right)
      {
            //右边找小填坑
            while(left<right && arr[right]>=tmp)
                  right--;
            arr[left] = arr[right];      
                  
            //左边找大填坑      
            while(left<right && arr[left]<=tmp)
                  left++;
            arr[right] = arr[left];
      }
      //填坑
      arr[left] = tmp;
      
      return tmp;
}

//
void QuickSort(vector<int>& arr,int left,int right)
{
      if(left>=right) return;
      
      //选出一个分界值,划分三部分. 对未排序继续重复操作
      int mid = Partion(arr,left,right);
      
      QuickSort(arr,left,mid-1);
      QuickSort(arr,mid+1,right);
    
}
