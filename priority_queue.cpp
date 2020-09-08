//每日练习
//向下调整
//小顶堆 --> 降序
void AdjustDown(vector<int>& num,int root,int n)
{
      int parent = root;
      int child = 2*root+1;
      
      while(child<n)
      { 
          //选最小的孩子
          if(child+1<n && num[child]>num[child+1]){
              child++;
          }
          //满足向下,则交换,更新调整的节点和孩子
          if(num[parent]>num[child])
          {
              swap(num[parent],num[child]);
              parent=child;
              child = 2*parent+1;
          }
          //不满足,则排序完成
          else
             break;
      }
}

//堆排序
//left = 2*root+1 right = 2*root+2
//root = (child-1)/2
vector<int>& HeapSort(vector<int> num,int n,vector<int>& tmp)
{
     if(num.empty()) return num;
     //建堆(从最后一个叶子节点开始)
     for(int i = (n-1)/2 ;i>=0;--i)
        AdjustDown(num,i,n);
        
     //排序(交换首尾,固定尾巴,向下调整)
     for(int i=n-1;i>0;--i)
     {
        swap(num[0],num[i]);
        AdjustDown(num,0,i);
     }
     
     return tmp;
}
