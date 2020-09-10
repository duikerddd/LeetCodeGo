//归并排序复习

//治
void Merge(vector<int>& num,int left,int mid,int right,vector<int>& tmp)
{
      int begin1 = left,end1 = mid;
      int begin2 = mid+1,end2 = right;
      int index = left;
      
      //比较插入
      while(begin1<=end1 && begin2<=end2)
      {
           if(num[begin1]<=num[begin2])
                tmp[index++]=num[begin1++];
           else
                tmp[index++]=num[begin2++];
      }
      //剩余插入
      while(begin1<=end1) tmp[index++]=num[begin1++];
      while(begin2<=end2) tmp[index++]=num[begin2++];
    
    //搬运回原数组
      for(int i=left;i<=right;++i)
      {
          num[i] = tmp[i];
      }
}

//分
vector<int> tmp;
void MergerSort(vector<int> num,int left,int right)
{
      if(left>=right) return;
      
      int mid = (left+right)>>1;
      MergeSort(num,left,mid);
      MergeSort(nun,mid+1,right);
      Merge(num,left,mid,right);
}
