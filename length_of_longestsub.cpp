//滑动窗口法 --- 前后指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        
        //字符串长度为0、1时直接返回数字，双指针没有地方指。
        if(!len)
            return 0;
        if(len==1)
            return 1;
        
        //头指针p，最大长度mlen至少为1。
        int p=0,mlen=1;
        //尾指针end
        //尾指针比较头指针之后是否有重复,重复则更新头,更新长度
        for(int end=1;end<len;end++){
            for(int aim=p;aim<end;aim++){
                //重复,更新长度
                if(s[aim]==s[end]){
                    //更新头指针p
                    p=aim+1;
                    //更新最大长度mlen
                    if(mlen<(end-aim))
                        mlen=end-aim;
                    break;
                }
            }
            //没有过重复,记录长度
            if(mlen<end-p+1)
                mlen=end-p+1;
        }
        return mlen;
    }
};
