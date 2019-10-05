//合并有序,从后往前更容易
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1;
        int n2 = n-1;
        int cur = m+n-1;
        //1.数组比较直到其中一个数组元素都赋值完
        while(n1>=0 && n2>=0)
        {
            if(nums1[n1] > nums2[n2])
            {
                nums1[cur] = nums1[n1];
                --n1;
            }
            else
            {
                nums1[cur] = nums2[n2];
                --n2;
            }
            --cur;
        }
        //2.将剩余元素依次赋值,因为n1有序,所以不用赋值自己
        if(n1<0)
        {
            while(cur>=0)
            {
                nums1[cur--] = nums2[n2--];
            }
        }
        
    }
        
};
