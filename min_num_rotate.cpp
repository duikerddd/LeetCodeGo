//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//思路: 该数组规律:有序  left>=right  寻找的元素: mid<left && mid<right 
//解法: 1.使用二分查找的方法,一次排除一半 2.mid>=left 排除左边 ---> left=mid; mid<left 排除右边 ---> right=mid; 3.当left,right相邻,则找到
//特殊情况: 非递减---> 2221222  --> 如果left=right=mid , 有重复的导致无法使用二分排除左右了,就只能使用线性探测

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty()) return 0;
    
    int left = 0;
    int right = rotateArray.size()-1;
    int mid = 0;
    
    while(rotateArray[left] >= rotateArray[right])
    {
          if(right-left==1)
          {
                mid = right;break;
          }
          
          mid = (left+right)>>1;
          //特殊情况: 使用线性探测
          if(rotateArray[left]==rotateArray[right]==rotateArray[mid]) 
          {
              int min = rotateArray[left];
              for(int i=left+1;i<right;++i)
              {
                  if(rotateArray[i] < min)
                  {
                      min = rotateArray[i]
                  }
              }
              return min;
          }
          
          if(rotateArray[left] >= rotateArray[mid]) 
                      right = mid;
          else
                      left = mid;
                      
    }
    
    return rotateArray[mid];
}
