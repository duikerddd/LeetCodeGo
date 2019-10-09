class Solution {
public:
    bool isPalindrome(string s) {
        auto front = s.begin();
        auto behind = s.begin() + s.size();
        while(front<=behind)
        {
            //排除字母和数字
            if(*front<'0' || *front>'9'&&*front<'A' || *front>'Z'&&*front<'a' || *front>'z')
            {
                ++front;
                continue;
            }
            if(*behind<'0' || *behind>'9'&&*behind<'A' || *behind>'Z'&&*behind<'a' || *behind>'z')
            {
                --behind;
                continue;
            }
            //比较是否相等  ||    大小写相等&&排除不是数字
            if(*front == *behind || *front+'a'-'A'==*behind&&*front>='A' || *front==*behind+'a'-'A'&&*behind>='A')
            {
                ++front;
                --behind;
                continue;
            }
            return false;
        }
        return true;
    }
};
