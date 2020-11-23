#include<algorithm>
class Solution {
public:
   
    //滑动窗口 
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max = 0;
        map<char,int> count;

        for(int i=0;i<s.size();i++)
        {
            //无重复,记录字母+索引
            if(count.find(s[i])==count.end())
            { 
                count[s[i]] = i;
            }
            //有重复,窗口左边收缩至重复字母后一位(如果前面有重复的,不需要将left回退到left之前,因为在left之前已经有重复的了)
            else
            {
                if(left<count[s[i]]+1)
                    left=count[s[i]]+1;
                count[s[i]] = i;
            }
            max = max>(i-left+1)?max:(i-left+1);
        }

        return max;
    }
};
