class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //数组下标
        int len = m+n-1;
        int len1 = m-1;
        int len2 = n-1;
        //比较插入
        while(len1>=0 && len2>=0)
        {
            if(nums1[len1]<=nums2[len2])
            {
                nums1[len--]=nums2[len2--];       
            }
            else
            {
                nums1[len--]=nums1[len1--];
            }
        }
        //剩余插入
        while(len1>=0)
        {
            nums1[len--]=nums1[len1--];
        }
        while(len2>=0)
        {
            nums1[len--]=nums2[len2--];
        }
    }
};
